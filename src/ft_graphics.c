/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_graphics.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: macbook <macbook@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 17:47:36 by macbook       #+#    #+#                 */
/*   Updated: 2023/02/06 15:40:23 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "MLX42.h"

#include <stdio.h>
#include <stdlib.h>

mlx_image_t	*get_sprite_from_map(t_map *map, char *fname, int column, int row)
{
	//const uint32_t	xy[2] = {96 * 1, 96 * row};
	//const uint32_t	wh[2] = {96, 96};
	const uint32_t	xy[2] = {50, 20};
	const uint32_t	wh[2] = {64, 64};
	mlx_texture_t	*tex;
	mlx_image_t		*img;

	tex = mlx_load_png(fname);
	if (!tex)
		return (NULL);
	img = mlx_texture_area_to_image(map->handle, tex, (uint32_t *) xy, (uint32_t *) wh);
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
				images[k++] = draw_tile(handle, 32, 32, create_vector(j * 32, m * 32));
			if (map->layout[m][j] == 'C')
				images[k++] = draw_collectable(handle, 32, 32, create_vector(j * 32, m * 32));
			j++;
		}
		m++;
	}
	return (images);
}

void	func(mlx_key_data_t keydata, void *voidmap)
{
	const t_map	*map = (t_map *) voidmap;

	if (!map->player && !map->player->bottom_image)
		return ;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit(1);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_direction(map, PLAYER_UP);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move_direction(map, PLAYER_LEFT);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move_direction(map, PLAYER_DOWN);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move_direction(map, PLAYER_RIGHT);
}

int	open_window(t_map *map)
{
	mlx_image_t	**images;

	ft_printf("[MLX42] Filename: %s\n", map->filename);
	ft_printf("[MLX42] Window width: %d, Window height: %d\n", 
		(map->width  - 1) * 32,
		(map->height - 0) * 32);
	map->handle = mlx_init(1366, 768, "So Long!", true);
	//map->handle = mlx_init(map->width * 32, map->height * 32, "So Long!", true);
	if (!map->handle)
		return (1);
	//draw_map(map, map->handle);
	if (!map->player)
		map->player = initialize_player(map);
	mlx_key_hook(map->handle, func, map);
	mlx_loop(map->handle);
	mlx_cleanup(map->handle, images);
	mlx_terminate(map->handle);
	return (0);
}