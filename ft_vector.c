/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_vector.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: macbook <macbook@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/12 14:12:52 by macbook       #+#    #+#                 */
/*   Updated: 2023/01/12 14:34:00 by macbook       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdlib.h>

t_vector	*create_vector(int x, int y)
{
	t_vector	*vec;

	vec = malloc(sizeof(t_vector));
	if (!vec)
		return (NULL);
	vec->x = x;
	vec->y = y;
	return (vec);
}

void	free_vector(t_vector *vec)
{
	free(vec);
}