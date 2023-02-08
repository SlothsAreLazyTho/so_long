/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_file_helpers.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/08 16:44:49 by cbijman       #+#    #+#                 */
/*   Updated: 2023/02/08 17:34:24 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_file_name(char *filename)
{
	char	*name;
	char	**splitted;
	int		i;

	i = 0;
	if (!ft_strrchr(filename, '/'))
	{
		name = ft_strdup(filename);
		return (name);
	}
	splitted = ft_split(filename, '/');
	while (splitted[i])
		i++;
	name = ft_strdup(splitted[i - 1]);
	while (i--)
		free(splitted[i]);
	return (free(splitted), name);
}
