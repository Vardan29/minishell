#include "minishell.h"

static int	check_files(t_data *data, char **argv, int argc)
{
	int	has_error;

	has_error = 0;
	if (data->infile < 0)
	{
		has_error = 1;
		print_error(data->project_name + 2, argv[1]);
	}
	if (data->outfile < 0)
	{
		has_error = 1;
		print_error(data->project_name + 2, argv[argc - 1]);
	}
	return (has_error);
}

static int	check_commands(t_data *data, char **argv)
{
	int	i;
	int	has_error;

	has_error = 0;
	i = -1;
	while (++i < data->cmds_count)
	{
		if (data->cmds[i].command == NULL)
		{
			print_error(data->project_name + 2,
				argv[2 + i]);
			has_error = 1;
		}
	}
	return (has_error);
}

void	check_input(t_data *data, char **argv, int argc)
{
	int	has_file_errors;
	int	has_command_errors;

	has_file_errors = check_files(data, argv, argc);
	has_command_errors = check_commands(data, argv);
	if (has_file_errors || has_command_errors)
		return ;
	//exit (2);
}
