/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:04:08 by miltavar          #+#    #+#             */
/*   Updated: 2025/12/15 16:30:20 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

char	*grab_path(char *str, char *to_find)
{
	char	*res;
	size_t	len;
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	skip_whitespaces(str, &i);
	if (ft_strncmp(str + i, to_find, 2) != 0)
		return (NULL);
	i += 2;
	skip_whitespaces(str, &i);
	len = ft_strlen(str + i);
	res = ft_calloc(len, sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcpy(res, str + i, len);
	return (res);
}

int	paths(int fd, t_game *game)
{
	char	*temp;

	temp = get_next_line(fd);
	skip_space(fd, &temp);
	if (!temp)
		return (get_next_line(-42), 1);
	game->path_n = grab_path(temp, "NO");
	free(temp);
	temp = get_next_line(fd);
	skip_space(fd, &temp);
	if (!temp)
		return (get_next_line(-42), 1);
	game->path_s = grab_path(temp, "SO");
	free(temp);
	temp = get_next_line(fd);
	skip_space(fd, &temp);
	if (!temp)
		return (get_next_line(-42), 1);
	game->path_w = grab_path(temp, "WE");
	free(temp);
	temp = get_next_line(fd);
	skip_space(fd, &temp);
	if (!temp)
		return (get_next_line(-42), 1);
	game->path_e = grab_path(temp, "EA");
	free(temp);
	if (!game->path_n || !game->path_s || !game->path_e || !game->path_w)
		return (get_next_line(-42), 1);
	return (0);
}
