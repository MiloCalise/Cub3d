/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 11:47:47 by miltavar          #+#    #+#             */
/*   Updated: 2025/11/10 17:10:38 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	exit_game(t_game *game)
{
	free_all(game);
	exit (0);
	return (0);
}

int	keys(int keycode, t_game *game)
{
	game->coll_margin = 0.3;
	game->move_speed = 0.5;
	game->rot_speed = 0.05;
	if (keycode == XK_Escape)
		exit_game(game);
	else if (keycode == XK_w)
		move_forward(game);
	else if (keycode == XK_s)
		move_backward(game);
	else if (keycode == XK_d)
		move_right(game);
	else if (keycode == XK_a)
		move_left(game);
	else if (keycode == XK_Left)
		look_left(game);
	else if (keycode == XK_Right)
		look_right(game);
	return (0);
}
