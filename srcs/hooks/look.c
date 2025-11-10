/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:17:45 by miltavar          #+#    #+#             */
/*   Updated: 2025/11/10 18:03:18 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	rotate_camera(t_game *g, double angle)
{
	double	old_dirX;
	double	old_planeX;

	old_dirX = g->ray->dirX;
	old_planeX = g->ray->planeX;
	g->ray->dirX = g->ray->dirX * cos(angle) - g->ray->dirY * sin(angle);
	g->ray->dirY = old_dirX * sin(angle) + g->ray->dirY * cos(angle);
	g->ray->planeX = g->ray->planeX * cos(angle) - g->ray->planeY * sin(angle);
	g->ray->planeY = old_planeX * sin(angle) + g->ray->planeX * cos(angle);
}

void	look_right(t_game *game)
{
	rotate_camera(game, game->rot_speed);
	dda(game);
}

void	look_left(t_game *game)
{
	rotate_camera(game, -game->rot_speed);
	dda(game);
}
