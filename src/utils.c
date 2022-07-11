/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeghiaz <syeghiaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:36:59 by syeghiaz          #+#    #+#             */
/*   Updated: 2022/07/08 19:15:32 by syeghiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_array(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

void	close_fds(int **fds, int i_len)
{
	int	i;

	i = -1;
	while (++i < i_len)
	{
		close(fds[i][0]);
		close(fds[i][1]);
		free(fds[i]);
	}
	free(fds);
}

char	**get_env_path(char **envv)
{
	int		i;
	char	**file_path;
	char	**withbackslash;

	i = -1;
	file_path = NULL;
	withbackslash = NULL;
	while (envv[++i])
	{
		if (!ft_strncmp(envv[i], "PATH=", 5))
		{
			file_path = ft_split(envv[i] + 5, ':');
			i = -1;
			while (file_path[++i])
				;
			withbackslash = malloc(sizeof(char *) * (i + 1));
			i = -1;
			while (file_path[++i])
				withbackslash[i] = ft_strjoin(file_path[i], "/");
			withbackslash[i] = NULL;
			break ;
		}
	}
	free_array(file_path);
	return (withbackslash);
}

char	**copy_env_var(char **text)
{
	char	**copy;
	int		line_count;

	line_count = -1;
	if (!text)
		return (NULL);
	while (text[++line_count])
		;
	copy = malloc(sizeof(char *) * (line_count + 1));
	line_count = -1;
	while (text[++line_count])
		copy[line_count] = ft_strdup(text[line_count]);
	copy[line_count] = NULL;
	return (copy);
}
