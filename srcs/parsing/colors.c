/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:02:12 by miltavar          #+#    #+#             */
/*   Updated: 2025/11/05 16:37:19 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static int	parse_rgb_value(char *str, int *start, int *tab, int index)
{
	char	*s;
	int		len;

	len = *start;
	while (str[*start] && ft_isdigit(str[*start]))
		(*start)++;
	s = ft_substr(str, len, *start - len);
	if (!s)
		return (get_next_line(-42), 1);
	tab[index] = ft_atoi(s);
	free(s);
	(*start)++;
	return (0);
}

int	grab_colors(int tab[3], char *str, char *tofind)
{
	int		start;

	if (!str)
		return (1);
	if (ft_strncmp(str, tofind, 2) != 0)
		return (1);
	start = 2;
	if (parse_rgb_value(str, &start, tab, 0) == 1)
		return (1);
	if (parse_rgb_value(str, &start, tab, 1) == 1)
		return (1);
	if (parse_rgb_value(str, &start, tab, 2) == 1)
		return (1);
	return (0);
}

int	colors(int fd, t_game *game)
{
	char	*temp;
	int		f_clr[3];
	int		t_clr[3];

	temp = get_next_line(fd);
	if (!temp)
		return (get_next_line(-42), 1);
	temp = skip_space(fd, temp);
	if (grab_colors(f_clr, temp, "F ") == 1)
		return (get_next_line(-42), free(temp), 1);
	free(temp);
	temp = get_next_line(fd);
	if (!temp)
		return (get_next_line(-42), 1);
	temp = skip_space(fd, temp);
	if (grab_colors(t_clr, temp, "C ") == 1)
		return (get_next_line(-42), free(temp), 1);
	game->floor_clr = (f_clr[0] << 16) | (f_clr[1] << 8) | f_clr[2];
	game->top_clr = (t_clr[0] << 16) | (t_clr[1] << 8) | t_clr[2];
	return (free(temp), 0);
}
