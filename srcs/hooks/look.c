/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:17:45 by miltavar          #+#    #+#             */
/*   Updated: 2025/11/10 18:54:10 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	rotate_left(t_game *g, double angle)
{
	double	old_dirX;
	double	old_planeX;

	old_dirX = g->ray->dirX;
	old_planeX = g->ray->planeX;
	g->ray->dirX = g->ray->dirX * cos(-angle) - g->ray->dirY * sin(-angle);
	g->ray->dirY = old_dirX * sin(-angle) + g->ray->dirY * cos(-angle);
	g->ray->planeX = g->ray->planeX * cos(-angle) - g->ray->planeY * sin(-angle);
	g->ray->planeY = old_planeX * sin(-angle) + g->ray->planeY * cos(-angle);
}

void	rotate_right(t_game *g, double angle)
{
	double	old_dirX;
	double	old_planeX;

	old_dirX = g->ray->dirX;
	old_planeX = g->ray->planeX;
	g->ray->dirX = g->ray->dirX * cos(angle) - g->ray->dirY * sin(angle);
	g->ray->dirY = old_dirX * sin(angle) + g->ray->dirY * cos(angle);
	g->ray->planeX = g->ray->planeX * cos(angle) - g->ray->planeY * sin(angle);
	g->ray->planeY = old_planeX * sin(angle) + g->ray->planeY * cos(angle);
}
