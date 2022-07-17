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

# include "linkedlist.h"
# include "minishell_macros.h"
# include "minishell_structs.h"
# include "utils.h"

//global variable
t_data *g_data;


//environment.c
void		free_data(void);
t_cmd		get_command(char *commandstr, t_data *data);
void		fill_data(t_data *data, int argc, char **argv);
t_data		*data_init(int argc, char **argv, char **envv);
char		*get_command_path(char *command, char **env_path);

//ft_split.c
char		**ft_split(char const *s, char c);

//checkings.c
void		check_input(t_data *data, char **argv, int argc);

//pipex.c
void		command_child(t_data *data, int index);

//printer.c
void		print_error(char *project_name, char *text);
void		print_str(char *str);

//builtins.c
int			echo(char *str, char with_option);
int			env(void);
int			cd(char *path);

//init.c
t_list		*init_env_list(char **envir);

#endif
