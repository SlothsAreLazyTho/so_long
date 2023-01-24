/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_map_validation.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: macbook <macbook@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/16 13:06:18 by macbook       #+#    #+#                 */
/*   Updated: 2023/01/24 17:45:56 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

int	validate_size(t_map *map)
{
	int	i;
	int	size;
	int	last_size;

	i = 0;
	size = 0;
	last_size = ft_strlen(map->layout[i]);
	while (++i < map->height)
	{
		size = ft_strlen(map->layout[i]);
		if (last_size != size)
			return (0);
		last_size = size;
	}
	return (1);
}

int	validate_borders(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->height)
	{
		if (i == 0 || i == (map->height - 1))
		{
			if (ft_strchr(map->layout[i], '0'))
				return (0);
		}
		if (i != 0 || i != (map->height - 1))
		{
			if (map->layout[i][0] == '0'
				|| map->layout[i][map->width - 1] == '0')
				return (0);
		}
	}
	return (1);
}

int	validate_objects(t_map *map)
{
	if (get_map_object_from_map(map, 'P') != 1)
		return (0);
	if (get_map_object_from_map(map, 'E') != 1)
		return (0);
	if (get_map_object_from_map(map, 'C') <= 0)
		return (0);
	return (1);
}

int	validate_map(t_map *map)
{
	if (!validate_size(map))
		return (0);
	if (!validate_borders(map))
		return (0);
	if (!validate_objects(map))
		return (0);
	return (1);
}
