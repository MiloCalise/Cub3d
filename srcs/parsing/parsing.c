/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 12:31:21 by miltavar          #+#    #+#             */
/*   Updated: 2026/02/14 11:26:04 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	parse_delim(char delim[2], t_game *game, char *temp)
{
	static int	i = 0;
	static int	y = 0;

	if (delim[0] == 'F')
	{
		if (i > 0 || grab_colors(game->f_clr, temp, delim))
			return (1);
		game->floor_clr = (game->f_clr[0] << 16)
			| (game->f_clr[1] << 8) | game->f_clr[2];
		return (i++, 0);
	}
	else if (delim[0] == 'C')
	{
		if (y > 0 || grab_colors(game->t_clr, temp, delim))
			return (1);
		game->top_clr = (game->t_clr[0] << 16)
			| (game->t_clr[1] << 8) | game->t_clr[2];
		return (y++, 0);
	}
	else if (!paths_dir(delim, game, temp))
		return (0);
	else
		return (1);
	return (1);
}

int	distributor(t_game *game)
{
	char	*temp;
	char	delim[2];
	int		i;
	int		count;

	count = 0;
	1 && (temp = get_next_line(game->map_fd),
		skip_space(game->map_fd, &temp), 0);
	if (!temp)
		return (get_next_line(-42), 1);
	while (temp && count < 6)
	{
		1 && (i = 0, count++, skip_whitespaces(temp, &i),
			delim[0] = temp[i], i++);
		if (!temp[i])
			return (get_next_line(-42), free(temp), 1);
		delim[1] = temp[i];
		if (parse_delim(delim, game, temp))
			return (get_next_line(-42), free(temp), 1);
		free(temp);
		if (count != 6)
			1 && (temp = get_next_line(game->map_fd),
				skip_space(game->map_fd, &temp), 0);
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

int	check_colors(t_game *game)
{
	if (game->top_clr == -1)
		return (1);
	if (game->floor_clr == -1)
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
	if (check_colors(game))
		return (ft_putstr_fd("Invalid map\n", 2), close(game->map_fd),
			free_all(game), 1);
	if (map(game) == 1)
		return (ft_putstr_fd("Invalid map\n", 2), close(game->map_fd),
			free_all(game), 1);
	1 && (close(game->map_fd), get_next_line(-42));
	if (do_flood(game) == 1)
		return (ft_putstr_fd("Invalid map\n", 2), free_all(game), 1);
	init_directions(game);
	return (0);
}
