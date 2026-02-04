/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soamraou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 10:44:19 by soamraou          #+#    #+#             */
/*   Updated: 2026/02/04 11:31:14 by soamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*create_node(int number)
{
	t_node node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = number;
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

t_node *build_stack_a(int *list, int size)
{
    int i;
    t_node *a;

    i = 0;
    a = NULL;
    while (i < size)
    {
        link_nodes(&a, create_node(list[i]));
        i++;
    }
    return (a);
}

