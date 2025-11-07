/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 16:26:40 by miltavar          #+#    #+#             */
/*   Updated: 2025/11/04 13:04:39 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (ft_fprintf(2, "requires one argument in .cub format\n"), 1);
	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (perror(NULL), 1);
	game->ray = ft_calloc(1, sizeof(t_ray));
	if (!game->ray)
		return (perror(NULL), free(game), 1);
	if (parsing(game, argv[1]) == 1)
		return (1);
	if (game_init(game) == 1)
		return (1);
	return (0);
}
