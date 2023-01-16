/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_main.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: macbook <macbook@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 15:03:24 by macbook       #+#    #+#                 */
/*   Updated: 2023/01/12 16:26:46 by macbook       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	t_map	*map;

	map = load_map("./assets/bigmap.ber");
	if (!map)
	{
		perror("Map error");
		return (1);
	}
	ft_printf("[INFO] Map size: %d, Width: %d, Height: %d\n",
		map->height * map->width, map->width, map->height);
	open_window(map);
	system("leaks -q so_long | grep \"^Process\"");
	return (0);
}