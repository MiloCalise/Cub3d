/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 12:37:08 by miltavar          #+#    #+#             */
/*   Updated: 2026/02/08 15:03:39 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	get_max(t_game *game)
{
	int		i;
	size_t	len;

	i = 0;
	game->max_len = 0;
	while (game->map[i])
	{
		len = ft_strlen(game->map[i]);
		if (len > (size_t)game->max_len)
			game->max_len = len;
		i++;
	}
}

int	check_dup(t_game *game)
{
	int	i;
	int	j;
	int	count;

	game->player_x = -1;
	1 && (i = 0, count = 0);
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'N' || game->map[i][j] == 'S'
					|| game->map[i][j] == 'E' || game->map[i][j] == 'W')
				1 && (count++, game->player_x = j, game->player_y = i);
			j++;
		}
		i++;
	}
	game->ray->pos_x = (double)game->player_x;
	game->ray->pos_y = (double)game->player_y;
	if (count != 1)
		return (1);
	return (0);
}

void	flood_fill(t_game *game, int x, int y, char **copy)
{
	if (x < 0 || y < 0 || y >= game->map_size || x > (int)ft_strlen(copy[y]))
		return ;
	if (!copy[y][x] || is_whitespace(copy[y][x]) || copy[y][x] == 'f')
	{
		game->player_x = -1;
		return ;
	}
	if (copy[y][x] == '2')
		return ;
	else if (copy[y][x] == '0' || copy[y][x] == 'N'
		|| copy[y][x] == 'W' || copy[y][x] == 'E' || copy[y][x] == 'S')
	{
		copy[y][x] = '2';
		flood_fill(game, x - 1, y, copy);
		flood_fill(game, x + 1, y, copy);
		flood_fill(game, x, y - 1, copy);
		flood_fill(game, x, y + 1, copy);
	}
}
