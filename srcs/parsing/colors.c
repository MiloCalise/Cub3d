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

static int	parse_rgb_value(char *str, int *start, int *tab, int index)
{
	char	*s;
	int		len;
	int		i;

	len = *start;
	while (str[*start] && ft_isdigit(str[*start]))
		(*start)++;
	i = *start;
	skip_whitespaces(str, &i);
	if (str[i] && str[i] != ',')
		return (get_next_line(-42), 1);
	s = ft_substr(str, len, *start - len);
	if (!s)
		return (get_next_line(-42), 1);
	if (!*s)
		return (free(s), get_next_line(-42), 1);
	if (check_rgb(s))
		return (get_next_line(-42), free(s), 1);
	tab[index] = ft_atoi(s);
	if (tab[index] < 0 || tab[index] > 255
		|| tab[index] < INT_MIN || tab[index] > INT_MAX)
		return (get_next_line(-42), free(s), 1);
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
