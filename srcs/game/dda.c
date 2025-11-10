/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 12:40:41 by miltavar          #+#    #+#             */
/*   Updated: 2025/11/10 12:55:38 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	ray_direction(t_game *g, int x)
{
	g->ray->cameraX = 2 * x / (double)g->scr_x - 1;
	g->ray->ray_dirX = g->ray->dirX + g->ray->planeX * g->ray->cameraX;
	g->ray->ray_dirY = g->ray->dirY + g->ray->planeY * g->ray->cameraX;
	g->ray->mapX = (int)g->ray->posX;
	g->ray->mapY = (int)g->ray->posY;
	if (g->ray->ray_dirX == 0)
		g->ray->delta_distX = 1e30;
	else
		g->ray->delta_distX = fabs(1 / g->ray->ray_dirX);
	if (g->ray->ray_dirY == 0)
		g->ray->delta_distY = 1e30;
	else
		g->ray->delta_distY = fabs(1 / g->ray->ray_dirY);
}

static void	ray_direction2(t_game *g)
{
	if (g->ray->ray_dirX < 0)
	{
		g->ray->stepX = -1;
		g->ray->side_distX = (g->ray->posX - g->ray->mapX)
			* g->ray->delta_distX;
	}
	else
	{
		g->ray->stepX = 1;
		g->ray->side_distX = (g->ray->mapX + 1.0 - g->ray->posX)
			* g->ray->delta_distX;
	}
	if (g->ray->ray_dirY < 0)
	{
		g->ray->stepY = -1;
		g->ray->side_distY = (g->ray->posY - g->ray->mapY)
			* g->ray->delta_distY;
	}
	else
	{
		g->ray->stepY = 1;
		g->ray->side_distY = (g->ray->mapY + 1.0 - g->ray->posY)
			* g->ray->delta_distY;
	}
}

static void	hit_loop(t_game *g)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (g->ray->side_distX < g->ray->side_distY)
		{
			g->ray->side_distX += g->ray->delta_distX;
			g->ray->mapX += g->ray->stepX;
			g->ray->side = 0;
		}
		else
		{
			g->ray->side_distY += g->ray->delta_distY;
			g->ray->mapY += g->ray->stepY;
			g->ray->side = 1;
		}
		if (g->ray->mapY < 0 || g->ray->mapX < 0
			|| g->ray->mapY >= g->scr_y || g->ray->mapX >= g->scr_x)
			break ;
		if (g->map[g->ray->mapY][g->ray->mapX] == '1')
			hit = 1;
	}
}

static void	wall_calc(t_game *g)
{
	if (g->ray->side == 0)
		g->ray->WallDist = (g->ray->side_distX - g->ray->delta_distX);
	else
		g->ray->WallDist = (g->ray->side_distY - g->ray->delta_distY);
	if (g->ray->WallDist <= 0.0)
		g->ray->WallDist = 1e-6;
	g->ray->lineHeight = (int)(g->scr_y / g->ray->WallDist);
	g->ray->drawStart = -g->ray->lineHeight / 2 + g->scr_y / 2;
	if (g->ray->drawStart < 0)
		g->ray->drawStart = 0;
	g->ray->drawEnd = g->ray->lineHeight / 2 + g->scr_y / 2;
	if (g->ray->drawEnd >= g->scr_y)
		g->ray->drawEnd = g->scr_y - 1;
}

void	dda(t_game *g)
{
	int		x;
	int		color;
	t_tex	*tex;

	x = 0;
	tex = NULL;
	color = 0;
	while (x < g->scr_x)
	{
		ray_direction(g, x);
		ray_direction2(g);
		hit_loop(g);
		wall_calc(g);
		tex = wall_select(g);
		if (!tex)
			return ;
		step_calc(g, tex);
		pixel_loop(g, tex, &color, x);
		x++;
	}
	mlx_put_image_to_window(g->gptr, g->win, g->main.img, 0, 0);
}
