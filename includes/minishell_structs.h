#ifndef MINISHELL_STRUCTS_H
# define MINISHELL_STRUCTS_H

typedef struct s_cmd
{
	char	*command;
	char	**params;
}			t_cmd;

typedef struct s_data
{
	int		infile;
	int		outfile;
	char	**path;
	char	**envir;
	t_cmd	*cmds;
	int		cmds_count;
	int		**fds;
	char	*project_name;
	t_list	*env_list;
}			t_data;

#endif