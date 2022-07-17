/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeghiaz <syeghiaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 12:08:06 by syeghiaz          #+#    #+#             */
/*   Updated: 2022/07/12 22:23:59 by syeghiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size1;
	size_t	size2;
	size_t	i;
	char	*res;

	size1 = -1;
	size2 = -1;
	i = -1;
	while (s1[++size1])
		;
	while (s2[++size2])
		;
	res = malloc(sizeof(char) * (size1 + size2 + 1));
	if (!res)
		return (NULL);
	while (++i < size1)
		res[i] = s1[i];
	while (i - size1 < size2)
	{
		res[i] = s2[i - size1];
		i++;
	}
	res[i] = 0;
	return (res);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && s1[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static	int	compare_char(char ch1, char ch2)
{
	if (ch1 > ch2)
		return (1);
	if (ch1 < ch2)
		return (-1);
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{		
		if (!compare_char(s1[i], s2[i]))
			i++;
		else
			return (compare_char(s1[i], s2[i]));
	}
	return (compare_char(s1[i], s2[i]));
}

char	*ft_strdup(const char *s1)
{
	char	*result;
	size_t	len;
	size_t	i;

	i = -1;
	len = ft_strlen(s1);
	result = malloc(len + 1);
	while (s1[++i])
		result[i] = s1[i];
	result[i] = 0;
	return (result);
}
