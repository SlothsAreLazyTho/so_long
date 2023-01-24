/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_graphics.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: macbook <macbook@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 17:47:36 by macbook       #+#    #+#                 */
/*   Updated: 2023/01/24 14:50:39 by macbook       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "MLX42.h"

#include <stdlib.h>

void	mlx_cleanup(mlx_t *handle, mlx_image_t **images)
{
	mlx_image_t	*curr;

	while (curr)
	{
		curr = *images++;
		mlx_delete_image(handle, curr);
	}
}

mlx_image_t	**draw_map(t_map *map, mlx_t *handle)
{
	mlx_image_t		**images;
	mlx_texture_t	*tex;
	int				i;
	int				j;
	int				k;
	int				m;

	images = malloc(map->height * map->width * sizeof(mlx_image_t));
	if (!images)
		return (NULL);
	i = map->height;
	k = 0;
	m = 0;
	while (m < i)
	{
		j = 0;
		while (map->layout[m][j])
		{
			if (map->layout[m][j] == '1')
				images[k++] = draw_tile(handle, 16, 16, create_vector(j * 16, m * 16));
			if (map->layout[m][j] == 'C')
				images[k++] = draw_collectable(handle, 16, 16, create_vector(j * 16, m * 16));
			if (map->layout[m][j] == 'P')
				images[k++] = draw_image(handle, "./assets/player.png", create_vector(j * 16, m * 16));
			j++;
		}
		m++;
	}
	return (images);
}

int	open_window(t_map *map)
{
	mlx_t		*handle;
	mlx_image_t	**images;

	ft_printf("[MLX42] Filename: %s\n", map->filename);
	ft_printf("[MLX42] Window width: %d, Window height: %d\n", (map->width - 1) * 16, map->height * 16);
	handle = mlx_init(map->width * 16, map->height * 16, "So Long!", true);
	if (!handle)
		return (1);
	images = draw_map(map, handle);
	mlx_loop(handle);
	mlx_cleanup(handle, images);
	mlx_terminate(handle);
	return (0);
}
