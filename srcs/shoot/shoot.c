/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 18:27:21 by molapoug          #+#    #+#             */
/*   Updated: 2026/03/07 12:24:01 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void shoot_projectile(t_game *game)
{
    if (game->shoot->active)
        return;

    game->shoot->x = game->ray->pos_x; 
    game->shoot->y = game->ray->pos_y;
    game->shoot->dir_x = game->ray->dir_x;
    game->shoot->dir_y = game->ray->dir_y;
    game->shoot->speed = 0.4;
    game->shoot->active = 1;
}

void update_projectile(t_game *game)
{
    if (!game->shoot->active)
        return ;

    double new_x = game->shoot->x + game->shoot->dir_x * game->shoot->speed;
    double new_y = game->shoot->y + game->shoot->dir_y * game->shoot->speed;

    if (game->map[(int)new_y][(int)new_x] == '1')
    {
        game->shoot->active = 0;
        free(game);
        return ;
    }

    game->shoot->x = new_x;
    game->shoot->y = new_y;
}

void draw_projectile(t_game *game)
{

	int i;
	int	j;
    int size;
    int start_x;
    int start_y;
    int color;

	i = 0;
    if (!game->shoot->active)
        return ;
    game->shoot->dir_x = game->shoot->x - game->ray->pos_x;
    game->shoot->dir_y= game->shoot->y - game->ray->pos_y;
    game->shoot->dist = sqrt(game->shoot->dir_x * game->shoot->dir_x + game->shoot->dir_y * game->shoot->dir_y);
    if (game->shoot->dist < 0.1 || game->shoot->dist > 100)
		return ;
    size = (int)(game->scr_y / game->shoot->dist);
    start_x = (game->scr_x / 2) - (size / 4);
    start_y = (game->scr_y / 2) - (size / 4);
    while (i < size / 2)
	{
		j = 0;
        while(j < size / 2)
		{
            color = (unsigned int )(game->shoot->tex.addr + game->ray->text_y * game->shoot->tex.line_len + game->ray->text_x * (game->shoot->tex.bpp / 8));
            put_pixel(game, start_x + i, start_y + j, 0xFF0000);
			j++;
		}
		i++;
	}
}
