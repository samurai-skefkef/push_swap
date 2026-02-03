/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soamraou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 16:56:49 by soamraou          #+#    #+#             */
/*   Updated: 2026/02/03 11:09:17 by soamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     ft_isdigit(int c)
{
        if (c >= 48 && c <= 57)
                return (1);
        return (0);
}

long     ft_atoi(const char *s)
{
        int     i;
        long     num;
        int     neg;

        if (s == NULL)
                return (0);
        i = 0;
        while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'
                        || s[i] == '\r' || s[i] == '\v' || s[i] == '\f'))
                i++;
        neg = 0;
        num = 0;
        if (s[i] == '+')
                i++;
        else if (s[i] == '-')
        {
                neg = 1;
                i++;
        }
        while (ft_isdigit(s[i]))
                num = num * 10 + (s[i++] - 48);
        if (neg == 1)
                num = -num;
        return (num);
}

static	size_t	w_cnt(const char *s, char c)
{
	int		i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	if (s[0] != c && s[0] != '\0')
		cnt = 1;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != '\0' && s[i + 1] != c)
			cnt++;
		i++;
	}
	return (cnt);
}

static int	*mall_check(const char *s, char c)
{
	int	*ret;

	ret = malloc(w_cnt(s, c) * sizeof(int));
	if (ret == NULL)
		return (NULL);
	return (ret);
}

static	int	*s_len_mk(const char *s, char c)
{
	int		i;
	size_t	cnt;
	int		len;
	int		*ret;

	ret = mall_check (s, c);
	i = 0;
	cnt = 0;
	len = 0;
	while (s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c)
		{
			ret[cnt++] = len;
			len = 0;
		}
		if (s[i] != c)
			len++;
		i++;
	}
	if (len > 0)
		ret[cnt] = len;
	return (ret);
}

static void	fill_arr(char const *s, char c, char **arr, int *s_len)
{
	int	i;
	int	cnt;
	int	len;

	i = 0;
	cnt = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		len = 0;
		arr[cnt] = malloc(s_len[cnt] + 1);
		if (arr[cnt] == NULL)
			return ;
		while (s[i] != '\0' && s[i] != c)
			arr[cnt][len++] = s[i++];
		arr[cnt][len] = '\0';
		cnt++;
	}
	arr[cnt] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		*s_len;

	if (s == NULL)
		return (NULL);
	arr = malloc((w_cnt(s, c) + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	if (w_cnt(s, c) == 0)
	{
		arr[0] = NULL;
		return (arr);
	}
	s_len = s_len_mk(s, c);
	if (s_len == NULL)
		return (NULL);
	fill_arr(s, c, arr, s_len);
	free (s_len);
	return (arr);
}
