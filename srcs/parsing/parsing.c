/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 12:31:21 by miltavar          #+#    #+#             */
/*   Updated: 2025/11/05 18:07:10 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	parsing(t_game *game, char *arg)
{
	int	fd;

	fd = open(arg, O_RDONLY);
	if (fd == -1)
		return (perror(NULL), free_all(game), 1);
	if (paths(fd, game) == 1)
		return (ft_putstr_fd("Invalid path\n", 2),
			close(fd), free_all(game), 1);
	if (colors(fd, game) == 1)
		return (ft_putstr_fd("Invalid colors\n", 2), close(fd),
			free_all(game), 1);
	if (map(fd, game) == 1)
		return (ft_putstr_fd("Invalid map\n", 2), close(fd),
			free_all(game), 1);
	1 && (close(fd), get_next_line(-42));
	if (do_flood(game) == 1)
		return (ft_putstr_fd("Invalid map\n", 2), free_all(game), 1);
	init_directions(game);
	return (0);
}
