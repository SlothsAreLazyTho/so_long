/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_graphics_utils.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: macbook <macbook@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 19:00:38 by macbook       #+#    #+#                 */
/*   Updated: 2023/02/09 14:43:27 by macbook       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "MLX42.h"

#include <stdlib.h>

mlx_image_t	*draw_tile(mlx_t *mlx, int width, int height, t_vector *vec)
{
	mlx_image_t		*img;
	mlx_texture_t	*tex;

	img = mlx_new_image(mlx, width, height);
	if (!img)
		return (NULL);
	ft_memset(img->pixels, 255, width * height * sizeof(int));
	mlx_image_to_window(mlx, img, vec->x, vec->y);
	return (img);
}

mlx_image_t	*draw_player(mlx_t *mlx, t_vector *vec)
{
	mlx_image_t		*img;
	mlx_texture_t	*tex;

	img = mlx_new_image(mlx, 32, 32);
	if (!img)
		return (NULL);
	ft_memset(img->pixels, 0x00FFFF, 32 * 32 * sizeof(int));
	mlx_image_to_window(mlx, img, vec->x, vec->y);
	return (img);
}

mlx_image_t	*draw_collectable(mlx_t *mlx, int width, int height, t_vector *vec)
{
	mlx_image_t		*img;
	mlx_texture_t	*tex;

	img = mlx_new_image(mlx, width, height);
	if (!img)
		return (NULL);
	ft_memset(img->pixels, 192, width * height * sizeof(int));
	mlx_image_to_window(mlx, img, vec->x, vec->y);
	return (img);
}
