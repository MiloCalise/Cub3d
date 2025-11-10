/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:56:12 by miltavar          #+#    #+#             */
/*   Updated: 2025/11/10 14:58:18 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	move_forward(t_game *g)
{
	double	newX;
	double	newY;

	newX = g->ray->posX + g->ray->dirX * g->move_speed;
	newY = g->ray->posY + g->ray->dirY * g->move_speed;
	if (g->map[(int)g->ray->posY]
		[(int)(newX + g->ray->dirX * g->coll_margin)] != '1')
		g->ray->posX = newX;
	if (g->map[(int)(newY + g->ray->dirY * g->coll_margin)]
		[(int)g->ray->posX] != '1')
		g->ray->posY = newY;
	dda(g);
}

void	move_backward(t_game *g)
{
	double	newX;
	double	newY;

	newX = g->ray->posX - g->ray->dirX * g->move_speed;
	newY = g->ray->posY - g->ray->dirY * g->move_speed;
	if (g->map[(int)g->ray->posY]
		[(int)(newX - g->ray->dirX * g->coll_margin)] != '1')
		g->ray->posX = newX;
	if (g->map[(int)(newY - g->ray->dirY * g->coll_margin)]
		[(int)g->ray->posX] != '1')
		g->ray->posY = newY;
	dda(g);
}

void	move_right(t_game *g)
{
	double	newX;
	double	newY;

	newX = g->ray->posX + g->ray->planeX * g->move_speed;
	newY = g->ray->posY + g->ray->planeY * g->move_speed;
	if (g->map[(int)g->ray->posY]
		[(int)(newX + g->ray->planeX * g->coll_margin)] != '1')
		g->ray->posX = newX;
	if (g->map[(int)(newY + g->ray->planeY * g->coll_margin)]
		[(int)g->ray->posX] != '1')
		g->ray->posY = newY;
	dda(g);
}

void	move_left(t_game *g)
{
	double	newX;
	double	newY;

	newX = g->ray->posX - g->ray->planeX * g->move_speed;
	newY = g->ray->posY - g->ray->planeY * g->move_speed;
	if (g->map[(int)g->ray->posY]
		[(int)(newX - g->ray->planeX * g->coll_margin)] != '1')
		g->ray->posX = newX;
	if (g->map[(int)(newY - g->ray->planeY * g->coll_margin)]
		[(int)g->ray->posX] != '1')
		g->ray->posY = newY;
	dda(g);
}

