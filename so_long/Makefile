# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/09 19:53:44 by asharafe          #+#    #+#              #
#    Updated: 2025/11/15 17:07:51 by asharafe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -I include
MLX_DIR = libraries/mlx
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

LIBFT_DIR = libraries/libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_FLAGS = -L$(LIBFT_DIR) -lft

SRC = 	src/so_long.c \
		src/mlx_init.c \
		src/map_reach_check.c \
		src/map_init.c \
		src/map_containers_check.c \
		src/load_textures.c \
		src/input_check.c \
		src/events_handle.c \
		src/error_free_exit.c 

OBJ =  $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(GNL)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) $(LIBFT_FLAGS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c $(MLX_DIR)/mlx.h
	$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re