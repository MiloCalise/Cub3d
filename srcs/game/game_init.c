/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 12:04:11 by miltavar          #+#    #+#             */
/*   Updated: 2025/12/15 13:44:17 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

// meilleure gestion des fps, comme ca si on a juste besoin
// d'afficher les fps dans un autre truc on a juste à importer
// cette fonction ailleur, et ca nous permet d'avoir un code
// plus modulable
void	calc_fps(t_game *g)
{
	char	*fps;

	if (g->frame_time > 0.0001)
		g->fps = (int)(1.0 / g->frame_time);
	else
		g->fps = 0;
	fps = ft_itoa(g->fps);
	if (!fps)
		return ;
	mlx_string_put(g->gptr, g->win, 10, 20, 0xFFFFFF, fps);
	free(fps);
}

int	game_loop(t_game *g)
{
	double	current_time;

	gettimeofday(&g->time, NULL);
	current_time = g->time.tv_sec + g->time.tv_usec / 1000000.0;
	g->frame_time = current_time - g->old_time;
	g->old_time = current_time;
	//draw_textured_background(g);
	dda(g);
	//draw_minimap(g);
	mlx_put_image_to_window(g->gptr, g->win, g->main.img, 0, 0);
	calc_fps(g);
	return (0);
}

// initialisation des variables pour la map en 2D
void	init_minimap(t_game *game)
{
	game->ray->minimap_on = 1;
	game->ray->minimap_scale = 10;
	game->ray->minimap_margin = 10;
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
	init_minimap(game);
	mlx_hook(game->win, 2, 1L, keys, game);
	mlx_hook(game->win, 17, 0L, exit_game, game);
	mlx_loop_hook(game->gptr, game_loop, game);
	mlx_loop(game->gptr);
	return (0);
}
