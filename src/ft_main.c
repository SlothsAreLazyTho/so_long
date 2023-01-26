/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_main.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: macbook <macbook@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 15:03:24 by macbook       #+#    #+#                 */
/*   Updated: 2023/01/26 18:07:12 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	test(int argc, char **argv)
{
	t_map	*map;

	if (!argv[1])
		return (perror("Error"), 1);
	map = load_map(argv[1]);
	if (!map)
		return (perror("Map Error"), 1);
	if (!validate_map(map))
		return (perror("Map Error"), 1);
	open_window(map);
	free_map(map);
	return (EXIT_SUCCESS);
}

int main(void)
{
	char *argv[] = { "so_long", "./maps/bigmap.ber" };
	return (test(2, argv)); //
}