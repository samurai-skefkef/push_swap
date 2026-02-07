/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soamraou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 10:44:19 by soamraou          #+#    #+#             */
/*   Updated: 2026/02/07 14:49:42 by soamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*create_node(int number, int order)
{
	t_node *node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = number;
	node->index = order;
	node->next = NULL;
	return (node);
}

static void link_nodes(t_node **stack, t_node *new)
{
    t_node *tmp;

    if (!*stack)
    {
        *stack = new;
        return;
    }
    tmp = *stack;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
}

static void index_nodes(t_node **a)
{
	int i;
	int j;
	int tmp;
	t_node *node1;
	t_node *node2;

	i = 0;
	j = 0;
	node1 = *a;
	while (node1)
	{
		node2 = node1->next;
		while (node2)
		{
			if (node2->value < node1->value)
			{
				tmp = node2->index;
				node2->index = node1->index;
				node1->index = tmp;
			}
			node2 = node2->next;
		}
		node1 = node1->next;
	}
}

t_node *build_stack_a(int *list, int size)
{
    int i;
    t_node *a;

    i = 0;
    a = NULL; 
    while (i < size)
    {
	    link_nodes(&a, create_node(list[i], i));
	    i++;
    }
    index_nodes(&a);
    return (a);
}

