
#include "minishell.h"

int	main(int argc, char **argv, char **envv)
{
	char			*inpt;
	int				i;
	int				is_not_executing;
	extern t_data	*d_data;

	is_not_executing = 1;
	g_data = data_init(argc, argv, envv);
	i = -1;
	export_print(g_data->env_list);
	while (is_not_executing)
	{
		is_not_executing = 0;
		inpt = readline("minishell> ");
		cd(inpt);
		add_history(inpt);
		is_not_executing = 1;
	}
	clear_history();
	free_data();
	return (0);
}
