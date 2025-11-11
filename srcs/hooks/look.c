/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:17:45 by miltavar          #+#    #+#             */
/*   Updated: 2025/11/11 12:37:41 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	rotate_left(t_game *g, double angle)
{
	double	olddirx;
	double	oldplanex;

	olddirx = g->ray->dir_x;
	oldplanex = g->ray->plane_x;
	g->ray->dir_x = g->ray->dir_x * cos(-angle) - g->ray->dir_y * sin(-angle);
	g->ray->dir_y = olddirx * sin(-angle) + g->ray->dir_y * cos(-angle);
	g->ray->plane_x = g->ray->plane_x * cos(-angle)
		- g->ray->plane_y * sin(-angle);
	g->ray->plane_y = oldplanex * sin(-angle) + g->ray->plane_y * cos(-angle);
}

void	rotate_right(t_game *g, double angle)
{
	double	olddirx;
	double	oldplanex;

	olddirx = g->ray->dir_x;
	oldplanex = g->ray->plane_x;
	g->ray->dir_x = g->ray->dir_x * cos(angle) - g->ray->dir_y * sin(angle);
	g->ray->dir_y = olddirx * sin(angle) + g->ray->dir_y * cos(angle);
	g->ray->plane_x = g->ray->plane_x * cos(angle)
		- g->ray->plane_y * sin(angle);
	g->ray->plane_y = oldplanex * sin(angle) + g->ray->plane_y * cos(angle);
}
