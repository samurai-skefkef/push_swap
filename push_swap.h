/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soamraou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:27:13 by soamraou          #+#    #+#             */
/*   Updated: 2026/02/03 11:09:45 by soamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

int     ft_isdigit(int c);
char    **ft_split(char const *s, char c);
long     ft_atoi(const char *s);
int     *list_int(char **av);
int count_nums(char **av);
int is_duplic(int *list, int size);
int are_numbers(int ac, char **av);

#endif
