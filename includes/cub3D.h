/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 16:23:18 by miltavar          #+#    #+#             */
/*   Updated: 2026/01/31 16:25:43 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/libft/libft.h"
# include "../libs/ft_fprintf/ft_fprintf.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"

# include <stdio.h>
# include <math.h>
# include <errno.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>
# include <sys/time.h>

typedef struct s_bg
{
	int		x;
	int		p;
	int		color;
	float	pos_z;
	float	row_dist;
	float	step[2];
	float	floor[2];
}			t_bg;

typedef struct s_tex
{
	void			*img;
	char			*addr;
	int				endian;
	int				bpp;
	int				line_len;
	int				x;
	int				y;
}					t_tex;

typedef struct s_ray
{
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				text_x;
	int				text_y;

	double			pos_x;
	double			pos_y;
	double			ray_dir_x;
	double			ray_dir_y;
	double			dir_x;
	double			dir_y;
	double			dist_x;
	double			dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			side_dist_x;
	double			side_dist_y;
	double			plane_x;
	double			plane_y;
	double			camera_x;
	double			wall_dist;
	double			wall_x;
	double			step;
	double			texpos;

	float			pos_z;
	float			row_dist;
	float			floor[2];

	int				minimap_on;
	int				minimap_scale;
	int				minimap_margin;

}					t_ray;

typedef struct s_game
{
	struct timeval	time;

	char			*path_n;
	char			*path_s;
	char			*path_w;
	char			*path_e;

	int				floor_clr;
	int				top_clr;
	int				t_clr[3];
	int				f_clr[3];
	int				scr_x;
	int				scr_y;
	int				map_size;
	int				line_len;
	int				player_x;
	int				player_y;
	int				fps;
	int				color;
	int				map_fd;

	double			coll_margin;
	double			move_speed;
	double			rot_speed;
	double			frame_time;
	double			old_time;

	char			**map;

	void			*gptr;
	void			*win;

	t_tex			north;
	t_tex			south;
	t_tex			east;
	t_tex			west;
	t_tex			main;

	t_tex			floor;
	t_tex			ciel;
	float			ray_dir0[2];
	float			ray_dir1[2];

	t_ray			*ray;

}					t_game;

/* parsing */

void	skip_whitespaces(char *s, int *i);
void	skip_space(int fd, char **temp);
void	flood_fill(t_game *game, int x, int y, char **copy);
void	init_directions(t_game *game);

int		parsing(t_game *game, char *arg);
int		check_dup(char **copy, t_game *game);
int		map(t_game *game);
int		do_flood(t_game *game);
int		is_invalid(char c);
int		grab_colors(int tab[3], char *str, char *tofind);
int		return_split(t_game *game, int i);

char	*grab_path(char *str, char *to_find);

/* game */

int		game_init(t_game *game);
int		game_load(t_game *game);
int		game_loop(t_game *g);

/* game bonus */
int		game_loop_bonus(t_game *g);
int		game_init_bonus(t_game *game);

void	init_minimap(t_game *game);
void	calc_fps(t_game *g);
void	dda_bonus(t_game *g);
void	pixel_loop_bonus(t_game *g, t_tex *tex, int *color, int x);
void	draw_minimap(t_game *g);
void	dda(t_game *game);
void	put_pixel(t_game *game, int x, int y, int color);
void	step_calc(t_game *game, t_tex *tex);
void	pixel_loop(t_game *game, t_tex *tex, int *color, int x);
void	draw_textured_background(t_game *g);
void	load_textures(t_game *g);

t_tex	*wall_select(t_game *game);

/* dda */
void	ray_direction(t_game *g, int x);
void	ray_direction2(t_game *g);
void	hit_loop(t_game *g);
void	wall_calc(t_game *g);

/* textures */
int		south_img(t_game *g);
int		east_img(t_game *g);
int		west_img(t_game *g);
int		north_img(t_game *g);

/* movement */

void	move_forward(t_game *game);
void	move_backward(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	rotate_right(t_game *g, double angle);
void	rotate_left(t_game *g, double angle);

/* hooks */

int		exit_game(t_game *game);
int		keys(int keycode, t_game *game);

/* utils */

void	free_all(t_game *game);
void	free_split(char **split);

int		is_whitespace(char c);

#endif
