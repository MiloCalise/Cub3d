/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 16:28:55 by miltavar          #+#    #+#             */
/*   Updated: 2025/11/07 16:32:42 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static int	south_img(t_game *game)
{
	game->south.img = mlx_xpm_file_to_image(game->gptr, game->path_s, &game->south.x, &game->main.y);
	if (!game->south.img)
		return (ft_putstr_fd("invalid map\n", 2), 1);
	if (game->south.x > 256 || game->south.y > 256)
		return (ft_putstr_fd("texture too large\n", 2), 1);
	game->south.addr = mlx_get_data_addr(game->south.img, &game->south.bpp, &game->south.line_len, &game->south.endian);
	if (!game->south.addr)
		return (ft_putstr_fd("failed to load addr\n", 2), 1);
	return (0);
}

static int	east_img(t_game *game)
{
	game->east.img = mlx_xpm_file_to_image(game->gptr, game->path_e, &game->east.x, &game->main.y);
	if (!game->east.img)
		return (ft_putstr_fd("invalid map\n", 2), 1);
	if (game->east.x > 256 || game->east.y > 256)
		return (ft_putstr_fd("texture too large\n", 2), 1);
	game->east.addr = mlx_get_data_addr(game->east.img, &game->east.bpp, &game->east.line_len, &game->east.endian);
	if (!game->east.addr)
		return (ft_putstr_fd("failed to load addr\n", 2), 1);
	return (0);
}

static int	west_img(t_game *game)
{
	game->west.img = mlx_xpm_file_to_image(game->gptr, game->path_w, &game->west.x, &game->main.y);
	if (!game->west.img)
		return (ft_putstr_fd("invalid map\n", 2), 1);
	if (game->west.x > 256 || game->west.y > 256)
		return (ft_putstr_fd("texture too large\n", 2), 1);
	game->west.addr = mlx_get_data_addr(game->west.img, &game->west.bpp, &game->west.line_len, &game->west.endian);
	if (!game->west.addr)
		return (ft_putstr_fd("failed to load addr\n", 2), 1);
	return (0);
}

static int	north_img(t_game *game)
{
	game->north.img = mlx_xpm_file_to_image(game->gptr, game->path_n, &game->north.x, &game->main.y);
	if (!game->north.img)
		return (ft_putstr_fd("invalid map\n", 2), 1);
	if (game->north.x > 256 || game->north.y > 256)
		return (ft_putstr_fd("texture too large\n", 2), 1);
	game->north.addr = mlx_get_data_addr(game->north.img, &game->north.bpp, &game->north.line_len, &game->north.endian);
	if (!game->north.addr)
		return (ft_putstr_fd("failed to load addr\n", 2), 1);
	return (0);
}

int	game_load(t_game *game)
{
	game->main.img = mlx_new_image(game->gptr, game->scr_x, game->scr_y);
	if (!game->main.img)
		return (1);
	game->main.addr = mlx_get_data_addr(game->main.img, &game->main.bpp, &game->main.line_len, &game->main.endian);
	if (!game->main.addr)
		return (ft_putstr_fd("failed to load addr\n", 2), 1);
	if (north_img(game) == 1)
		return (1);
	if (south_img(game) == 1)
		return (1);
	if (east_img(game) == 1)
		return (1);
	if (west_img(game) == 1)
		return (1);
	return (0);
}
