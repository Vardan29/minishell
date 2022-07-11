#include "minishell.h"

static int	check_files(t_env *env, char **argv, int argc)
{
	int	has_error;

	has_error = 0;
	if (env->infile < 0)
	{
		has_error = 1;
		print_error(env->project_name + 2, argv[1]);
	}
	if (env->outfile < 0)
	{
		has_error = 1;
		print_error(env->project_name + 2, argv[argc - 1]);
	}
	return (has_error);
}

static int	check_commands(t_env *env, char **argv)
{
	int	i;
	int	has_error;

	has_error = 0;
	i = -1;
	while (++i < env->cmds_count)
	{
		if (env->cmds[i].command == NULL)
		{
			print_error(env->project_name + 2,
				argv[2 + i]);
			has_error = 1;
		}
	}
	return (has_error);
}

void	check_input(t_env *env, char **argv, int argc)
{
	int	has_file_errors;
	int	has_command_errors;

	has_file_errors = check_files(env, argv, argc);
	has_command_errors = check_commands(env, argv);
	if (has_file_errors || has_command_errors)
		return ;
	//exit (2);
}
