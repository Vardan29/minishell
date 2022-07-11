/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeghiaz <syeghiaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:27:11 by syeghiaz          #+#    #+#             */
/*   Updated: 2022/07/08 16:49:49 by syeghiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	command_child(t_env *env, int index)
{
	if (dup2(env->fds[index - 1][0], STDIN_FILENO) == -1)
		exit (1);
	if (dup2(env->fds[index][1], STDOUT_FILENO) == -1)
		exit (1);
	close_fds(env->fds, env->cmds_count + 1);
	if (execve(env->cmds[index - 1].command,
			env->cmds[index - 1].params, env->envir) == -1)
		exit(1);
}

int	pipex_main(int argc, char **argv, char **envir)
{
	t_env	*env;
	int		i;
	int		pid;

	i = -1;
	if (argc < 5)
		return (1);
	env = env_init(argc, argv, envir);
	while (++i < env->cmds_count + 1)
		pipe(env->fds[i]);
	dup2(env->infile, env->fds[0][0]);
	dup2(env->outfile, env->fds[env->cmds_count][1]);
	i = 0;
	while (++i <= env->cmds_count)
	{
		pid = fork();
		if (pid == 0)
			command_child(env, i);
	}
	close_fds(env->fds, env->cmds_count + 1);
	while (wait(NULL) != -1 || errno != ECHILD)
		;
	free_env(env);
	return (0);
}
