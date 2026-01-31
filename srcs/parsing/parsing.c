/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 12:31:21 by miltavar          #+#    #+#             */
/*   Updated: 2026/01/31 16:01:50 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	parse_delim(char delim[2], t_game *game, char *temp)
{
	if (delim[0] == 'N' && delim[1] == 'O')
		game->path_n = grab_path(temp, delim);
	else if (delim[0] == 'S' && delim[1] == 'O')
		game->path_s = grab_path(temp, delim);
	else if (delim[0] == 'W' && delim[1] == 'E')
		game->path_w = grab_path(temp, delim);
	else if (delim[0] == 'E' && delim[1] == 'A')
		game->path_e = grab_path(temp, delim);
	else if (delim[0] == 'F' && (delim[1] == ' ' || delim[1] == '\t'))
	{
		if (grab_colors(game->f_clr, temp, delim))
			return (1);
		game->floor_clr = (game->f_clr[0] << 16)
			| (game->f_clr[1] << 8) | game->f_clr[2];
	}
	else if (delim[0] == 'C' && (delim[1] == ' ' || delim[1] == '\t'))
	{
		if (grab_colors(game->t_clr, temp, delim))
			return (1);
		game->top_clr = (game->t_clr[0] << 16)
			| (game->t_clr[1] << 8) | game->t_clr[2];
	}
	else
		return (1);
	return (0);
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
	if (game->top_clr == 0)
		return (1);
	if (game->floor_clr == 0)
		return (1);
	return (0);
}

int	parsing(t_game *game, char *arg)
{
	if (check_name(arg))
		return (ft_putstr_fd("Invalid map type\n", 2), free_all(game), 1);
	game->top_clr = 0;
	game->floor_clr = 0;
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
