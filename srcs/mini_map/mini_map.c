#include "cub3D.h"

/*
** Dessine un carré plein (pour les murs ou le joueur)
** Respecte les limites de l'écran via put_pixel
*/
static void	draw_mm_square(t_game *g, int x, int y, int color)
{
	int	i;
	int	j;
	int	size;

	size = g->ray->minimap_scale;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			put_pixel(g, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

/*
** Dessine le joueur sur la minimap.
** La position est convertie de coordonnées monde (double) en pixels.
*/
static void	draw_mm_player(t_game *g, int margin)
{
	int	pos_x;
	int	pos_y;
	int	scale;

	scale = g->ray->minimap_scale;
	pos_x = (int)(g->ray->pos_x * scale) + margin;
	pos_y = (int)(g->ray->pos_y * scale) + margin;
	draw_mm_square(g, pos_x - (scale / 4), pos_y - (scale / 4), 0xFF0000);
}

/*
** Parcourt la grille de la map (char **) et dessine les murs.
** 0x808080 = Gris pour les murs
** 0x000000 = Noir (ou transparent) pour le sol
*/
static void	draw_mm_grid(t_game *g, int margin, int scale)
{
	int	x;
	int	y;
	int	color_wall;

	color_wall = 0x808080;
	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			if (g->map[y][x] == '1')
				draw_mm_square(g, (x * scale) + margin, \
					(y * scale) + margin, color_wall);
			else if (g->map[y][x] == '0' || ft_strchr("NSWE", g->map[y][x]))
				draw_mm_square(g, (x * scale) + margin, \
					(y * scale) + margin, 0x202020);
			x++;
		}
		y++;
	}
}

void	draw_minimap(t_game *g)
{
	if (!g->ray->minimap_on)
		return ;
	if (g->ray->minimap_scale <= 0)
		g->ray->minimap_scale = 10;
	if (g->ray->minimap_margin <= 0)
		g->ray->minimap_margin = 20;
	draw_mm_grid(g, g->ray->minimap_margin, g->ray->minimap_scale);
	draw_mm_player(g, g->ray->minimap_margin);
}