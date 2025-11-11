/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:56:12 by miltavar          #+#    #+#             */
/*   Updated: 2025/11/11 12:34:41 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	move_forward(t_game *g)
{
	double	newx;
	double	newy;

	newx = g->ray->pos_x + g->ray->dir_x * g->move_speed;
	newy = g->ray->pos_y + g->ray->dir_y * g->move_speed;
	if (g->map[(int)g->ray->pos_y]
		[(int)(newx + g->ray->dir_x * g->coll_margin)] != '1')
		g->ray->pos_x = newx;
	if (g->map[(int)(newy + g->ray->dir_y * g->coll_margin)]
		[(int)g->ray->pos_x] != '1')
		g->ray->pos_y = newy;
}

void	move_backward(t_game *g)
{
	double	newx;
	double	newy;

	newx = g->ray->pos_x - g->ray->dir_x * g->move_speed;
	newy = g->ray->pos_y - g->ray->dir_y * g->move_speed;
	if (g->map[(int)g->ray->pos_y]
		[(int)(newx - g->ray->dir_x * g->coll_margin)] != '1')
		g->ray->pos_x = newx;
	if (g->map[(int)(newy - g->ray->dir_y * g->coll_margin)]
		[(int)g->ray->pos_x] != '1')
		g->ray->pos_y = newy;
}

void	move_right(t_game *g)
{
	double	newx;
	double	newy;

	newx = g->ray->pos_x + g->ray->plane_x * g->move_speed;
	newy = g->ray->pos_y + g->ray->plane_y * g->move_speed;
	if (g->map[(int)g->ray->pos_y]
		[(int)(newx + g->ray->plane_x * g->coll_margin)] != '1')
		g->ray->pos_x = newx;
	if (g->map[(int)(newy + g->ray->plane_y * g->coll_margin)]
		[(int)g->ray->pos_x] != '1')
		g->ray->pos_y = newy;
}

void	move_left(t_game *g)
{
	double	newx;
	double	newy;

	newx = g->ray->pos_x - g->ray->plane_x * g->move_speed;
	newy = g->ray->pos_y - g->ray->plane_y * g->move_speed;
	if (g->map[(int)g->ray->pos_y]
		[(int)(newx - g->ray->plane_x * g->coll_margin)] != '1')
		g->ray->pos_x = newx;
	if (g->map[(int)(newy - g->ray->plane_y * g->coll_margin)]
		[(int)g->ray->pos_x] != '1')
		g->ray->pos_y = newy;
}
