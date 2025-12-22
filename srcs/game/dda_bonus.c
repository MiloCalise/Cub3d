/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:30:16 by miltavar          #+#    #+#             */
/*   Updated: 2025/12/22 15:31:23 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	dda_bonus(t_game *g)
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
		pixel_loop_bonus(g, tex, &color, x);
		x++;
	}
	mlx_put_image_to_window(g->gptr, g->win, g->main.img, 0, 0);
}
