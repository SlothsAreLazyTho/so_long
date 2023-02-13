/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_player.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: macbook <macbook@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/24 15:44:17 by macbook       #+#    #+#                 */
/*   Updated: 2023/02/09 14:41:20 by macbook       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define PLAYER_ASSET "./textures/characters/player_32x32.png"

int	player_can_move(const t_map *map, int x, int y)
{
	return (1);
}

t_player	*initialize_player(t_map *map)
{
	t_player	*player;
	t_vector	*position;

	player = ft_calloc(1, sizeof(t_player));
	if (!player)
		return (NULL);
	position = get_object_coords_from_map(map, 'P');
	if (!position)
		return (perror("Error"), NULL);
	player->e_direction = PLAYER_LEFT;
	player->bottom_image = draw_player(map->handle, position);
	player->upper_image = get_sprite_from_map(map, PLAYER_ASSET, 0, PLAYER_LEFT);
	//mlx_image_to_window(map->handle, player->upper_image, 
	//	position->x, 
	//	position->y);
	return (player);
}

void	move_direction(const t_map *map, t_player_direction direction)
{
	const t_player	*player = (t_player *) map->player;

	map->player->moves++;
	if (!player_can_move(map, 0, 0))
		return ;
	if (direction == PLAYER_DOWN)
		map->player->bottom_image->instances[0].y += TILE_W;
	if (direction == PLAYER_UP)
		map->player->bottom_image->instances[0].y -= TILE_W;
	if (direction == PLAYER_LEFT)
		map->player->bottom_image->instances[0].x -= TILE_W;
	if (direction == PLAYER_RIGHT)
		map->player->bottom_image->instances[0].x += TILE_W;
	ft_printf("[MLX42] Player moved: X: %d, Y: %d, Moves: %d\n", 
		map->player->bottom_image->instances[0].x,
		map->player->bottom_image->instances[0].y,
		map->player->moves);
}
