/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soamraou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:34:04 by soamraou          #+#    #+#             */
/*   Updated: 2026/02/01 18:54:11 by soamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int are_numbers(int ac, char **av)
{
    int i;
    int j;

    i = 1;
    while (i < ac)
    {
        j = 0;
        if (av[i][j] == '+' || av[i][j] == '-')
            j = 1;
        while (av[i][j] != '\0' && (ft_isdigit(av[i][j]) || av[i][j] == ' '))
            j++;
	if (j == 1 && (av[i][j - 1] == '+' || av[i][j - 1] == '-'))
                        return (0);
        if (av[i][j] == '\0')
                i++;
        else
            return (0);
    }
    return (1);
}

int	**list(int ac, char **av)
{
	int i;

	i = 0;

}

int is_duplic(int ac, char **av)
{
    int i;
    int j;

    i = 1;
    while (i < ac - 1)
    {
        j = i + 1;
	while (j < ac)
	{
		if (ft_strlen(av[i]) == ft_strlen(av[j]) && ft_strnstr(av[i], av[j], ft_strlen(av[i])) != NULL)
			return (1);
		j++;
	}
	i++;
    }
    return (0);
}
