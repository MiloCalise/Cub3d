#include "cub3D.h"

/*
** Dessine le joueur (point rouge) au centre du radar
*/
static void	draw_player_icon(t_game *g, int c_x, int c_y)
{
	int	i;
	int	j;

	i = -2;
	while (i <= 2)
	{
		j = -2;
		while (j <= 2)
		{
			put_pixel(g, c_x + j, c_y + i, 0xFF0000);
			j++;
		}
		i++;
	}
}

// affiche la couleur du bloc dans la position du Monde en "w_x" et "w_y"
// si on sort de la map on va afficher du NOIR (0x000000), si tu veux changer les couleurs je t'ai mis le code couleur
// quand on crois un mur -> GRIS CLAIR (0x808080)
// quand c'est le sol -> GRIS FONCÉ (0x303030)
int	get_radar_color(t_game *g, double w_x, double w_y)
{
	int	mx;
	int	my;

	mx = (int)w_x;
	my = (int)w_y;
	if (my < 0 || my >= g->map_size)
		return (0x000000);
	if (mx < 0 || !g->map[my] || mx >= (int)ft_strlen(g->map[my]))
		return (0x000000);
	if (g->map[my][mx] == '1')
		return (0x808080);
	if (g->map[my][mx] == '0' || ft_strchr("NSWE", g->map[my][mx]))
		return (0x303030);
	return (0x000000);
}

// j'ai dessiner un cercle pour la map
// IMPORTANT : On réinitialise x a -r a chaque itération de y
// ca évitera les "overflows" noir sur la map, car on doit render la
// mini_map à chaque udate de la position du joueur avec :
// IMPORTANT : x = -r
void	draw_radar_circle(t_game *g, int r, int cx, int cy)
{
	int		x;
	int		y;
	int		dist_sq;
	double	src[2];

	y = -r - 1;
	while (++y <= r)
	{
		x = -r;
		while (x <= r)
		{
			dist_sq = x * x + y * y;
			if (dist_sq < r * r)
			{
				src[0] = g->ray->pos_x + (double)x / g->ray->minimap_scale;
				src[1] = g->ray->pos_y + (double)y / g->ray->minimap_scale;
				if (dist_sq > (r - 2) * (r - 2))
					put_pixel(g, cx + x, cy + y, 0xFFFFFF);
				else
					put_pixel(g, cx + x, cy + y, \
						get_radar_color(g, src[0], src[1]));
			}
			x++;
		}
	}
}

void	draw_minimap(t_game *g)
{
	int	radius;
	int	center_x;
	int	center_y;

	if (!g->ray->minimap_on)
		return ;
	if (g->ray->minimap_scale <= 0)
		g->ray->minimap_scale = 10;
	radius = 75;
	center_x = 20 + radius;
	center_y = 20 + radius;
	draw_radar_circle(g, radius, center_x, center_y);
	draw_player_icon(g, center_x, center_y);
}