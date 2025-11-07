/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:56:12 by miltavar          #+#    #+#             */
/*   Updated: 2025/11/06 14:19:08 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	move_forward(t_game *game)
{
	if (game->map[(int)game->ray->posY][(int)(game->ray->posX + game->ray->dirX * game->move_speed)] == '0')
		game->ray->posX += game->ray->dirX * game->move_speed;
	if (game->map[(int)(game->ray->posY + game->ray->dirY * game->move_speed)][(int)game->ray->posX] == '0')
		game->ray->posY += game->ray->dirY * game->move_speed;
	dda(game);
}

void	move_backward(t_game *game)
{
	if (game->map[(int)game->ray->posY][(int)(game->ray->posX + game->ray->dirX * game->move_speed)] == '0')
		game->ray->posX -= game->ray->dirX * game->move_speed;
	if (game->map[(int)(game->ray->posY + game->ray->dirY * game->move_speed)][(int)game->ray->posX] == '0')
		game->ray->posY -= game->ray->dirY * game->move_speed;
	dda(game);
}

void	move_right(t_game *game)
{
	if (game->map[(int)game->ray->posY][(int)(game->ray->posX + game->ray->planeX * game->move_speed)] == '0')
		game->ray->posX += game->ray->planeX * game->move_speed;
	if (game->map[(int)(game->ray->posY + game->ray->planeY * game->move_speed)][(int)game->ray->posY] == '0')
		game->ray->posY += game->ray->planeY * game->move_speed;
	dda(game);
}

void	move_left(t_game *game)
{
	if (game->map[(int)game->ray->posY][(int)(game->ray->posX + game->ray->planeX * game->move_speed)] == '0')
		game->ray->posX -= game->ray->planeX * game->move_speed;
	if (game->map[(int)(game->ray->posY + game->ray->planeY * game->move_speed)][(int)game->ray->posY] == '0')
		game->ray->posY -= game->ray->planeY * game->move_speed;
	dda(game);
}
