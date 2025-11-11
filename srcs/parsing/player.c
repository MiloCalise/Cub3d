/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 12:34:30 by miltavar          #+#    #+#             */
/*   Updated: 2025/11/11 12:36:25 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	init_directions(t_game *game)
{
	if (game->map[game->player_y][game->player_x] == 'N')
		1 && (game->ray->dir_x = 0, game->ray->dir_y = -1,
			game->ray->plane_x = 0.66, game->ray->plane_y = 0);
	else if (game->map[game->player_y][game->player_x] == 'S')
		1 && (game->ray->dir_x = 0, game->ray->dir_y = 1,
			game->ray->plane_x = -0.66, game->ray->plane_y = 0);
	else if (game->map[game->player_y][game->player_x] == 'E')
		1 && (game->ray->dir_x = 1, game->ray->dir_y = 0,
			game->ray->plane_x = 0, game->ray->plane_y = 0.66);
	else if (game->map[game->player_y][game->player_x] == 'W')
		1 && (game->ray->dir_x = -1, game->ray->dir_y = 0,
			game->ray->plane_x = 0, game->ray->plane_y = -0.66);
}
