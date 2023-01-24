/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_map.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: macbook <macbook@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 16:08:25 by macbook       #+#    #+#                 */
/*   Updated: 2023/01/24 15:52:57 by macbook       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static void	*process_map_line(t_map *map, char *str, int i)
{
	if (!str)
		return (NULL);
	map->layout[i] = ft_strtrim(str, "\n\0");
	if (!map->layout[i])
		return (NULL);
	if (!map->width)
		map->width = ft_strlen(map->layout[i]);
	free(str);
	return (map->layout[i]);
}

int	validate_filename(char *filename, t_map *map)
{	
	int		i;
	char	**splitted;

	i = 0;
	if (ft_strncmp(&filename[ft_strlen(filename) - 4], FILE_EXTENSION, 4) != 0)
		return (0);
	if (!ft_strrchr(filename, '/'))
	{
		map->filename = ft_strdup(filename);
		return (1);
	}
	splitted = ft_split(filename, '/');
	while (splitted[i])
		i++;
	map->filename = ft_strdup(splitted[i - 1]);
	while (i--)
		free(splitted[i]);
	return (free(splitted), 1);
}

t_map	*create_map(char *filename)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	if (!validate_filename(filename, map))
		return (NULL);
	map->width = 0;
	map->height = get_map_size(filename);
	map->layout = malloc((map->height + 1) * sizeof(char *));
	if (!map->layout)
		return (NULL);
	map->coins = malloc(get_map_coins(filename) * sizeof(t_coin));
	if (!map->coins)
		return (NULL);
	return (map);
}

t_map	*load_map(char *filename)
{
	char	*str;
	t_map	*map;
	int		fd;
	int		i;

	i = 0;
	fd = open(filename, O_RDONLY);
	map = create_map(filename);
	if (!map || fd < 0)
		return (free(map), NULL);
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
	map->layout[++i] = NULL;
	close(fd);
	return (map);
}

void	free_map(t_map *map)
{
	while (map->height--)
		free(map->layout[map->height]);
	free(map->filename);
	free(map->layout);
	free(map->coins);
	free(map);
}
