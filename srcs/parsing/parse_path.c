/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 18:27:21 by miltavar          #+#    #+#             */
/*   Updated: 2026/02/08 18:52:09 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	paths_dir(char delim[2], t_game *game, char *temp)
{
	if (delim[0] == 'N' && delim[1] == 'O')
	{
		if (game->path_n)
			return (1);
		game->path_n = grab_path(temp, delim);
	}
	else if (delim[0] == 'S' && delim[1] == 'O')
	{
		if (game->path_s)
			return (1);
		game->path_s = grab_path(temp, delim);
	}
	else if (delim[0] == 'W' && delim[1] == 'E')
	{
		if (game->path_w)
			return (1);
		game->path_w = grab_path(temp, delim);
	}
	else if (delim[0] == 'E' && delim[1] == 'A')
	{
		if (game->path_e)
			return (1);
		game->path_e = grab_path(temp, delim);
	}
	return (0);
}
