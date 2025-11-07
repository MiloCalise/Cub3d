/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:04:08 by miltavar          #+#    #+#             */
/*   Updated: 2025/11/04 16:14:35 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

char	*grab_path(char *str, char *to_find)
{
	char	*res;
	size_t	len;

	if (ft_strncmp(str, to_find, 3) != 0)
		return (NULL);
	len = ft_strlen(str + 3);
	res = ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcpy(res, str + 3, len);
	return (res);
}

int	paths(int fd, t_game *game)
{
	char	*temp;

	temp = get_next_line(fd);
	if (!temp)
		return (get_next_line(-42), 1);
	game->path_n = grab_path(temp, "NO ");
	free(temp);
	temp = get_next_line(fd);
	if (!temp)
		return (get_next_line(-42), 1);
	game->path_s = grab_path(temp, "SO ");
	free(temp);
	temp = get_next_line(fd);
	if (!temp)
		return (get_next_line(-42), 1);
	game->path_w = grab_path(temp, "WE ");
	free(temp);
	temp = get_next_line(fd);
	if (!temp)
		return (get_next_line(-42), 1);
	game->path_e = grab_path(temp, "EA ");
	free(temp);
	if (!game->path_n || !game->path_s || !game->path_e || !game->path_w)
		return (get_next_line(-42), 1);
	return (0);
}
