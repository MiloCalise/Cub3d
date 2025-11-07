/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 12:34:30 by miltavar          #+#    #+#             */
/*   Updated: 2025/11/05 18:42:09 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	init_directions(t_game *game)
{
	if (game->map[game->player_y][game->player_x] == 'N')
		1 && (game->ray->dirX = 0, game->ray->dirY = -1,
			game->ray->planeX = 0.66, game->ray->planeY = 0);
	else if (game->map[game->player_y][game->player_x] == 'S')
		1 && (game->ray->dirX = 0, game->ray->dirY = 1,
			game->ray->planeX = -0.66, game->ray->planeY = 0);
	else if (game->map[game->player_y][game->player_x] == 'E')
		1 && (game->ray->dirX = 1, game->ray->dirY = 0,
			game->ray->planeX = 0, game->ray->planeY = 0.66);
	else if (game->map[game->player_y][game->player_x] == 'W')
		1 && (game->ray->dirX = -1, game->ray->dirY = 0,
			game->ray->planeX = 0, game->ray->planeY = -0.66);
}
