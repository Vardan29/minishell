
#ifndef UTILS_H
# define UTILS_H

#include "minishell.h"

//utils.c
void		free_array(char **arr);
void		close_fds(int **fds, int i_len);
char		**get_data_path(char **envv);
char		**copy_env_var(char **text);
void		change_cwd(char *new_pwd);

//libft_utils.c
size_t		ft_strlen(const char *s);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strjoin(char const *s1, char const *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*str_dup(char *str);
char		*ft_strdup(const char *s1);

//str_utils.c
int			is_alpha(unsigned char ch);
int			is_valid_export_key(char *key);

#endif