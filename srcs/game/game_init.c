/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 12:04:11 by miltavar          #+#    #+#             */
/*   Updated: 2025/11/10 17:11:50 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

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
	dda(game);
	mlx_hook(game->win, 2, 1L, keys, game);
	mlx_hook(game->win, 17, 0L, exit_game, game);
	mlx_loop(game->gptr);
	return (0);
}
