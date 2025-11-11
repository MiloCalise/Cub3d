/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:02:06 by miltavar          #+#    #+#             */
/*   Updated: 2025/11/11 12:30:18 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

t_tex	*wall_select(t_game *g)
{
	if (g->ray->side == 0 && g->ray->ray_dir_x > 0)
		return (&g->west);
	else if (g->ray->side == 0 && g->ray->ray_dir_x < 0)
		return (&g->east);
	else if (g->ray->side == 1 && g->ray->ray_dir_y > 0)
		return (&g->north);
	else
		return (&g->south);
	return (NULL);
}

void	step_calc(t_game *g, t_tex *tex)
{
	if (g->ray->side == 0)
		g->ray->wall_x = g->ray->pos_y + g->ray->wall_dist * g->ray->ray_dir_y;
	else
		g->ray->wall_x = g->ray->pos_x + g->ray->wall_dist * g->ray->ray_dir_x;
	g->ray->wall_x -= floor(g->ray->wall_x);
	g->ray->text_x = (int)(g->ray->wall_x * (double)(tex->x));
	if ((g->ray->side == 0 && g->ray->ray_dir_x > 0)
		|| (g->ray->side == 1 && g->ray->ray_dir_y < 0))
		g->ray->text_x = tex->x - g->ray->text_x - 1;
	g->ray->step = 1.0 * tex->y / g->ray->line_height;
	g->ray->texpos = (g->ray->draw_start - g->scr_y
			/ 2 + g->ray->line_height / 2) * g->ray->step;
}

void	pixel_loop(t_game *g, t_tex *tex, int *color, int x)
{
	int	y;

	y = 0;
	while (y < g->scr_y)
	{
		if (y < g->ray->draw_start)
			put_pixel(g, x, y, g->top_clr);
		else if (y > g->ray->draw_end)
			put_pixel(g, x, y, g->floor_clr);
		else
		{
			g->ray->text_y = (int)g->ray->texpos % tex->y;
			if (g->ray->text_y < 0)
				g->ray->text_y += tex->y;
			g->ray->texpos += g->ray->step;
			*color = *(unsigned int *)(tex->addr + g->ray->text_y
					* tex->line_len + g->ray->text_x * (tex->bpp / 8));
			put_pixel(g, x, y, *color);
		}
		y++;
	}
}
