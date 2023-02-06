# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: macbook <macbook@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2023/01/16 13:26:57 by macbook       #+#    #+#                  #
#    Updated: 2023/01/30 12:44:25 by cbijman       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = so_long

# Flags
CFLAGS = -Wall -Wextra -Werror
DFLAGS = -g
OPENGL_FLAGS = -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit

# Colours
RESET = \033[0m
GREEN = \033[0;92m

# Files
INCLUDE =./include

HEADER = ./include/so_long.h \
		./include/libft.h \
		./include/MLX42.h \
		./include/MLX42_Input.h \

SRC =	ft_main.c \
		ft_vector.c \
		ft_player.c \
		ft_draw_utils.c \
		ft_animation.c \
		ft_map.c \
		ft_map_helpers.c \
		ft_map_validation.c \
		ft_map_path_validation.c \
		ft_graphics.c \
		ft_graphics_utils.c \

OBJ = ${SRC:%.c=bin/%.o}

LIBS =	libft/libft.a \
		MLX42/libmlx42.a

# Rules

bin/%.o: src/%.c $(HEADER)
	@gcc $(DFLAGS) -I$(INCLUDE) -o $@ -c $<
	@echo "$(GREEN)Compiling: $(RESET)$<"

$(NAME): $(OBJ)
	@mkdir -p bin
	@gcc $(CFLAGS) $(DFLAGS) $(OBJ) $(LIBS) -I$(INCLUDE) $(OPENGL_FLAGS) -o $(NAME)

all: lib $(NAME)

lib:
	@$(MAKE) -C MLX42 all
	@$(MAKE) -C libft all

clean:
	@rm -rf $(OBJ)
	@$(MAKE) -C libft clean
	@$(MAKE) -C MLX42 clean

fclean: clean
	@rm -rf $(NAME) $(LIBS)

re: fclean all

.PHONY: test all lib clean fclean re