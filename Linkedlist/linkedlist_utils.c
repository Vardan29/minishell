#include "minishell.h"

t_node	*find_node_with_key(t_list *list, char *key)
{
	t_node	*node;

	if (list->count <= 0)
		return (NULL);
	node = list->head;
	while (node)
	{
		if (!ft_strcmp(key, node->key))
			return (node);
		node = node->next;
	}
	return (NULL);
}

void	for_each(t_list *list, void (*func)(t_node *))
{
	int		i;
	t_node	*current;

	i = -1;
	current = list->head;
	while (++i < list->count)
	{
		func(current);
		current = current->next;
	}
}

static void	remove_last(t_list *list)
{
	t_node	*last;

	if (list->count == 0)
		return ;
	last = list->tail;
	if (list->count == 1)
	{
		list->tail = NULL;
		list->head = NULL;
	}
	else
		list->tail = last->prev;
	free(last);
	list->count--;
}

void	free_list(t_list *list)
{
	while (list->count > 0)
		remove_last(list);
	free(list);
}

void	unset_index(t_node *node)
{
	node->index = -1;
}
