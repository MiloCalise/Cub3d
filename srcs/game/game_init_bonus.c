/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:01:56 by miltavar          #+#    #+#             */
/*   Updated: 2026/02/26 14:39:20 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	game_loop_bonus(t_game *g)
{
	double	current_time;

	gettimeofday(&g->time, NULL);
	current_time = g->time.tv_sec + g->time.tv_usec / 1000000.0;
	g->frame_time = current_time - g->old_time;
	g->old_time = current_time;
	draw_textured_background(g);
	dda_bonus(g);
	update_projectile(g);
	draw_minimap(g);
	draw_projectile(g);
	mlx_put_image_to_window(g->gptr, g->win, g->main.img, 0, 0);
	calc_fps(g);
	return (0);
}

int	game_load_bonus(t_game *g)
{
	g->main.img = mlx_new_image(g->gptr, g->scr_x, g->scr_y);
	if (!g->main.img)
		return (1);
	g->main.addr = mlx_get_data_addr(g->main.img, &g->main.bpp,
			&g->main.line_len, &g->main.endian);
	if (!g->main.addr)
		return (ft_putstr_fd("failed to load addr\n", 2), 1);
	if (north_img(g) == 1)
		return (1);
	if (south_img(g) == 1)
		return (1);
	if (east_img(g) == 1)
		return (1);
	if (west_img(g) == 1)
		return (1);
	load_textures(g);
	return (0);
}

void	init_minimap(t_game *game)
{
	game->ray->minimap_on = 1;
	game->ray->minimap_scale = 10;
	game->ray->minimap_margin = 10;
}

int	game_init_bonus(t_game *game)
{
	game->gptr = mlx_init();
	if (!game->gptr)
		return (free_all(game), 1);
	mlx_get_screen_size(game->gptr, &game->scr_x, &game->scr_y);
	game->win = mlx_new_window(game->gptr, game->scr_x, game->scr_y, "Cub3D");
	if (!game->win)
		return (free_all(game), 1);
	if (game_load_bonus(game) == 1)
		return (free_all(game), 1);
	init_minimap(game);
	mlx_hook(game->win, 2, 1L, keys, game);
	mlx_hook(game->win, 6, 1L << 6, mouse_move, game);
	mlx_hook(game->win, 17, 0L, exit_game, game);
	mlx_mouse_move(game->gptr, game->win, game->scr_x / 2, game->scr_y / 2);
	mlx_loop_hook(game->gptr, game_loop_bonus, game);
	mlx_loop(game->gptr);
	return (0);
}
