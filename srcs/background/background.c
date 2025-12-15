/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:43:41 by miltavar          #+#    #+#             */
/*   Updated: 2025/12/15 17:01:26 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static int	get_tex_color(t_tex *tex, int x, int y)
{
	char	*dst;
	int		tex_x;
	int		tex_y;

	tex_x = x & (64 - 1);
	tex_y = y & (64 - 1);
	dst = tex->addr + (tex_y * tex->line_len + tex_x * (tex->bpp / 8));
	return (*(unsigned int *)dst);
}

static void	render_floor_line(t_game *g, int y,
	float ray_dir0[2], float ray_dir1[2])
{
	t_bg	bg;

	bg.p = y - g->scr_y / 2;
	bg.pos_z = 0.5 * g->scr_y;
	bg.row_dist = bg.pos_z / bg.p;
	bg.step[0] = bg.row_dist * (ray_dir1[0] - ray_dir0[0]) / g->scr_x;
	bg.step[1] = bg.row_dist * (ray_dir1[1] - ray_dir0[1]) / g->scr_x;
	bg.floor[0] = g->ray->pos_x + bg.row_dist * ray_dir0[0];
	bg.floor[1] = g->ray->pos_y + bg.row_dist * ray_dir0[1];
	bg.x = 0;
	while (bg.x < g->scr_x)
	{
		bg.color = get_tex_color(&g->north, (int)(bg.floor[0] * 64),
				(int)(bg.floor[1] * 64));
		put_pixel(g, bg.x, y, bg.color);
		bg.color = get_tex_color(&g->south, (int)(bg.floor[0] * 64),
				(int)(bg.floor[1] * 64));
		put_pixel(g, bg.x, g->scr_y - y - 1, bg.color);
		bg.floor[0] += bg.step[0];
		bg.floor[1] += bg.step[1];
		bg.x++;
	}
}

void	draw_textured_background(t_game *g)
{
	int		y;
	float	ray_dir0[2];
	float	ray_dir1[2];

	ray_dir0[0] = g->ray->dir_x - g->ray->plane_x;
	ray_dir0[1] = g->ray->dir_y - g->ray->plane_y;
	ray_dir1[0] = g->ray->dir_x + g->ray->plane_x;
	ray_dir1[1] = g->ray->dir_y + g->ray->plane_y;
	y = g->scr_y / 2 + 1;
	while (y < g->scr_y)
	{
		render_floor_line(g, y, ray_dir0, ray_dir1);
		y++;
	}
}
