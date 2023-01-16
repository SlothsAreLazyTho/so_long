
NAME = so_long
INCLUDE =./include

CFLAGS = -Wall -Wextra -Werror
OPENGL_FLAGS = -lglfw -framework Cocoa -framework OpenGL -framework IOKit

SRC =	ft_main.c \
		ft_map.c \
		ft_vector.c \
		ft_graphics.c \
		ft_graphics_utils.c \

OBJ = ${SRC:%.c=bin/%.o}

LIBS = libft/libft.a MLX42/libmlx42.a

bin/%.o: %.c
	gcc -I$(INCLUDE) -o $@ -c $<

$(NAME): $(OBJ)
	@mkdir -p bin
	@gcc -I$(INCLUDE) $(OBJ) $(LIBS) $(OPENGL_FLAGS) -o $(NAME)
	@echo "Enjoy playing buddy!"

all: $(NAME)

lib:
	@make all -C MLX42
	@make all -C libft

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: clean all

.PHONY: lib all clean fclean re