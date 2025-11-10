/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 16:28:55 by miltavar          #+#    #+#             */
/*   Updated: 2025/11/10 17:12:10 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static int	south_img(t_game *g)
{
	g->south.img = mlx_xpm_file_to_image(g->gptr, g->path_s,
			&g->south.x, &g->south.y);
	if (!g->south.img)
		return (ft_putstr_fd("invalid map\n", 2), 1);
	if (g->south.x > 256 || g->south.y > 256)
		return (ft_putstr_fd("texture too large\n", 2), 1);
	g->south.addr = mlx_get_data_addr(g->south.img,
			&g->south.bpp, &g->south.line_len, &g->south.endian);
	if (!g->south.addr)
		return (ft_putstr_fd("failed to load addr\n", 2), 1);
	return (0);
}

static int	east_img(t_game *g)
{
	g->east.img = mlx_xpm_file_to_image(g->gptr, g->path_e,
			&g->east.x, &g->east.y);
	if (!g->east.img)
		return (ft_putstr_fd("invalid map\n", 2), 1);
	if (g->east.x > 256 || g->east.y > 256)
		return (ft_putstr_fd("texture too large\n", 2), 1);
	g->east.addr = mlx_get_data_addr(g->east.img, &g->east.bpp,
			&g->east.line_len, &g->east.endian);
	if (!g->east.addr)
		return (ft_putstr_fd("failed to load addr\n", 2), 1);
	return (0);
}

static int	west_img(t_game *g)
{
	g->west.img = mlx_xpm_file_to_image(g->gptr, g->path_w,
			&g->west.x, &g->west.y);
	if (!g->west.img)
		return (ft_putstr_fd("invalid map\n", 2), 1);
	if (g->west.x > 256 || g->west.y > 256)
		return (ft_putstr_fd("texture too large\n", 2), 1);
	g->west.addr = mlx_get_data_addr(g->west.img, &g->west.bpp,
			&g->west.line_len, &g->west.endian);
	if (!g->west.addr)
		return (ft_putstr_fd("failed to load addr\n", 2), 1);
	return (0);
}

static int	north_img(t_game *g)
{
	g->north.img = mlx_xpm_file_to_image(g->gptr, g->path_n,
			&g->north.x, &g->north.y);
	if (!g->north.img)
		return (ft_putstr_fd("invalid map\n", 2), 1);
	if (g->north.x > 256 || g->north.y > 256)
		return (ft_putstr_fd("texture too large\n", 2), 1);
	g->north.addr = mlx_get_data_addr(g->north.img, &g->north.bpp,
			&g->north.line_len, &g->north.endian);
	if (!g->north.addr)
		return (ft_putstr_fd("failed to load addr\n", 2), 1);
	return (0);
}

int	game_load(t_game *g)
{
	g->main.img = mlx_new_image(g->gptr, g->scr_x, g->scr_y);
	if (!g->main.img)
		return (1);
	g->main.addr = mlx_get_data_addr(g->main.img, &g->main.bpp,
			&g->main.line_len, &g->main.endian);
	if (!g->main.addr)
		return (ft_putstr_fd("failed to load addr\n", 2), 1);
	if (north_img(g) == 1)
		return (1);
	if (south_img(g) == 1)
		return (1);
	if (east_img(g) == 1)
		return (1);
	if (west_img(g) == 1)
		return (1);
	return (0);
}
