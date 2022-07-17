/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeghiaz <syeghiaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:36:59 by syeghiaz          #+#    #+#             */
/*   Updated: 2022/07/16 20:07:50 by syeghiaz         ###   ########.fr       */
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

char	**get_data_path(char **env)
{
	int		i;
	char	**file_path;
	char	**withbackslash;

	i = -1;
	file_path = NULL;
	withbackslash = NULL;
	while (env[++i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
		{
			file_path = ft_split(env[i] + 5, ':');
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

void	change_cwd(char *new_pwd)
{
	t_node	*old_pwd;
	t_node	*pwd;

	old_pwd = find_node_with_key(g_data->env_list, "OLDPWD");
	pwd = find_node_with_key(g_data->env_list, "PWD");
	free(old_pwd->value);
	old_pwd->value = pwd->value;
	pwd->value = ft_strdup(new_pwd);
}
