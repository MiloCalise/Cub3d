/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 11:47:47 by miltavar          #+#    #+#             */
/*   Updated: 2025/11/06 14:25:54 by miltavar         ###   ########.fr       */
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
	game->move_speed = 0.1;
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
	// else if (keycode == XK_Left)
	// 	look_left(game);
	// else if (keycode == XK_Right)
	// 	look_right(game);
	return (0);
}
