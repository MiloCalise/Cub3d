/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 12:40:41 by miltavar          #+#    #+#             */
/*   Updated: 2025/11/11 12:28:26 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	ray_direction(t_game *g, int x)
{
	g->ray->camera_x = 2 * x / (double)g->scr_x - 1;
	g->ray->ray_dir_x = g->ray->dir_x + g->ray->plane_x * g->ray->camera_x;
	g->ray->ray_dir_y = g->ray->dir_y + g->ray->plane_y * g->ray->camera_x;
	g->ray->map_x = (int)g->ray->pos_x;
	g->ray->map_y = (int)g->ray->pos_y;
	if (g->ray->ray_dir_x == 0)
		g->ray->delta_dist_x = 1e30;
	else
		g->ray->delta_dist_x = fabs(1 / g->ray->ray_dir_x);
	if (g->ray->ray_dir_y == 0)
		g->ray->delta_dist_y = 1e30;
	else
		g->ray->delta_dist_y = fabs(1 / g->ray->ray_dir_y);
}

static void	ray_direction2(t_game *g)
{
	if (g->ray->ray_dir_x < 0)
	{
		g->ray->step_x = -1;
		g->ray->side_dist_x = (g->ray->pos_x - g->ray->map_x)
			* g->ray->delta_dist_x;
	}
	else
	{
		g->ray->step_x = 1;
		g->ray->side_dist_x = (g->ray->map_x + 1.0 - g->ray->pos_x)
			* g->ray->delta_dist_x;
	}
	if (g->ray->ray_dir_y < 0)
	{
		g->ray->step_y = -1;
		g->ray->side_dist_y = (g->ray->pos_y - g->ray->map_y)
			* g->ray->delta_dist_y;
	}
	else
	{
		g->ray->step_y = 1;
		g->ray->side_dist_y = (g->ray->map_y + 1.0 - g->ray->pos_y)
			* g->ray->delta_dist_y;
	}
}

static void	hit_loop(t_game *g)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (g->ray->side_dist_x < g->ray->side_dist_y)
		{
			g->ray->side_dist_x += g->ray->delta_dist_x;
			g->ray->map_x += g->ray->step_x;
			g->ray->side = 0;
		}
		else
		{
			g->ray->side_dist_y += g->ray->delta_dist_y;
			g->ray->map_y += g->ray->step_y;
			g->ray->side = 1;
		}
		if (g->ray->map_y < 0 || g->ray->map_x < 0
			|| g->ray->map_y >= g->scr_y || g->ray->map_x >= g->scr_x)
			break ;
		if (g->map[g->ray->map_y][g->ray->map_x] == '1')
			hit = 1;
	}
}

static void	wall_calc(t_game *g)
{
	if (g->ray->side == 0)
		g->ray->wall_dist = (g->ray->side_dist_x - g->ray->delta_dist_x);
	else
		g->ray->wall_dist = (g->ray->side_dist_y - g->ray->delta_dist_y);
	if (g->ray->wall_dist <= 0.0)
		g->ray->wall_dist = 1e-6;
	g->ray->line_height = (int)(g->scr_y / g->ray->wall_dist);
	g->ray->draw_start = -g->ray->line_height / 2 + g->scr_y / 2;
	if (g->ray->draw_start < 0)
		g->ray->draw_start = 0;
	g->ray->draw_end = g->ray->line_height / 2 + g->scr_y / 2;
	if (g->ray->draw_end >= g->scr_y)
		g->ray->draw_end = g->scr_y - 1;
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
