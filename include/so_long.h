/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: macbook <macbook@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 14:50:50 by macbook       #+#    #+#                 */
/*   Updated: 2023/02/06 15:12:17 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "MLX42.h"
# include <stdlib.h>

# define DEBUG
# define FILE_EXTENSION ".ber"
# define TILE_SIZE		96
# define TILE_W			32

typedef enum	e_direction
{
	PLAYER_DOWN	 = 0,
	PLAYER_LEFT	 = 3,
	PLAYER_UP	 = 2,
	PLAYER_RIGHT = 1,
} t_player_direction;

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_coin
{
	t_vector	*position;
	mlx_image_t	*image;
	int			enabled;
}	t_coin;

typedef struct s_player
{
	int					moves;
	mlx_image_t			*bottom_image;
	mlx_image_t			*upper_image;
	t_vector			*position;
	t_player_direction	e_direction;
}	t_player;

typedef struct s_map
{
	mlx_t		*handle;
	t_coin		*coins;
	t_player	*player;
	mlx_image_t	**images;
	char		**layout;
	char		*filename;
	int			width;
	int			height;
}	t_map;


//Map
t_map		*load_map(char *filename);
void		free_map(t_map *map);

//Map info
int			get_map_size(char *filename);
int			get_map_object(char *filename, char object);
int			get_map_object_from_map(t_map *map, char object);
t_vector	*get_object_coords_from_map(t_map *map, char obj);

//Validation
int			validate_map(t_map *map);
int			validate_size(t_map *map);
int			validate_path(t_map *map);
int			validate_borders(t_map *map);
int			validate_objects(t_map *map);
int			validate_filename(char *filename, t_map *map);


//MLX42 Graphics stuff related.
int			open_window(t_map *map);

//Drawing utils for MLX42
mlx_image_t	*get_sprite_from_map(t_map *map, char *fname, int column, int row);

//Drawing utils.
void		mlx_draw_line(mlx_image_t *img, int y, int height);
void		mlx_draw_rectangle(mlx_image_t *img, int xy[2], int wh[2]);
void		mlx_draw_rectangle_coords(mlx_image_t *img, int x, int y, int width, int height);
mlx_image_t	*draw_tile(mlx_t *mlx, int width, int height, t_vector *vec);
mlx_image_t	*draw_collectable(mlx_t *mlx, int width, int height, t_vector *vec);
mlx_image_t	*draw_image(mlx_t *mlx, char *filename, t_vector *vec);

//Vector
t_vector	*create_vector(int x, int y);

//Player
t_player	*initialize_player(t_map *map);
void		move_direction(const t_map *map, t_player_direction direction);
int			player_can_move(const t_map *map, int x, int y);

#endif