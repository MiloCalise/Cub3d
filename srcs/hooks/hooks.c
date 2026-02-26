/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 11:47:47 by miltavar          #+#    #+#             */
/*   Updated: 2025/12/22 16:01:42 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	exit_game(t_game *game)
{
	free_all(game);
	exit(0);
	return (0);
}

// fonction qui permet d'afficher la mini_map
void	handle_minimap_keys(int keycode, t_game *game)
{
	if (keycode == XK_m)
		game->ray->minimap_on = !game->ray->minimap_on;
	else if (keycode == XK_equal || keycode == XK_plus)
		game->ray->minimap_scale += 1;
	else if (keycode == XK_minus)
	{
		game->ray->minimap_scale -= 1;
		if (game->ray->minimap_scale < 5)
			game->ray->minimap_scale = 5;
	}
}

int	mouse_move(int x, int y, t_game *game)
{
	int		center_x;
	double	delta;

	(void)y;
	center_x = game->scr_x / 2;
	delta = (x - center_x) * 0.002;
	if (delta == 0.0)
		return (0);
	if (delta > 0)
		rotate_right(game, delta);
	else
		rotate_left(game, -delta);
	mlx_mouse_move(game->gptr, game->win, center_x, game->scr_y / 2);
	game->mouse_x = center_x;
	return (0);
}

int	keys(int keycode, t_game *game)
{
	game->coll_margin = 0.4;
	game->move_speed = 0.1;
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
		rotate_left(game, game->rot_speed);
	else if (keycode == XK_Right)
		rotate_right(game, game->rot_speed);
	else
		handle_minimap_keys(keycode, game);
	return (0);
}
