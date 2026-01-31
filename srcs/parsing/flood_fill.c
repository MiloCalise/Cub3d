/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 12:37:08 by miltavar          #+#    #+#             */
/*   Updated: 2026/01/29 12:52:09 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	check_dup(char **copy, t_game *game)
{
	int	i;
	int	j;
	int	count;

	game->player_x = -1;
	if (!copy)
		return (1);
	1 && (i = 0, count = 0);
	while (copy[i])
	{
		j = 0;
		while (copy[i][j])
		{
			if (copy[i][j] == 'N' || copy[i][j] == 'S'
					|| copy[i][j] == 'E' || copy[i][j] == 'W')
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
	if (x < 0 || y < 0 || y >= game->map_size || x >= (int)ft_strlen(copy[y]))
		return ;
	if (!copy[y][x] || is_whitespace(copy[y][x]))
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
