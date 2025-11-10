/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 16:23:18 by miltavar          #+#    #+#             */
/*   Updated: 2025/11/10 17:08:17 by miltavar         ###   ########.fr       */
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

typedef struct s_tex
{
	void	*img;
	char	*addr;
	int		endian;
	int		bpp;
	int		line_len;
	int		x;
	int		y;
}			t_tex;

typedef struct s_ray
{
	int		mapX;
	int		mapY;
	int		stepY;
	int		stepX;
	int		side;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	int		textX;
	int		textY;

	double	posX;
	double	posY;
	double	ray_dirX;
	double	ray_dirY;
	double	dirX;
	double	dirY;
	double	distX;
	double	distY;
	double	delta_distX;
	double	delta_distY;
	double	side_distX;
	double	side_distY;
	double	planeX;
	double	planeY;
	double	cameraX;
	double	WallDist;
	double	wallX;
	double	step;
	double	texpos;

}			t_ray;

typedef struct s_game
{
	char	*path_n;
	char	*path_s;
	char	*path_w;
	char	*path_e;

	int		floor_clr;
	int		top_clr;
	int		scr_x;
	int		scr_y;
	int		map_size;
	int		player_x;
	int		player_y;

	double	coll_margin;
	double	move_speed;
	double	rot_speed;

	char	**map;

	void	*gptr;
	void	*win;

	t_tex	north;
	t_tex	south;
	t_tex	east;
	t_tex	west;
	t_tex	main;

	t_ray	*ray;

}			t_game;

/* parsing */

char	*skip_space(int fd, char *temp);
void	flood_fill(t_game *game, int x, int y, char **copy);
void	init_directions(t_game *game);

int		parsing(t_game *game, char *arg);
int		paths(int fd, t_game *game);
int		colors(int fd, t_game *game);
int		map(int fd, t_game *game);
int		do_flood(t_game *game);
int		is_invalid(char c);

/* game */

int		game_init(t_game *game);
int		game_load(t_game *game);
int		game_loop(t_game *g);

void	dda(t_game *game);
void	put_pixel(t_game *game, int x, int y, int color);
void	step_calc(t_game *game, t_tex *tex);
void	pixel_loop(t_game *game, t_tex *tex, int *color, int x);

t_tex	*wall_select(t_game *game);

/* movement */

void	move_forward(t_game *game);
void	move_backward(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	look_left(t_game *game);
void	look_right(t_game *game);

/* hooks */

int		exit_game(t_game *game);
int		keys(int keycode, t_game *game);

/* utils */

void	free_all(t_game *game);
void	free_split(char **split);

int		is_whitespace(char c);

#endif
