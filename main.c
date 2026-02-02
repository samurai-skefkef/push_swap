/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soamraou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:27:40 by soamraou          #+#    #+#             */
/*   Updated: 2026/02/02 19:52:28 by soamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	parse_error(int ac, char **av, int *list)
{
	if (ac == 1)
		return (0);
	if (!are_numbers(ac, av))
	{
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

int main(int argc, char **argv)
{
    /**if (argc == 1)
        return (0);
    if (!are_numbers(argc, argv))
        write (2, "Error\n", 6);**/
	int	*list;
	int	check;

	list = list_int(argv);
	check = parse_error(argc, argv, list);
	if (check == 0)
		return (0);
	//free(list);
}
