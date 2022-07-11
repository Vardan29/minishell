#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <signal.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "minishell_macros.h"
# include "minishell_structs.h"

//environment.c
void		free_env(t_env *env);
t_cmd		get_command(char *commandstr, t_env *env);
void		fill_env(t_env *env, int argc, char **argv);
t_env		*env_init(int argc, char **argv, char **envv);
char		*get_command_path(char *command, char **env_path);

//ft_split.c
char		**ft_split(char const *s, char c);

//checkings.c
void		check_input(t_env *env, char **argv, int argc);


//libft_utils.c
size_t		ft_strlen(const char *s);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strjoin(char const *s1, char const *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*str_dup(char *str);
char		*ft_strdup(const char *s1);

//utils.c
void		free_array(char **arr);
void		close_fds(int **fds, int i_len);
char		**get_env_path(char **envv);
char		**copy_env_var(char **text);

//pipex.c
void		command_child(t_env *env, int index);

//printer.c
void		print_error(char *project_name, char *text);

#endif