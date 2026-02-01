/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soamraou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:27:40 by soamraou          #+#    #+#             */
/*   Updated: 2026/02/01 16:50:06 by soamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc == 1)
        return (0);
    if (!are_numbers(argc, argv) || is_duplic(argc, argv))
        write (2, "Error\n", 6);
}
