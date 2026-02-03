/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_errors_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soamraou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:34:04 by soamraou          #+#    #+#             */
/*   Updated: 2026/02/03 11:08:13 by soamraou         ###   ########.fr       */
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
        while (av[i][j] != '\0' && (ft_isdigit(av[i][j]) || av[i][j] == ' ' || av[i][j] == '-' || av[i][j] == '+'))
	{
		if (av[i][j] == '-' || av[i][j] == '+')
		{
			if (!ft_isdigit(av[i][j + 1]))
				return (0);
			if (j > 0 && av[i][j - 1] != ' ')
				return (0);
		}
		j++;
	}
        if (av[i][j] == '\0')
                i++;
        else
            return (0);
    }
    return (1);
}

//To count the number of numbers for the allocation of the list:
int count_nums(char **av)
{
    int i;
    int j;
    int count;
    char **split;

    i = 1;
    count = 0;
    while (av[i])
    {
        split = ft_split(av[i], ' ');
        if (!split)
            return (0);
        j = 0;
        while (split[j])
        {
            count++;
            free(split[j]);
            j++;
        }
        free(split);
        i++;
    }
    return (count);
}

//To fill the list:
int	*list_int(char **av)
{
	int i;
	int j;
	int k;
	char **split;
	int *list;

	i = 1;
	k = 0;
	list = malloc(count_nums(av) * sizeof(int));
	if (!list)
		return (0);
	while(av[i])
	{
		j = 0;
		split = ft_split(av[i], ' ');
		while (split[j])
		{
			if (ft_atoi(split[j]) < INT_MIN || ft_atoi(split[j]) > INT_MAX)
				return (NULL);
			list[k++] = (int)ft_atoi(split[j]);
			free(split[j]);
			j++;
		}
		free(split);
		i++;
	}
	return (list);
}

//Duplicate checker:
int is_duplic(int *list, int size)
{
    int i;
    int j;

    i = 0;
    while (i < size)
    {
        j = i + 1;
        while (j < size)
        {
            if (list[i] == list[j])
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}
