/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:02:06 by miltavar          #+#    #+#             */
/*   Updated: 2025/11/10 12:58:29 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

t_tex	*wall_select(t_game *g)
{
	if (g->ray->side == 0 && g->ray->ray_dirX > 0)
		return (&g->west);
	else if (g->ray->side == 0 && g->ray->ray_dirX < 0)
		return (&g->east);
	else if (g->ray->side == 1 && g->ray->ray_dirY > 0)
		return (&g->north);
	else
		return (&g->south);
	return (NULL);
}

void	step_calc(t_game *g, t_tex *tex)
{
	if (g->ray->side == 0)
		g->ray->wallX = g->ray->posY + g->ray->WallDist * g->ray->ray_dirY;
	else
		g->ray->wallX = g->ray->posX + g->ray->WallDist * g->ray->ray_dirX;
	g->ray->wallX -= floor(g->ray->wallX);
	g->ray->textX = (int)(g->ray->wallX * (double)(tex->x));
	if ((g->ray->side == 0 && g->ray->ray_dirX > 0)
		|| (g->ray->side == 1 && g->ray->ray_dirY < 0))
		g->ray->textX = tex->x - g->ray->textX - 1;
	g->ray->step = 1.0 * tex->y / g->ray->lineHeight;
	g->ray->texpos = (g->ray->drawStart - g->scr_y
			/ 2 + g->ray->lineHeight / 2) * g->ray->step;
}

void	pixel_loop(t_game *g, t_tex *tex, int *color, int x)
{
	int	y;

	y = 0;
	while (y < g->scr_y)
	{
		if (y < g->ray->drawStart)
			put_pixel(g, x, y, g->top_clr);
		else if (y > g->ray->drawEnd)
			put_pixel(g, x, y, g->floor_clr);
		else
		{
			g->ray->textY = (int)g->ray->texpos % tex->y;
			if (g->ray->textY < 0)
				g->ray->textY += tex->y;
			g->ray->texpos += g->ray->step;
			*color = *(unsigned int *)(tex->addr + g->ray->textY
					* tex->line_len + g->ray->textX * (tex->bpp / 8));
			put_pixel(g, x, y, *color);
		}
		y++;
	}
}
