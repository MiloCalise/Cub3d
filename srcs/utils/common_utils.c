/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 11:41:57 by miltavar          #+#    #+#             */
/*   Updated: 2025/11/06 13:07:58 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	free_paths(t_game *game)
{
	if (game->path_n)
		free(game->path_n);
	if (game->path_s)
		free(game->path_s);
	if (game->path_e)
		free(game->path_e);
	if (game->path_w)
		free(game->path_w);
}

static void	clean_images(t_game *game)
{
	if (game->east.img)
		mlx_destroy_image(game->gptr, game->east.img);
	if (game->west.img)
		mlx_destroy_image(game->gptr, game->west.img);
	if (game->south.img)
		mlx_destroy_image(game->gptr, game->south.img);
	if (game->north.img)
		mlx_destroy_image(game->gptr, game->north.img);
	if (game->main.img)
		mlx_destroy_image(game->gptr, game->main.img);
}

void	free_all(t_game *game)
{
	if (!game)
		return ;
	clean_images(game);
	if (game->win)
		mlx_destroy_window(game->gptr, game->win);
	if (game->gptr)
	{
		mlx_destroy_display(game->gptr);
		free(game->gptr);
	}
	free_paths(game);
	free_split(game->map);
	free(game->ray);
	free(game);
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		if (split[i])
			free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
}
