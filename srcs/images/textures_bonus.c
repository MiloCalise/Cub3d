/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:35:48 by molapoug          #+#    #+#             */
/*   Updated: 2025/12/13 21:53:47 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	load_xpm(t_game *g, t_tex *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(g->gptr, path, &tex->x, &tex->y);
	if (!tex->img)
	{
		printf("Error\nCannot load texture: %s\n", path);
		exit_game(g);
	}
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp,\
		&tex->line_len, &tex->endian);
}

void	load_textures(t_game *g)
{
	load_xpm(g, &g->floor, "./ressources/floor.xpm");
	load_xpm(g, &g->ciel, "./ressources/sky.xpm");
}
