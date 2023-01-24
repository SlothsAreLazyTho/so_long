/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: macbook <macbook@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 14:50:50 by macbook       #+#    #+#                 */
/*   Updated: 2023/01/24 14:59:14 by macbook       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "MLX42.h"

# define FILE_EXTENSION ".ber"
# define PIXEL_WIDTH 32
# define PIXEL_HEIGHT 32

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
	mlx_image_t	*image;
	t_vector	*position;
}	t_player;

typedef struct s_map
{
	char		*filename;
	char		**layout;
	t_coin		*coins;
	t_player	*player;
	int			width;
	int			height;
}	t_map;


//Map
t_map		*load_map(char *filename);
void		load_map_objects(t_map *map);
void		free_map(t_map *map);

//Map info
int			get_map_size(char *filename);
int			get_map_coins(char *filename);
int			get_map_object_from_map(t_map *map, char object);
int			get_map_object(char *filename, char object);

//Validation
int			validate_map(t_map *map);
int			validate_size(t_map *map);
int			validate_path(t_map *map);
int			validate_borders(t_map *map);
int			validate_objects(t_map *map);
int			validate_filename(char *filename, t_map *map);


//MLX42 Graphics stuff related.
int			open_window(t_map *map);
mlx_image_t	*draw_tile(mlx_t *mlx, int width, int height, t_vector *vec);
mlx_image_t	*draw_collectable(mlx_t *mlx, int width, int height, t_vector *vec);
mlx_image_t	*draw_image(mlx_t *mlx, char *filename, t_vector *vec);

//Vector
t_vector	*create_vector(int x, int y);


#endif