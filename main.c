/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soamraou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:27:40 by soamraou          #+#    #+#             */
/*   Updated: 2026/02/04 14:24:46 by soamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	parse_error(int ac, char **av, int *list)
{
	if (ac == 1)
	{
		free(list);
		return (0);
	}
	if (!are_numbers(ac, av))
	{
		free(list);
		write (2, "Error\n", 6);
		return (0);
	}
	if (list == NULL || is_duplic(list, count_nums(av)))
	{
		free(list);
		write (2, "Error\n", 6);
		return (0);
	}
	return (1);
}

static int initial_checks(char **av, int *list)
{
	int num_count;

	num_count = count_nums(av);
	if (in_order(list, num_count))
	{
		free(list);
		return (0);
	}
	return (1);
}

int main(int argc, char **argv)
{
	int	*list;

	list = list_int(argv);
	if (parse_error(argc, argv, list) == 0)
		return (0);
	if (count_nums(argv) == 1 || initial_checks(argv, list) == 0)
		return (0);
	return (1);
}
