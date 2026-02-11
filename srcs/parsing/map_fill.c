/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 14:08:15 by miltavar          #+#    #+#             */
/*   Updated: 2026/02/11 17:02:51 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	all_whitespace(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!is_whitespace(s[i]))
			return (0);
		i++;
	}
	return (1);
}

void	fill_line(char *s, t_game *game, int y)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(game->map[y]);
	i = (int)len;
	ft_strlcpy(s, game->map[y], len + 1);
	while (i < game->max_len)
	{
		s[i] = 'M';
		i++;
	}
	s[i] = '\0';
}

char	*fill(t_game *game)
{
	char	*res;
	int		i;

	res = ft_calloc(game->max_len + 1, sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (i < game->max_len)
	{
		res[i] = 'M';
		i++;
	}
	res[i] = '\0';
	return (res);
}
