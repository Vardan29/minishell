/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeghiaz <syeghiaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:27:11 by syeghiaz          #+#    #+#             */
/*   Updated: 2022/07/16 18:37:43 by syeghiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	command_child(t_data *data, int index)
{
	if (dup2(data->fds[index - 1][0], STDIN_FILENO) == -1)
		exit (1);
	if (dup2(data->fds[index][1], STDOUT_FILENO) == -1)
		exit (1);
	close_fds(data->fds, data->cmds_count + 1);
	if (execve(data->cmds[index - 1].command,
			data->cmds[index - 1].params, data->envir) == -1)
		exit(1);
}

// int	pipex_main(int argc, char **argv, char **envir)
// {
// 	t_data	*data;
// 	int		i;
// 	int		pid;

// 	i = -1;
// 	if (argc < 5)
// 		return (1);
// 	data = data_init(argc, argv, envir);
// 	while (++i < data->cmds_count + 1)
// 		pipe(data->fds[i]);
// 	dup2(data->infile, data->fds[0][0]);
// 	dup2(data->outfile, data->fds[data->cmds_count][1]);
// 	i = 0;
// 	while (++i <= data->cmds_count)
// 	{
// 		pid = fork();
// 		if (pid == 0)
// 			command_child(data, i);
// 	}
// 	close_fds(data->fds, data->cmds_count + 1);
// 	while (wait(NULL) != -1 || errno != ECHILD)
// 		;
// 	free_data();
// 	return (0);
// }
