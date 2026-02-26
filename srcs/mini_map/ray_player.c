/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 13:24:47 by molapoug          #+#    #+#             */
/*   Updated: 2026/02/26 14:44:15 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	is_wall(t_game *g, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (map_x < 0 || map_x >= g->max_len
		|| map_y < 0 || map_y >= g->map_size)
		return (1);
	if (!g->map[map_y])
		return (1);
	return (g->map[map_y][map_x] == '1');
}

static void	sample_and_draw(t_game *g, double dx, double dy)
{
	double	t;
	double	w[2];
	int		s[2];

	if (g->ray->minimap_scale <= 0)
		g->ray->minimap_scale = 10;
	t = 0.0;
	while (t <= 75.0 / g->ray->minimap_scale)
	{
		w[0] = g->ray->pos_x + dx * t;
		w[1] = g->ray->pos_y + dy * t;
		s[0] = 95 + (int)((w[0] - g->ray->pos_x) * g->ray->minimap_scale);
		s[1] = 95 + (int)((w[1] - g->ray->pos_y) * g->ray->minimap_scale);
		if ((s[0] - 95) * (s[0] - 95) + (s[1] - 95) * (s[1] - 95) > 5625)
			break ;
		put_pixel(g, s[0], s[1], 0xFFFF00);
		if (is_wall(g, w[0], w[1]))
			break ;
		t += 0.05;
	}
}

void	cast_ray(t_game *g, double ray_angle)
{
	double	dx;
	double	dy;

	dx = cos(ray_angle);
	dy = sin(ray_angle);
	sample_and_draw(g, dx, dy);
}

void	draw_rays(t_game *g)
{
	int		i;
	double	fov;
	double	player_angle;
	double	angle_step;

	fov = 1.15;
	i = 0;
	while (i < 90)
	{
		angle_step = fov / 90.0;
		player_angle = atan2(g->ray->dir_y, g->ray->dir_x);
		cast_ray(g, player_angle - fov / 2.0 + i * angle_step);
		i++;
	}
}
