/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:07:11 by miltavar          #+#    #+#             */
/*   Updated: 2026/02/09 16:19:42 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	check_line(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((i == 0) && (s[i] != '1' && !is_whitespace(s[i])))
			return (1);
		if (s[i] != '1' && !is_whitespace(s[i]) && s[i] != '0'
			&& s[i] != 'N' && s[i] != 'S' && s[i] != 'E' && s[i] != 'W')
			return (1);
		i++;
	}
	return (0);
}

int	copy_map(char **copy, t_game *game)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	copy[i] = fill(game);
	if (!copy[i])
		return (1);
	i++;
	while (game->map[y])
	{
		copy[i] = ft_calloc(game->max_len + 1, sizeof(char));
		if (!copy[i])
			return (1);
		fill_line(copy[i], game, y);
		y++;
		i++;
	}
	copy[i] = fill(game);
	if (!copy[i])
		return (1);
	i++;
	copy[i] = NULL;
	return (0);
}

int	map_check(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		if (all_whitespace(game->map[i]) == 1)
			return (1);
		if (check_line(game->map[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}


void  check_map_flood(t_game *game, char **copy)
{
  int i;
  int j;

  i = 1;
  while (i < game->map_size)
  {
    j = 0;
    while (j < game->max_len)
    {
      if (copy[i][j] == '0' || copy[i][j] == 'N' || copy[i][j] == 'S'
          || copy[i][j] == 'E' || copy[i][j] == 'W')
        game->player_x = -1;
      j++;
    }
    i++;
  }
}

int	do_flood(t_game *game)
{
	char	**copy;

	if (map_check(game) == 1)
		return (1);
	if (check_dup(game) == 1)
		return (1);
	copy = ft_calloc(game->map_size + 3, sizeof(char *));
	if (!copy)
		return (perror(NULL), 1);
	get_max(game);
	if (copy_map(copy, game) == 1)
		return (free_split(copy), 1);
	flood_fill(game, game->player_x, game->player_y, copy);
	for (int i = 0; i < game->map_size + 2; i++)
		printf("%s\n", copy[i]);
	/*for (int i = 1; i <= game->map_size; i++)
	{
		for (int j = 0; j < game->max_len; j++)
		{
			if (copy[i][j] == '0' || copy[i][j] == 'N' || copy[i][j] == 'S'
				|| copy[i][j] == 'E' || copy[i][j] == 'W')
				game->player_x = -1;
		}
	}*/
  check_map_flood(game, copy);
	if (game->player_x == -1)
		return (free_split(copy), 1);
	return (free_split(copy), 0);
}

int	map(t_game *g)
{
	char		*temp;
	int			i;
	size_t		len;

	1 && (i = 0, g->map = ft_calloc(100, sizeof(char *)));
	if (!g)
		return (perror(NULL), 1);
	1 && (g->map_size = 0, temp = get_next_line(g->map_fd));
	skip_space(g->map_fd, &temp);
	while (temp && i < 100)
	{
		1 && (len = ft_strlen(temp), g->map[i] = ft_calloc(len, sizeof(char)));
		if (!g->map[i])
			return (get_next_line(-42), free(temp), free_split(g->map), 1);
		1 && (ft_strlcpy(g->map[i], temp, len),
			free(temp), i++,
			temp = get_next_line(g->map_fd), g->map_size++);
	}
	if (i >= 100 || i == 0)
	{
		if (i >= 100)
			return (free_split(g->map), get_next_line(-42), 1);
		return (get_next_line(-42), 1);
	}
	return (g->map[i] = NULL, 0);
}
