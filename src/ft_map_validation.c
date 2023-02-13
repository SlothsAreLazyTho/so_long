/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_map_validation.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: macbook <macbook@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/16 13:06:18 by macbook       #+#    #+#                 */
/*   Updated: 2023/02/09 13:24:10 by macbook       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

bool	validate_size(t_map *map)
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
			return (false);
		last_size = size;
	}
	return (true);
}

bool	validate_borders(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->height)
	{
		if ((i == 0 || i == (map->height - 1)) \
			&& ft_strchr(map->layout[i], '0'))
		{
			return (false);
		}
		if (i != 0 || i != (map->height - 1))
		{
			if (map->layout[i][0] == '0'
				|| map->layout[i][map->width - 1] == '0')
				return (false);
		}
	}
	return (true);
}

bool	validate_objects(t_map *map)
{
	if (get_map_object_from_map(map, 'P') != 1)
		return (false);
	if (get_map_object_from_map(map, 'E') != 1)
		return (false);
	if (get_map_object_from_map(map, 'C') <= 0)
		return (false);
	return (true);
}

bool	validate_map(t_map *map)
{
	if (!validate_size(map))
		return (false);
	if (!validate_borders(map))
		return (false);
	if (!validate_objects(map))
		return (false);
	return (true);
}
