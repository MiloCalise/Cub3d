/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:02:12 by miltavar          #+#    #+#             */
/*   Updated: 2026/02/14 12:36:39 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static int	check_rgb(char *s)
{
	int	i;

	if (!s)
		return (1);
	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (1);
		i++;
	}
	return (0);
}

static int check_overflow_itn(int res, int sign, char digit)
{
	if (res > (INT_MAX / 10))
		return (1);
	if (res == (unsigned long long)(INT_MAX / 10))
	{
		if (sign == 1 && (digit - '0') > INT_MAX % 10)
			return (1);
		if (sign == -1 && (digit - '0') > -(INT_MIN % 10))
			return (1);
	}
	return (0);
}

static int ft_atoi_ow(char *str, int *out)
{
    int i = 0;
    int sign = 1;
    int res = 0;

    if (str[i] == '-')
        sign = -1, i++;

    while (str[i] >= '0' && str[i] <= '9')
    {
        if (check_overflow_itn(res, sign, str[i]))
            return (1);
        res = res * 10 + (str[i] - '0');
        i++;
    }
    *out = res * sign;
    return (0);
}

static int parse_rgb_value(char *str, int *start, int *tab, int index)
{
    char *s;
    int len = *start;
    int i;
    int tmp;

    while (str[*start] && ft_isdigit(str[*start]))
        (*start)++;
    i = *start;
    skip_whitespaces(str, &i);
    if (str[i] && str[i] != ',')
        return (get_next_line(-42), 1);
    s = ft_substr(str, len, *start - len);
    if (!s)
        return (get_next_line(-42), 1);
    if (!*s || check_rgb(s))
        return (free(s), get_next_line(-42), 1);
    if (ft_atoi_ow(s, &tmp))
        return (free(s), get_next_line(-42), 1);
    if (tmp < 0 || tmp > 255)
        return (free(s), get_next_line(-42), 1);
    tab[index] = tmp;
    skip_whitespaces(str, start);
    return (free(s), (*start)++, 0);
}


int	grab_colors(int tab[3], char *str, char *tofind)
{
	int	i;

	i = 0;
	skip_whitespaces(str, &i);
	if (ft_strncmp(str + i, tofind, 1) != 0)
		return (1);
	i++;
	if (str[i] && str[i] == '\n')
		return (1);
	skip_whitespaces(str, &i);
	if (parse_rgb_value(str, &i, tab, 0) == 1)
		return (1);
	skip_whitespaces(str, &i);
	if (parse_rgb_value(str, &i, tab, 1) == 1)
		return (1);
	skip_whitespaces(str, &i);
	if (parse_rgb_value(str, &i, tab, 2) == 1)
		return (1);
	return (0);
}
