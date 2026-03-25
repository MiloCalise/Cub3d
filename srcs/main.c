/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 16:26:40 by miltavar          #+#    #+#             */
/*   Updated: 2026/01/21 13:23:12 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 3 && argc != 2)
		return (ft_fprintf(2, "requires one argument in .cub format\n"), 1);
	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (perror(NULL), 1);
	game->ray = ft_calloc(1, sizeof(t_ray));
	if (!game->ray)
		return (perror(NULL), free(game), 1);
	game->shoot = ft_calloc(1, sizeof(t_proj));
	if (!game->shoot)
		return (perror(NULL), free(game), 1);
	if (parsing(game, argv[1]) == 1)
		return (1);
	if (argv[2] && ft_strncmp(argv[2], "--bonus", 7) == 0)
		if (game_init_bonus(game) == 1)
			return (free(game), 1);
	else
		if (game_init(game) == 1)
			return (1);
	return (0);
}
