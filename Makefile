# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/30 16:11:53 by miltavar          #+#    #+#              #
#    Updated: 2025/11/11 12:38:45 by miltavar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D
CC			= cc
CFLAGS		= -g3 -Wall -Wextra -Werror -Ilibs/libft/includes -Ilibs/ft_fprintf -Iincludes -Imlx
MLXFLAGS 	= -Lmlx -lmlx_Linux -lXext -lX11 -lm

MAKE = make -s -C

SRCS = srcs/main.c \
		srcs/game/game_init.c \
		srcs/utils/common_utils.c \
		srcs/hooks/movement.c \
		srcs/hooks/look.c \
		srcs/hooks/hooks.c \
		srcs/parsing/parsing.c \
		srcs/parsing/paths.c \
		srcs/parsing/colors.c \
		srcs/parsing/flood_fill.c \
		srcs/parsing/map.c \
		srcs/parsing/utils.c \
		srcs/parsing/player.c \
		srcs/images/pixels.c \
		srcs/images/textures.c \
		srcs/game/dda.c \
		srcs/game/dda_utils.c


BOLD = \e[1m
GRAY = \e[30m
GREEN = \e[32m
PURPLE = \e[35m
RESET = \e[0m

OBJS		= $(SRCS:.c=.o)

LIBFT_PATH	= libs/libft
LIBFT		= $(LIBFT_PATH)/libft.a

FT_FPRINTF_PATH	= libs/ft_fprintf
FT_FPRINTF		= $(FT_FPRINTF_PATH)/ft_fprintf.a

MLX_PATH 	= mlx
MLX 		= $(MLX_PATH)/libmlx_Linux.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(FT_FPRINTF) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(FT_FPRINTF) $(MLX) $(MLXFLAGS) -o $(NAME)

$(LIBFT):
	$(MAKE) $(LIBFT_PATH)

$(FT_FPRINTF):
	$(MAKE) $(FT_FPRINTF_PATH)

$(MLX):
	$(MAKE) $(MLX_PATH)

%.o: %.c includes/cub3D.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(LIBFT) $(FT_FPRINTF) $(MLX)
	$(MAKE) $(LIBFT_PATH) clean
	$(MAKE) $(FT_FPRINTF_PATH) clean
	$(MAKE) $(MLX_PATH) clean

fclean: clean
	rm -f $(NAME) $(LIBFT)
	$(MAKE) $(LIBFT_PATH) fclean
	$(MAKE) $(FT_FPRINTF_PATH) fclean
	$(MAKE) $(MLX_PATH) clean

re: fclean all

.PHONY: all clean fclean re
