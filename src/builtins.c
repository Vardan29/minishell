#include "minishell.h"

int	cd(char *path)
{
	char	ch[256];

	if (!chdir(path))
	{
		change_cwd(getcwd(ch, sizeof(ch)));
		return (0);
	}
	return (errno);
}

int	env(void)
{
	for_each(g_data->env_list, print_env_node);
	return (0);
}

void	export_node(char *key, char *value, char has_eqaul)
{
	t_node	*node;

	node = find_node_with_key(g_data->env_list, key);
	if (node && has_eqaul)
		update_with_key(g_data->env_list, key, value);
	else if (!node)
	{
		if (has_eqaul)
			node = new_node(key, value);
		else
			node = new_node(key, NULL);
		add(g_data->env_list, node);
	}
	print_export_node(node);
}

void	for_each_export(char *argument)
{
	int		i;
	char	has_equal;

	i = -1;
	has_equal = 0;
	while (argument[++i] && argument[i] != '=')
		;
	if (argument[i] == '=')
	{
		argument[i++] = 0;
		has_equal = 1;
	}
	export_node(argument, argument + i, has_equal);
}

int	is_valid_env_var(char *str)
{
	int	i;

	i = -1;
	while (str[++i] && str[i] != '=')
		;
	if (str[i] == '=')
	{
		str[i++] = 0;
	}
	return (is_valid_export_key(str));
}

int	export(char **arguments)
{
	int	i;
	int	status;

	i = -1;
	status = 0;
	if (!arguments || !arguments[0])
	{
		export_print(g_data->env_list);
		return (0);
	}
	while (arguments[++i])
	{
		if (is_valid_env_var(arguments[i]))
			for_each_export(arguments[i]);
		else
			status = 1;
	}
	return (status);
}

int	unset(char **arguments)
{
	int		i;
	int		status;

	i = -1;
	status = 0;
	if (!arguments || !arguments[0])
		return (status);
	while ( arguments[++i])
	{
		if (is_valid_export_key(arguments[i]))
			remove_with_key(g_data->env_list, arguments[i]);
		else
			status = 1;
	}
	return (status);
}

int	echo(char *str, char with_option)
{
	print_str(str);
	if (!with_option )
	{
		print_str("\n");
	}
	return (0);
}
