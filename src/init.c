#include "minishell.h"

t_list	*init_env_list(char **envir)
{
	int		i;
	t_list	*list;
	t_node	*node;
	char	**splitted_text;

	list = new_list();
	i = -1;
	while (envir[++i])
	{
		splitted_text = ft_split(envir[i], '=');
		node = new_node(splitted_text[0], splitted_text[1]);
		add(list, node);
		free_array(splitted_text);
	}
	return (list);
}
