/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:07:11 by miltavar          #+#    #+#             */
/*   Updated: 2025/11/11 12:35:25 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	check_line(char *s, int index, int max, t_game *game)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (index == 0 || index == max)
		{
			if (s[i] != '1' && !is_whitespace(s[i]))
				return (1);
		}
		else
		{
			if (s[i] != '1' && !is_whitespace(s[i]) && s[i] != '0'
				&& s[i] != 'N' && s[i] != 'S' && s[i] != 'E' && s[i] != 'W')
				return (1);
			if (s[i] == 'N' || s[i] == 'S' || s[i] == 'W' || s[i] == 'E')
				1 && (game->player_x = i, game->player_y = index);
		}
		i++;
	}
	return (0);
}

int	copy_map(char **copy, t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		copy[i] = ft_strdup(game->map[i]);
		if (!copy[i])
			return (perror(NULL), free_split(copy), 1);
		i++;
	}
	copy[i] = NULL;
	return (0);
}

int	map_check(t_game *game)
{
	int	i;

	i = 0;
	game->player_x = -1;
	while (game->map[i])
	{
		if (check_line(game->map[i], i, game->map_size, game) == 1)
			return (1);
		i++;
	}
	if (game->player_x == -1)
		return (1);
	game->ray->pos_x = (double)game->player_x;
	game->ray->pos_y = (double)game->player_y;
	return (0);
}

int	do_flood(t_game *game)
{
	char	**copy;

	if (map_check(game) == 1)
		return (1);
	copy = ft_calloc(game->map_size + 1, sizeof(char *));
	if (!copy)
		return (perror(NULL), 1);
	if (copy_map(copy, game) == 1)
		return (1);
	flood_fill(game, game->player_x, game->player_y, copy);
	if (game->player_x == -1)
		return (free_split(copy), 1);
	return (free_split(copy), 0);
}

int	map(int fd, t_game *game)
{
	char		*temp;
	int			i;
	size_t		len;

	i = 0;
	game->map = ft_calloc(100, sizeof(char *));
	if (!game)
		return (perror(NULL), 1);
	1 && (game->map_size = 0, temp = get_next_line(fd));
	temp = skip_space(fd, temp);
	while (temp && i < 100)
	{
		len = ft_strlen(temp);
		game->map[i] = ft_calloc(len, sizeof(char));
		if (!game->map[i])
			return (get_next_line(-42), free(temp),
				free_split(game->map), 1);
		1 && (ft_strlcpy(game->map[i], temp, len),
			free(temp), i++, temp = get_next_line(fd), game->map_size++);
	}
	if (i >= 100 || i == 0)
		return (free_split(game->map), get_next_line(-42), 1);
	return (game->map[i] = NULL, 0);
}
