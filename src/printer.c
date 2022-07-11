#include "minishell.h"

void	print_char(char ch)
{
	write(1, &ch, 1);
}

void	print_str(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		print_char(str[i]);
}

void	print_error(char *project_name, char *text)
{
	print_str(project_name);
	print_str("> ");
	print_str(strerror(errno));
	print_str(": ");
	print_str(text);
	print_str("\n");
}
