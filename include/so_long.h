/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: macbook <macbook@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 14:50:50 by macbook       #+#    #+#                 */
/*   Updated: 2023/01/12 16:46:05 by macbook       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "MLX42.h"

# define DEBUG

typedef struct s_map
{
	char	**layout;
	int		width;
	int		height;	
}	t_map;

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_player
{
	mlx_image_t	*image;
	t_vector	*position;
}	t_player;

//Map
t_map		*load_map(char *filename);
void		*process_map_line(t_map *map, char *str, int i);
void		free_map(t_map *map);
int			get_map_size(char *filename);


//MLX42 Graphics stuff related.
int			open_window(t_map *map);
mlx_image_t	*draw_tile(mlx_t *mlx, int width, int height, t_vector *vec);
mlx_image_t	*draw_image(mlx_t *mlx, char *filename, t_vector *vec);

//Vector
t_vector	*create_vector(int x, int y);


#endif