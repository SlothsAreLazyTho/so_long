/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_graphics.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: macbook <macbook@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 17:47:36 by macbook       #+#    #+#                 */
/*   Updated: 2023/01/24 18:21:40 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "MLX42.h"

#include <stdio.h>
#include <stdlib.h>

mlx_image_t *load_spritesheet(mlx_t *mlx, char *filename)
{
	mlx_image_t		*img;
	mlx_texture_t	*tex;

	int posx = 32;
	int posy = 32;

	uint32_t xy[2] = { 64, 64 };
	uint32_t wh[2] = { posx + 32, posy + 32 };

	tex = mlx_load_png(filename);
	if (!tex)
		return (NULL);
	img = mlx_texture_area_to_image(mlx, tex, xy, wh);
	mlx_image_to_window(mlx, img, 10, 10);
	return (img);
}

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

void func(mlx_key_data_t keydata, void *map)
{
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		ft_printf("Mister is going upstairs!");
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		ft_printf("Mister is going left!");
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		ft_printf("Mister is going right!");
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		ft_printf("Mister is going downstairs!");
}

int	open_window(t_map *map)
{
	mlx_image_t	**images;

	ft_printf("[MLX42] Filename: %s\n", map->filename);
	ft_printf("[MLX42] Window width: %d, Window height: %d\n", (map->width - 1) * 32, map->height * 32);
	map->handle = mlx_init(map->width * 16, map->height * 16, "So Long!", true);
	if (!map->handle)
		return (1);
	//images = draw_map(map, handle);
	//mlx_loop_hook(handle, hook, NULL);
	load_spritesheet(map->handle, "./textures/characters/player.png");
	mlx_key_hook(map->handle, func, map);
	mlx_loop(map->handle);
	mlx_cleanup(map->handle, images);
	mlx_terminate(map->handle);
	return (0);
}

//if (map->game_state || map->lock_input)
		//return ;