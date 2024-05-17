# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/27 14:34:20 by tfiguero          #+#    #+#              #
#    Updated: 2024/05/17 17:42:42 by tfiguero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D
INC_DIR		= inc
LIB_DIR		= inc
MKFL		= Makefile
INIT_DIR	= init/
MOV_DIR		= movement/
PARSE_DIR	= parse/
RENDER_DIR	= render/
UTILS_DIR	= utils/
SRC_DIR		= srcs/
OBJ_DIR		= objs/

MLX			= libmlx.a

INC_MLX		= mlx.h

MLX_DIR		= inc/mlx
	MLX_FLAGS	= -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
	# MLX_FLAGS	= -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -I$(MLX_DIR) -lXext -lX11 -lm
	MLX_CC		= -I/usr/include -I$(MLX_DIR)
	LIB_M 		= $(LIB_DIR)/mlx/
	
# ----Libraries----
PW_HEADER	= $(INC_DIR)/cub3D.h
LIB			= $(LIB_DIR)/libft/libft.a
LIB_L 		= $(LIB_DIR)/libft/
# -------------
RM = rm -rf
MP = mkdir -p
CFLAGS = -g -Wall -Wextra -Werror #-fsanitize=address
LIBC = ar -rcs
CC = clang
# =============

SRC_L	=	main.c												\

SRC_L +=	$(addprefix $(INIT_DIR), init_data.c)				\
			$(addprefix $(INIT_DIR), init_mlx.c)				\
			$(addprefix $(MOV_DIR), input_handler.c)			\
			$(addprefix $(MOV_DIR), player_direction.c)			\
			$(addprefix $(MOV_DIR), player_movement.c)			\
			$(addprefix $(MOV_DIR), player_position.c)			\
			$(addprefix $(MOV_DIR), player_rotate.c)			\
			$(addprefix $(PARSE_DIR), parse_info.c)				\
			$(addprefix $(PARSE_DIR), parse_info2.c)			\
			$(addprefix $(PARSE_DIR), parse_map.c)				\
			$(addprefix $(PARSE_DIR), parse_map2.c)				\
			$(addprefix $(PARSE_DIR), parse_textures.c)			\
			$(addprefix $(RENDER_DIR), raycast.c)				\
			$(addprefix $(RENDER_DIR), render.c)				\
			$(addprefix $(RENDER_DIR), textures.c)				\
			$(addprefix $(UTILS_DIR), errors.c)					\
			$(addprefix $(UTILS_DIR), print_utils.c)			\
			$(addprefix $(UTILS_DIR), utils_line.c)				\
			$(addprefix $(UTILS_DIR), utils_tabs.c)				\
			$(addprefix $(UTILS_DIR), get_next_line.c)			\
			$(addprefix $(UTILS_DIR), get_next_line_utils.c)	\

SRC = $(addprefix $(SRC_DIR), $(SRC_L))

# -------------
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
DEP = $(addsuffix .d, $(basename $(OBJ)))
# =============

all:
	@$(MAKE) -C $(LIB_L) --no-print-directory
	@$(MAKE) -C $(LIB_M) --no-print-directory
	@$(MAKE) $(NAME) --no-print-directory

$(OBJ_DIR)%.o: %.c $(MKFL)
	@$(MP) $(dir $@)
	@$(CC) $(CFLAGS) -MMD -I $(INC_DIR) $(MLX_CC) -c $< -o $@

$(NAME):: $(OBJ) $(LIB)
	@$(CC)  $(CFLAGS) $(OBJ) $(LIB) $(MLX_FLAGS) -o $(NAME)

$(NAME)::
	@echo "Hello, cub3d already compiled "

-include $(DEP)

clean:
	@$(MAKE) clean -C $(LIB_M) --no-print-directory
	@$(MAKE) clean -C $(LIB_L) --no-print-directory
	$(RM) $(OBJ_DIR)

fclean: clean
	@$(MAKE) fclean -C $(LIB_L) --no-print-directory
	@$(MAKE) clean -C $(LIB_M) --no-print-directory
	$(RM) $(NAME)

re:
	@$(MAKE) fclean --no-print-directory
	@$(MAKE) --no-print-directory

.PHONY: all clean fclean re
