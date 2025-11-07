/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 12:40:41 by miltavar          #+#    #+#             */
/*   Updated: 2025/11/06 13:32:36 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	dda(t_game *game)
{
	int		x;
	int		y;
	int		hit;
	int		color;
	t_tex	*tex;

	x = 0;
	while (x < game->scr_x)
	{
		game->ray->cameraX = 2 * x / (double)game->scr_x - 1;
		game->ray->ray_dirX = game->ray->dirX + game->ray->planeX * game->ray->cameraX;
		game->ray->ray_dirY = game->ray->dirY + game->ray->planeY * game->ray->cameraX;
		game->ray->mapX = (int)game->ray->posX;
		game->ray->mapY = (int)game->ray->posY;
		if (game->ray->ray_dirX == 0)
			game->ray->delta_distX = 1e30;
		else
			game->ray->delta_distX = fabs(1 / game->ray->ray_dirX);
		if (game->ray->ray_dirY == 0)
			game->ray->delta_distY = 1e30;
		else
			game->ray->delta_distY = fabs(1 / game->ray->ray_dirY);
		if (game->ray->ray_dirX < 0)
		{
			game->ray->stepX = -1;
			game->ray->side_distX = (game->ray->posX - game->ray->mapX) * game->ray->delta_distX;
		}
		else
		{
			game->ray->stepX = 1;
			game->ray->side_distX = (game->ray->mapX + 1.0 - game->ray->posX) * game->ray->delta_distX;
		}
		if (game->ray->ray_dirY < 0)
		{
			game->ray->stepY = -1;
			game->ray->side_distY = (game->ray->posY - game->ray->mapY) * game->ray->delta_distY;
		}
		else
		{
			game->ray->stepY = 1;
			game->ray->side_distY = (game->ray->mapY + 1.0 - game->ray->posY) * game->ray->delta_distY;
		}
		hit = 0;
		while (!hit)
		{
			if (game->ray->side_distX < game->ray->side_distY)
			{
				game->ray->side_distX += game->ray->delta_distX;
				game->ray->mapX += game->ray->stepX;
				game->ray->side = 0;
			}
			else
			{
				game->ray->side_distY += game->ray->delta_distY;
				game->ray->mapY += game->ray->stepY;
				game->ray->side = 1;
			}
			if (game->ray->mapY < 0 || game->ray->mapX < 0 || game->ray->mapY >= game->scr_y || game->ray->mapX >= game->scr_x)
				break ;
			if (game->map[game->ray->mapY][game->ray->mapX] == '1')
				hit = 1;
		}
		if (game->ray->side == 0)
			game->ray->WallDist = (game->ray->side_distX - game->ray->delta_distX);
		else
			game->ray->WallDist = (game->ray->side_distY - game->ray->delta_distY);
		if (game->ray->WallDist <= 0.0)
			game->ray->WallDist = 1e-6;
		game->ray->lineHeight = (int)(game->scr_y / game->ray->WallDist);
		game->ray->drawStart = -game->ray->lineHeight / 2 + game->scr_y / 2;
		if (game->ray->drawStart < 0)
			game->ray->drawStart = 0;
		game->ray->drawEnd = game->ray->lineHeight / 2 + game->scr_y / 2;
		if (game->ray->drawEnd >= game->scr_y)
			game->ray->drawEnd = game->scr_y - 1;
		if (game->ray->side == 0 && game->ray->ray_dirX > 0)
			tex = &game->west;
		else if (game->ray->side == 0 && game->ray->ray_dirX < 0)
			tex = &game->east;
		else if (game->ray->side == 1 && game->ray->ray_dirY > 0)
			tex = &game->north;
		else
			tex = &game->south;
		if (game->ray->side == 0)
			game->ray->wallX = game->ray->posY + game->ray->WallDist * game->ray->ray_dirY;
		else
			game->ray->wallX = game->ray->posX + game->ray->WallDist * game->ray->ray_dirX;
		game->ray->wallX -= floor(game->ray->wallX);
		game->ray->textX = (int)(game->ray->wallX * (double)(tex->x));
		if ((game->ray->side == 0 && game->ray->ray_dirX > 0) || (game->ray->side == 1 && game->ray->ray_dirY < 0))
			game->ray->textX = tex->x - game->ray->textX - 1;
		game->ray->step = 1.0 * tex->y / game->ray->lineHeight;
		game->ray->texpos = (game->ray->drawStart - game->scr_y / 2 + game->ray->lineHeight / 2) * game->ray->step;
		y = 0;
		while (y < game->scr_y)
		{
			if (y < game->ray->drawStart)
				put_pixel(game, x, y, game->top_clr);
			else if (y > game->ray->drawEnd)
				put_pixel(game, x, y, game->floor_clr);
			else
			{
				game->ray->textY = (int)game->ray->texpos & (tex->y - 1);
				game->ray->texpos += game->ray->step;
				color = *(unsigned int *)(tex->addr + game->ray->textY * tex->line_len + game->ray->textX * (tex->bpp / 8));
				put_pixel(game, x, y, color);
			}
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(game->gptr, game->win, game->main.img, 0, 0);
}
