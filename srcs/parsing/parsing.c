/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 12:31:21 by miltavar          #+#    #+#             */
/*   Updated: 2026/02/16 12:23:09 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	parse_delim(char delim[2], t_game *game)
{
	static int	i = 0;
	static int	y = 0;

	if (delim[0] == 'F')
	{
		if (i > 0 || grab_colors(game->f_clr, game->gnl, delim))
			return (1);
		game->floor_clr = (game->f_clr[0] << 16)
			| (game->f_clr[1] << 8) | game->f_clr[2];
		return (i++, 0);
	}
	else if (delim[0] == 'C')
	{
		if (y > 0 || grab_colors(game->t_clr, game->gnl, delim))
			return (1);
		game->top_clr = (game->t_clr[0] << 16)
			| (game->t_clr[1] << 8) | game->t_clr[2];
		return (y++, 0);
	}
	else if (!paths_dir(delim, game, game->gnl))
		return (0);
	else
		return (1);
	return (1);
}

static int	check_mapargs(t_game *game)
{
	if (!game->path_e || !game->path_n || !game->path_s || !game->path_w)
		return (1);
	if (!*game->path_e || !*game->path_n || !*game->path_s || !*game->path_w)
		return (1);
	if (game->top_clr == -1)
		return (1);
	if (game->floor_clr == -1)
		return (1);
	return (0);
}

int	distributor(t_game *game)
{
	char	delim[2];
	int		i;

	1 && (game->gnl = get_next_line(game->map_fd),
		skip_space(game->map_fd, &game->gnl), 0);
	if (!game->gnl)
		return (get_next_line(-42), 1);
	while (game->gnl && check_mapargs(game))
	{
		1 && (i = 0, skip_whitespaces(game->gnl, &i),
			delim[0] = game->gnl[i], i++);
		if (!game->gnl[i])
			return (get_next_line(-42), free(game->gnl), 1);
		delim[1] = game->gnl[i];
		if (parse_delim(delim, game))
			return (get_next_line(-42), free(game->gnl), 1);
		free(game->gnl);
		1 && (game->gnl = get_next_line(game->map_fd),
			skip_space(game->map_fd, &game->gnl), 0);
	}
	return (0);
}

int	check_name(char *arg)
{
	int	i;

	i = ft_strlen(arg);
	i--;
	if (i < 0 || arg[i] != 'b')
		return (1);
	i--;
	if (i < 0 || arg[i] != 'u')
		return (1);
	i--;
	if (i < 0 || arg[i] != 'c')
		return (1);
	i--;
	if (i < 0 || arg[i] != '.')
		return (1);
	i--;
	if (i < 0 || arg[i] == '/')
		return (1);
	return (0);
}

int	parsing(t_game *game, char *arg)
{
	if (check_name(arg))
		return (ft_putstr_fd("Invalid map type\n", 2), free_all(game), 1);
	game->top_clr = -1;
	game->floor_clr = -1;
	game->map_fd = open(arg, O_RDONLY);
	if (game->map_fd == -1)
		return (perror(NULL), free_all(game), 1);
	if (distributor(game))
		return (ft_putstr_fd("Invalid map\n", 2), close(game->map_fd),
			free_all(game), 1);
	if (map(game) == 1)
		return (ft_putstr_fd("Invalid map\n", 2), close(game->map_fd),
			free_all(game), 1);
	1 && (close(game->map_fd), get_next_line(-42));
	if (check_mapargs(game))
		return (ft_putstr_fd("Invalid map\n", 2), free_all(game), 1);
	if (do_flood(game) == 1)
		return (ft_putstr_fd("Invalid map\n", 2), free_all(game), 1);
	init_directions(game);
	return (0);
}
