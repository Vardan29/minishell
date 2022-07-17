/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeghiaz <syeghiaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:30:04 by syeghiaz          #+#    #+#             */
/*   Updated: 2022/07/16 20:25:48 by syeghiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_data	*data_init(int argc, char **argv, char **env)
{
	(void)argc;
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		exit(1);
	data->env_list = init_env_list(env);
	data->path = get_data_path(env);
	data->project_name = argv[0];
	return (data);
}

void	fill_data(t_data *data, int argc, char **argv)
{
	int	i;

	data->infile = open(argv[1], O_RDONLY);
	data->outfile = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0777);
	data->cmds_count = argc - 3;
	data->fds = malloc(sizeof(int *) * (data->cmds_count + 1));
	i = -1;
	while (++i < argc - data->cmds_count + 1)
		data->fds[i] = (int *)malloc(sizeof(int) * 2);
	data->cmds = malloc(sizeof(t_cmd) * data->cmds_count);
	i = -1;
	while (++i < data->cmds_count)
		data->cmds[i] = get_command(argv[2 + i], data);
	check_input(data, argv, argc);
}

void	free_data(void)
{
	int	i;
	int	j;

	i = -1;
	while (g_data->path[++i])
		free(g_data->path[i]);
	free(g_data->path);
	i = -1;
	while (++i < g_data->cmds_count)
	{
		free(g_data->cmds[i].command);
		j = -1;
		while (g_data->cmds[i].params[++j])
			free(g_data->cmds[i].params[j]);
		free(g_data->cmds[i].params);
	}
	free(g_data->cmds);
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

t_cmd	get_command(char *commandstr, t_data *data)
{
	t_cmd	command;
	char	**splited_text;

	splited_text = ft_split(commandstr, ' ');
	command.command = get_command_path(splited_text[0], data->path);
	command.params = splited_text;
	return (command);
}
