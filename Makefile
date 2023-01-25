# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: macbook <macbook@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2023/01/16 13:26:57 by macbook       #+#    #+#                  #
#    Updated: 2023/01/25 16:13:45 by cbijman       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = so_long

# Flags
CFLAGS = -Wall -Wextra -Werror
DFLAGS = -g -fsanitize=address
OPENGL_FLAGS = -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit

# Colours
RESET = \033[0m
GREEN = \033[0;92m

# Files
INCLUDE =./include

SRC =	ft_main.c \
		ft_vector.c \
		ft_draw_utils.c \
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

bin/%.o: src/%.c
	@gcc -I$(INCLUDE) -o $@ -c $<
	@echo "$(GREEN)Compiling: $(RESET)$<"

$(NAME): $(OBJ)
	@mkdir -p bin
	@gcc -I$(INCLUDE) $(CFLAGS) $(OBJ) $(LIBS) $(OPENGL_FLAGS) -o $(NAME)

test: $(OBJ)
	@mkdir -p bin
	@gcc -I$(INCLUDE) $(DFLAGS) $(OBJ) $(LIBS) $(OPENGL_FLAGS) -o $(NAME)


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

.PHONY: lib test all clean fclean re