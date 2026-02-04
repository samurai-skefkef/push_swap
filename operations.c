/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soamraou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 14:29:45 by soamraou          #+#    #+#             */
/*   Updated: 2026/02/04 19:17:05 by soamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_node **stack_a)
{
	t_node *node_1;
	t_node *node_2;

	node_1 = *stack_a;
	node_2 = (*stack_a)->next;
	node_1->next = node_2->next;
	node_2->next = node_1;
	*stack_a = node_2;
	write(1, "sa\0", 3);
}

void sb(t_node **stack_b)
{
        t_node *node_1;
        t_node *node_2;

        node_1 = *stack_b;
        node_2 = (*stack_b)->next;
        node_1->next = node_2->next;
        node_2->next = node_1;
        *stack_b = node_2;
        write(1, "sb\0", 3);
}

void ss(t_node **stack_a, t_node **stack_b)
{
        t_node *node_1;
        t_node *node_2;

	//stack a change
        node_1 = *stack_a;
        node_2 = (*stack_a)->next;
        node_1->next = node_2->next;
        node_2->next = node_1;
        *stack_a = node_2;
	//stack b change
        node_1 = *stack_b;
        node_2 = (*stack_b)->next;
        node_1->next = node_2->next;
        node_2->next = node_1;
        *stack_b = node_2;
        write(1, "ss\0", 3);
}

void pa(t_node **stack_a, t_node **stack_b)
{
	t_node *node_b;

	node_b = *stack_b;
	if (*stack_b)
	{
		*stack_b = node_b->next;
		node_b->next = *stack_a;
		*stack_a = node_b;
		write(1, "pa\n", 3);

	}
}

void pb(t_node **stack_a, t_node **stack_b)
{
        t_node *node_a;

        node_a = *stack_a;
        if (*stack_a)
        {
                *stack_a = node_a->next;
                node_a->next = *stack_b;
                *stack_b = node_a;
                write(1, "pb\n", 3);
        }
}

void ra(t_node **stack_a)
{
	t_node *tmp;
	t_node *first_node;

	tmp = *stack_a;
	first_node = *stack_a;
	while(tmp->next)
		tmp = tmp->next;
	*stack_a = first_node->next;
	first_node->next = tmp->next;//Which is NULL, the tmp here is the last node
	tmp->next = first_node;
	write(1, "ra\n", 3);
}

void rb(t_node **stack_b)
{
        t_node *tmp;
        t_node *first_node;

        tmp = *stack_b;
        first_node = *stack_b;
        while(tmp->next)
                tmp = tmp->next;
        *stack_b = first_node->next;
        first_node->next = tmp->next;//Which is NULL, the tmp here is the last node
        tmp->next = first_node;
	write (1, "rb\n", 3);
}

void rr(t_node **stack_a, t_node **stack_b)
{
	t_node *tmp;
        t_node *first_node;

	//stack a:
        tmp = *stack_a;
        first_node = *stack_a;
        while(tmp->next)
                tmp = tmp->next;
        *stack_a = first_node->next;
        first_node->next = tmp->next;
        tmp->next = first_node;
	//stack b:
        tmp = *stack_b;
        first_node = *stack_b;
        while(tmp->next)
                tmp = tmp->next;
        *stack_b = first_node->next;
        first_node->next = tmp->next;
        tmp->next = first_node;
	write (1, "rr\n", 3);
}

void rra(t_node **stack_a)
{
	t_node *tmp;
	t_node *before_tmp;

	tmp = *stack_a;
	while (tmp->next)
	{
		before_tmp = tmp;
		tmp = tmp->next;
	}
	tmp->next = *stack_a;
	*stack_a = tmp;
	before_tmp->next = NULL;
	write(1, "rra\n", 4);
}

void rrb(t_node **stack_b)
{
        t_node *tmp;
        t_node *before_tmp;

        tmp = *stack_b;
        while (tmp->next)
        {
                before_tmp = tmp;
                tmp = tmp->next;
        }
        tmp->next = *stack_b;
        *stack_b = tmp;
        before_tmp->next = NULL;
        write(1, "rrb\n", 4);
}

void rrr(t_node **stack_a, t_node **stack_b)
{
        t_node *tmp;
        t_node *before_tmp;

	//stack a
        tmp = *stack_a;
        while (tmp->next)
        {
                before_tmp = tmp;
                tmp = tmp->next;
        }
        tmp->next = *stack_a;
        *stack_a = tmp;
        before_tmp->next = NULL;
        //stack b:
	tmp = *stack_b;
        while (tmp->next)
        {
                before_tmp = tmp;
                tmp = tmp->next;
        }
        tmp->next = *stack_b;
        *stack_b = tmp;
        before_tmp->next = NULL;
        write(1, "rrr\n", 4);
}
