/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_draw_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/25 16:01:31 by cbijman       #+#    #+#                 */
/*   Updated: 2023/01/25 16:24:10 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_draw_line(mlx_image_t *img, int y, int height)
{
	ft_printf("[MLX42] Printing line from %d to %d\n", height, y);
	y += 1;
	while(--y)
	{
		#ifdef RELEASE
			ft_printf("[DEBUG] [MLX42] Drawing pixel at X: %d, Y: %d\n", height, y);
		#endif
		mlx_put_pixel(img, height, y, 250);
	}
}

void	mlx_draw_rectangle_coords(mlx_image_t *img, int x, int y, int width, int height)
{
	int xy[2] = { x, y };
	int wh[2] = { width, height };
	mlx_draw_rectangle(img, xy, wh);
}

void	mlx_draw_rectangle(mlx_image_t *img, int xy[2], int wh[2])
{
	int	x_original;
	int	y_original;

	x_original = xy[0];
	y_original = xy[1];
	while (xy[0] < wh[0])
		mlx_put_pixel(img, xy[0]++, xy[1], 250);	
	while (xy[1] < wh[1])
		mlx_put_pixel(img, xy[0],   xy[1]++, 250);
	while (xy[1] > y_original)
		mlx_put_pixel(img, xy[1]--, xy[0], 250);
	while (xy[0] > x_original)
		mlx_put_pixel(img, xy[1],   xy[0]--, 250);
	
}
