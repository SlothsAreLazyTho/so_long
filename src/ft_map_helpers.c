/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_map_helpers.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: macbook <macbook@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/19 15:54:26 by macbook       #+#    #+#                 */
/*   Updated: 2023/01/24 15:52:01 by macbook       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int	get_map_size(char *filename)
{
	int		fd;
	int		i;
	char	*str;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	while (str)
	{
		str = get_next_line(fd);
		if (str)
			i++;
		free(str);
	}
	close(fd);
	return (i);
}

int	get_map_object(char *filename, char object)
{
	int		i;
	int		j;
	int		k;
	int		fd;
	char	*str;

	i = 0;
	k = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	str = get_next_line(fd);
	while (str)
	{
		j = -1;
		while (str[++j])
		{
			if (str[j] == object)
				k++;
		}
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (free(str), k);
}

int	get_map_object_from_map(t_map *map, char object)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (i < map->height)
	{
		j = 0;
		while (map->layout[i][j])
		{
			if (map->layout[i][j] == object)
				k++;
			j++;
		}
		i++;
	}
	return (k);
}

int	get_map_coins(char *filename)
{
	return (get_map_object(filename, 'C'));
}