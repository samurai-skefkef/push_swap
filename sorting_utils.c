/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soamraou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 12:13:20 by soamraou          #+#    #+#             */
/*   Updated: 2026/02/07 19:23:16 by soamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int stack_size(t_node *stack)
{
    int i = 0;

    while (stack)
    {
        i++;
        stack = stack->next;
    }
    return i;
}

static int distance_to_index(t_node *stack, int index)
{
    int i = 0;

    while (stack)
    {
        if (stack->index == index)
            return i;
        i++;
        stack = stack->next;
    }
    return -1;
}

static int find_max_index(t_node *stack)
{
    if (!stack)
        return -1; // safety check

    int max = stack->index;
    while (stack)
    {
        if (stack->index > max)
            max = stack->index;
        stack = stack->next;
    }
    return max;
}


static void push_chunks(t_node **a, t_node **b, int chunk)
{
	int limit;
	int dist;
	int size;
	int pushed;
	int index;

	limit = chunk;
	pushed = 0;
	while (*a)
	{
		size = stack_size(*a);
		if ((*a)->index < limit)
		{
			index = (*a)->index;
			dist = distance_to_index(*a, index);
			if (dist <= size / 2)
			{
				while ((*a)->index != index)
					ra(a);
			}
			else
			{
				while ((*a)->index != index)
					rra(a);
			}
			pb(a, b);
			pushed++;
		}
		if (pushed == limit)
			limit += chunk;
	}

}

static void push_back_to_a(t_node **a, t_node **b)
{
	while (*b)
	{
		int max = find_max_index(*b);
		int dist = distance_to_index(*b, max);
		int size = stack_size(*b);

		if (dist <= size / 2)
		{
			while ((*b)->index != max)
				rb(b);
		}
		else
		{
			while ((*b)->index != max)
				rrb(b);
		}
		pa(a, b);
	}
}

void chunk_sort(t_node **a, t_node **b)
{
    int size = stack_size(*a);
    int chunk_size;

    if (size <= 100)
        chunk_size = 20;
    else
        chunk_size = 45;

    push_chunks(a, b, chunk_size);
    push_back_to_a(a, b);
}

