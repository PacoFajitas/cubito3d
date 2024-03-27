# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/27 14:34:20 by tfiguero          #+#    #+#              #
#    Updated: 2024/03/27 14:50:10 by tfiguero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

FILES = main
SRC = $(addsuffix .c, $(FILES))
vpath %.c srcs

HEADER = inc/cub3d.h

OBJ_DIR = objs
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
DEP = $(addsuffix .d, $(basename $(OBJ))) 

MLX_DIR = inc/mlx
MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

LIBFT_DIR = inc/libft
LIBFT = inc/libft/libft.a

RM = rm -f
CC = cc
CFLAGS = -Werror -Wextra -Wall #-g -fsanitize=address

$(OBJ_DIR)/%.o: %.c ${HEADER}  Makefile
	@mkdir -p $(@D)
	@${CC} $(CFLAGS) -Imlx -MMD -c $< -o $@

all:
	@$(MAKE) -C $(MLX_DIR) --no-print-directory
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory
	$(MAKE) $(NAME) --no-print-directory

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) $(LIBFT) -g -fsanitize=address -o -O3 $(NAME)
	@echo "EVERYTHING DONE  "

clean:
	$(MAKE) clean -C $(MLX_DIR) --no-print-directory
	$(MAKE) clean -C $(LIBFT_DIR) --no-print-directory
	$(RM) $(OBJ) $(DEP) --no-print-directory
	$(RM) -r $(OBJ_DIR) --no-print-directory
	@echo "OBJECTS REMOVED   "

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR) --no-print-directory
	$(RM) $(NAME) --no-print-directory
	@echo "EVERYTHING REMOVED   "

re:	fclean all

.PHONY: all clean fclean re

-include $(DEP)

#########
