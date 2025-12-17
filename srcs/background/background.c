/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:43:41 by molapoug          #+#    #+#             */
/*   Updated: 2025/12/17 12:35:08 by molapoug         ###   ########.fr       */
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
	if (!tex->addr)
		return (0);
	dst = tex->addr + (tex_y * tex->line_len + tex_x * (tex->bpp / 8));
	return (*(unsigned int *)dst);
}

static void	init_floor_line(t_game *g, int y, float out[4])
{
	int		p;
	float	pos_z;
	float	row_dist;

	p = y - g->scr_y / 2;
	pos_z = 0.5 * g->scr_y;
	row_dist = pos_z / p;
	out[2] = row_dist * (g->ray_dir1[0] - g->ray_dir0[0]) / g->scr_x;
	out[3] = row_dist * (g->ray_dir1[1] - g->ray_dir0[1]) / g->scr_x;
	out[0] = g->ray->pos_x + row_dist * g->ray_dir0[0];
	out[1] = g->ray->pos_y + row_dist * g->ray_dir0[1];
}

static void	render_floor_line(t_game *g, int y)
{
	int		x;
	float	out[4];
	int		color;

	init_floor_line(g, y, out);
	x = -1;
	while (++x < g->scr_x)
	{
		color = get_tex_color(&g->floor, (int)(out[0] * 64),
				(int)(out[1] * 64));
		put_pixel(g, x, y, color);
		color = get_tex_color(&g->ciel, (int)(out[0] * 64),
				(int)(out[1] * 64));
		put_pixel(g, x, g->scr_y - y - 1, color);
		out[0] += out[2];
		out[1] += out[3];
	}
}

void	draw_textured_background(t_game *g)
{
	int		y;

	g->ray_dir0[0] = g->ray->dir_x - g->ray->plane_x;
	g->ray_dir0[1] = g->ray->dir_y - g->ray->plane_y;
	g->ray_dir1[0] = g->ray->dir_x + g->ray->plane_x;
	g->ray_dir1[1] = g->ray->dir_y + g->ray->plane_y;
	y = g->scr_y / 2 + 1;
	while (y < g->scr_y)
	{
		render_floor_line(g, y);
		y++;
	}
}
