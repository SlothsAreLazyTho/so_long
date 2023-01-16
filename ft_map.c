/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_map.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: macbook <macbook@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 16:08:25 by macbook       #+#    #+#                 */
/*   Updated: 2023/01/12 00:14:32 by macbook       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

t_map	*load_map(char *filename)
{
	char	*str;
	t_map	*map;
	int		fd;
	int		i;

	i = 0;
	fd = open(filename, O_RDONLY);
	map = malloc(sizeof(t_map));
	if (!map || fd < 0)
		return (free(map), NULL);
	map->height = get_map_size(filename);
	map->width = 0;
	map->layout = malloc(map->height * sizeof(char *));
	if (!map->layout || map->height <= 0)
		return (NULL);
	str = get_next_line(fd);
	while (str)
	{
		if (!process_map_line(map, str, i))
			return (free_map(map), NULL);
		i++;
		str = get_next_line(fd);
	}
	close(fd);
	return (map);
}

void	*process_map_line(t_map *map, char *str, int i)
{
	if (!str)
		return (NULL);
	map->layout[i] = ft_calloc(ft_strlen(str), sizeof(char));
	if (!map->layout[i])
		return (NULL);
	if (!map->width)
		map->width = ft_strlen(str);
	if (ft_strrchr(str, '\n'))
		ft_strlcpy(map->layout[i], str, ft_strlen(str));
	else
		ft_strlcpy(map->layout[i], str, ft_strlen(str) + 1);
	ft_printf("[Map] %s\n", map->layout[i]);
	free(str);
	return (map->layout[i]);
}

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

void	free_map(t_map *map)
{
	while (map->height--)
		free(map->layout[map->height]);
	free(map->layout);
	free(map);
}
