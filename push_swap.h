/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soamraou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:27:13 by soamraou          #+#    #+#             */
/*   Updated: 2026/02/07 14:48:45 by soamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

typedef struct s_node
{
    int             value;
    int		index;
    struct s_node   *next;
}   t_node;

int     ft_isdigit(int c);
char    **ft_split(char const *s, char c);
long     ft_atoi(const char *s);
int     *list_int(char **av);
int count_nums(char **av);
int is_duplic(int *list, int size);
int are_numbers(int ac, char **av);
int in_order(int *list, int size);
//operations:
void sa(t_node **stack_a);
void sb(t_node **stack_b);
void ss(t_node **stack_a, t_node **stack_b);
void pa(t_node **stack_a, t_node **stack_b);
void pb(t_node **stack_a, t_node **stack_b);
void ra(t_node **stack_a);
void rb(t_node **stack_b);
void rr(t_node **stack_a, t_node **stack_b);
void rra(t_node **stack_a);
void rrb(t_node **stack_b);
void rrr(t_node **stack_a, t_node **stack_b);

t_node *build_stack_a(int *list, int size);
void chunk_sort(t_node **a, t_node **b);

#endif
