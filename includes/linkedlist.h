/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeghiaz <syeghiaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 14:02:57 by syeghiaz          #+#    #+#             */
/*   Updated: 2022/07/17 19:02:48 by syeghiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKEDLIST_H
# define LINKEDLIST_H

typedef struct s_node	t_node;

struct s_node
{
	char	*key;
	char	*value;
	t_node	*next;
	t_node	*prev;
	int		index;
};

typedef struct s_list
{
	t_node	*head;
	t_node	*tail;
	int		count;
}	t_list;


//linkedlist.c
t_list	*new_list(void);
t_node	*new_node(char *key, char *value);
void	add(t_list *list, t_node *node);
void	remove_with_key(t_list *list, char *key);
void	update_with_key(t_list *list, char *key, char *new_value);

//linkedlist_utils.c
t_node	*find_node_with_key(t_list *list, char *key);
void	for_each(t_list *list, void (*func)(t_node *));
void	free_list(t_list *list);
void	unset_index(t_node *node);

//linkedlist_printer.c
void	print_list(t_list *list);
void	print_export_node(t_node *node);
void	print_env_node(t_node *node);
void	export_print(t_list *list);

#endif