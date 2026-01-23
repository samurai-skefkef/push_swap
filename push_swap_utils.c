/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soamraou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:34:04 by soamraou          #+#    #+#             */
/*   Updated: 2026/01/23 15:34:29 by soamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int     ft_isdigit(int c)
{
        if (c >= 48 && c <= 57)
                return (1);
        return (0);
}

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
        if (av[i][j] == '\0')
                i++;
        else
            return (0);
    }
    return (1);
}