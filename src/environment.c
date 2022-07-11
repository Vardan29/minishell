/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeghiaz <syeghiaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:30:04 by syeghiaz          #+#    #+#             */
/*   Updated: 2022/07/08 19:16:18 by syeghiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*env_init(int argc, char **argv, char **envv)
{
	t_env	*env;
	(void) argc;
	env = malloc(sizeof(t_env));
	if (!env)
		exit(1);
	env->envir = copy_env_var(envv);
	int i;
	i = -1;
	while(++i < 28)
	{
		printf("%s\n", env->envir[i]);
	}
	env->path = get_env_path(envv);
	env->project_name = argv[0];
	//fill_env(env, argc, argv);
	return (env);
}

void	fill_env(t_env *env, int argc, char **argv)
{
	int	i;

	env->infile = open(argv[1], O_RDONLY);
	env->outfile = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0777);
	env->cmds_count = argc - 3;
	env->fds = malloc(sizeof(int *) * (env->cmds_count + 1));
	i = -1;
	while (++i < argc - env->cmds_count + 1)
		env->fds[i] = (int *)malloc(sizeof(int) * 2);
	env->cmds = malloc(sizeof(t_cmd) * env->cmds_count);
	i = -1;
	while (++i < env->cmds_count)
		env->cmds[i] = get_command(argv[2 + i], env);
	check_input(env, argv, argc);
}

void	free_env(t_env *env)
{
	int	i;
	int	j;

	i = -1;
	while (env->path[++i])
		free(env->path[i]);
	free(env->path);
	i = -1;
	while (++i < env->cmds_count)
	{
		free(env->cmds[i].command);
		j = -1;
		while (env->cmds[i].params[++j])
			free(env->cmds[i].params[j]);
		free(env->cmds[i].params);
	}
	free(env->cmds);
	free(env);
}

char	*get_command_path(char *command, char **env_path)
{
	char	*file_path;
	char	*result;
	int		i;

	result = NULL;
	i = -1;
	while (env_path[++i])
	{
		file_path = ft_strjoin(env_path[i], command);
		if (access(file_path, X_OK) == 0)
		{
			result = file_path;
			break ;
		}
		free(file_path);
	}
	return (result);
}

t_cmd	get_command(char *commandstr, t_env *env)
{
	t_cmd	command;
	char	**splited_text;

	splited_text = ft_split(commandstr, ' ');
	command.command = get_command_path(splited_text[0], env->path);
	command.params = splited_text;
	return (command);
}
