/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 12:37:08 by miltavar          #+#    #+#             */
/*   Updated: 2025/11/10 12:37:30 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	flood_fill(t_game *game, int x, int y, char **copy)
{
	int	len;

	len = ft_strlen(copy[y]);
	if (x < 0 || x >= len || y < 0 || y >= game->map_size)
		return ;
	if (copy[y][x] == '1' || copy[y][x] == '3')
		return ;
	else if (copy[y][x] == '0' || copy[y][x] == 'N'
		|| copy[y][x] == 'W' || copy[y][x] == 'E' || copy[y][x] == 'S')
	{
		copy[y][x] = '3';
		flood_fill(game, x - 1, y, copy);
		flood_fill(game, x + 1, y, copy);
		flood_fill(game, x, y - 1, copy);
		flood_fill(game, x, y + 1, copy);
	}
	else if (is_invalid(copy[y][x]))
	{
		game->player_x = -1;
		return ;
	}
}
