/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:02:12 by miltavar          #+#    #+#             */
/*   Updated: 2026/01/31 12:53:02 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static int	check_rgb(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]) && !is_whitespace(s[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	parse_rgb_value(char *str, int *start, int *tab, int index)
{
	char	*s;
	int		len;

	len = *start;
	while (str[*start] && str[*start] != ',')
		(*start)++;
	s = ft_substr(str, len, *start - len);
	if (!s)
		return (get_next_line(-42), 1);
	if (check_rgb(s))
		return (get_next_line(-42), free(s), 1);
	tab[index] = ft_atoi(s);
	if (tab[index] < 0 || tab[index] > 255)
		return (get_next_line(-42), free(s), 1);
	free(s);
	(*start)++;
	return (0);
}

int	grab_colors(int tab[3], char *str, char *tofind)
{
	int	i;

	if (!str)
		return (1);
	i = 0;
	skip_whitespaces(str, &i);
	if (ft_strncmp(str + i, tofind, 2) != 0)
		return (1);
	i++;
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
