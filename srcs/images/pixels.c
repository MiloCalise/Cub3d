/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:35:48 by miltavar          #+#    #+#             */
/*   Updated: 2025/11/10 12:39:25 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	put_pixel(t_game *game, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= game->scr_x || y < 0 || y >= game->scr_y)
		return ;
	dst = game->main.addr + (y * game->main.line_len
			+ x * (game->main.bpp / 8));
	*(unsigned int *)dst = color;
}
