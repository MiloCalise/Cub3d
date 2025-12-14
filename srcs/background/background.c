#include "cub3D.h"

static int	get_tex_color(t_tex *tex, int x, int y)
{
	char	*dst;
	int		tex_x;
	int		tex_y;

	tex_x = x & (64 - 1); 
	tex_y = y & (64 - 1);
	
	dst = tex->addr + (tex_y * tex->line_len + tex_x * (tex->bpp / 8));
	return (*(unsigned int *)dst);
}

static void	render_floor_line(t_game *g, int y, float ray_dir0[2], float ray_dir1[2])
{
	int		x;
	int		p;
	float	pos_z;
	float	row_dist;
	float	step[2];
	float	floor[2];
	int		color;
	
	p = y - g->scr_y / 2;
	pos_z = 0.5 * g->scr_y;
	row_dist = pos_z / p;
	step[0] = row_dist * (ray_dir1[0] - ray_dir0[0]) / g->scr_x;
	step[1] = row_dist * (ray_dir1[1] - ray_dir0[1]) / g->scr_x;
	floor[0] = g->ray->pos_x + row_dist * ray_dir0[0];
	floor[1] = g->ray->pos_y + row_dist * ray_dir0[1];
	x = 0;
	while (x < g->scr_x)
	{
		color = get_tex_color(&g->north, (int)(floor[0] * 64), (int)(floor[1] * 64));
		put_pixel(g, x, y, color);
		color = get_tex_color(&g->south, (int)(floor[0] * 64), (int)(floor[1] * 64)); 
		put_pixel(g, x, g->scr_y - y - 1, color);

		floor[0] += step[0];
		floor[1] += step[1];
		x++;
	}
}


void	draw_textured_background(t_game *g)
{
	int		y;
	float	ray_dir0[2];
	float	ray_dir1[2];

	ray_dir0[0] = g->ray->dir_x - g->ray->plane_x;
	ray_dir0[1] = g->ray->dir_y - g->ray->plane_y;
	ray_dir1[0] = g->ray->dir_x + g->ray->plane_x;
	ray_dir1[1] = g->ray->dir_y + g->ray->plane_y;
	y = g->scr_y / 2 + 1;
	while (y < g->scr_y)
	{
		render_floor_line(g, y, ray_dir0, ray_dir1);
		y++;
	}
}
