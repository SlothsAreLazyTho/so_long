/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_player.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: macbook <macbook@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/24 15:44:17 by macbook       #+#    #+#                 */
/*   Updated: 2023/01/26 18:10:07 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define PLAYER_ASSET "./textures/characters/player_32x32_new.png"

t_player	*initialize_player(t_map *map)
{
	t_player	*player;
	t_vector	*position;

	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	position = get_object_coords_from_map(map, 'P');
	ft_printf("\t%d\t%d", position->x, position->y);
	if (!position)
		return (perror("Error"), 1);
	player->x = position->x;
	player->y = position->y;
	player->e_direction = PLAYER_LEFT;
	player->image = get_sprite_from_map(map, PLAYER_ASSET, 0, PLAYER_LEFT);
	player->moves = 0;
	mlx_image_to_window(map->handle, player->image, player->x, player->y);
	return (player);
}

void	move_direction(t_map *map, t_player_direction direction)
{
	const t_player	*player = (t_player *) map->player;

	map->player->moves++;
	if (!player_can_move(0, 0, map))
		return ;
	if (direction == PLAYER_DOWN)
		map->player->image->instances[0].y += TILE_W;
	if (direction == PLAYER_UP)
		map->player->image->instances[0].y -= TILE_W;
	if (direction == PLAYER_LEFT)
		map->player->image->instances[0].x -= TILE_W;
	if (direction == PLAYER_RIGHT)
		map->player->image->instances[0].x += TILE_W;

	ft_printf("[MLX42] Player moved: X: %d, Y: %d, Moves: %d\n", 
		map->player->image->instances[0].x,
		map->player->image->instances[0].y,
		map->player->moves);
}

int	player_can_move(int x, int y, t_map *map)
{
	return (1);
}