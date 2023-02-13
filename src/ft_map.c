/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_map.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: macbook <macbook@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 16:08:25 by macbook       #+#    #+#                 */
/*   Updated: 2023/02/09 13:29:30 by macbook       ########   odam.nl         */
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

t_map	*create_map(char *filename)
{
	t_map	*map;
	int		fd;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	if (!validate_filename(filename, map))
		return (NULL);
	map->filename = get_file_name(filename);
	map->height = get_map_size(filename);
	map->layout = ft_calloc((map->height + 1), sizeof(char *));
	if (!map->layout)
		return (NULL);
	map->coins = malloc(get_map_object(filename, 'C') * sizeof(t_coin));
	if (!map->coins)
		return (NULL);
	return (map);
}

//Add extra protection for file descriptor safety.
t_map	*load_map(char *filename)
{
	char	*str;
	t_map	*map;
	int		fd;
	int		i;

	i = 0;
	map = create_map(filename);
	fd = open(filename, O_RDONLY);
	if (!map || fd < 0)
		return (free_map(map), NULL);
	if (!map->layout || map->height <= 0)
		return (NULL);
	str = get_next_line(fd);
	while (str)
	{
		if (!process_map_line(map, str, i))
			return (free_map(map), NULL);
		ft_printf("[Map] %s\n", map->layout[i]);
		i++;
		str = get_next_line(fd);
	}
	map->layout[i] = NULL;
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
