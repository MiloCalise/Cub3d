/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 12:04:11 by miltavar          #+#    #+#             */
/*   Updated: 2025/11/11 13:59:24 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	game_loop(t_game *g)
{
	double	current_time;
	char	*fps;

	gettimeofday(&g->time, NULL);
	current_time = g->time.tv_sec + g->time.tv_usec / 1000000.0;
	g->frame_time = current_time - g->old_time;
	g->old_time = current_time;
	dda(g);
	if (g->frame_time > 0.0001)
		g->fps = (int)(1.0 / g->frame_time);
	else
		g->fps = 0;
	fps = ft_itoa(g->fps);
	if (!fps)
		return (0);
	mlx_string_put(g->gptr, g->win, 10, 20, 0xFFFFFF, fps);
	free(fps);
	return (0);
}

int	game_init(t_game *game)
{
	game->gptr = mlx_init();
	if (!game->gptr)
		return (free_all(game), 1);
	mlx_get_screen_size(game->gptr, &game->scr_x, &game->scr_y);
	game->win = mlx_new_window(game->gptr, game->scr_x, game->scr_y, "Cub3D");
	if (!game->win)
		return (free_all(game), 1);
	if (game_load(game) == 1)
		return (free_all(game), 1);
	mlx_hook(game->win, 2, 1L, keys, game);
	mlx_hook(game->win, 17, 0L, exit_game, game);
	mlx_loop_hook(game->gptr, game_loop, game);
	mlx_loop(game->gptr);
	return (0);
}
