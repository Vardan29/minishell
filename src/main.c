
#include "minishell.h"

int	main(int argc, char **argv, char **envir)
{
	t_env	*env;
	char	*inpt;
	int		i;

	env = env_init(argc, argv, envir);
	i = -1;
	while (1)
	{
		inpt = readline("minishell> ");
		add_history(inpt);
	}
	clear_history();
	free_env(env);
	return (0);
}
