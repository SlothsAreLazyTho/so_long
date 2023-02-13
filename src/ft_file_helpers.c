/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_file_helpers.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/08 16:44:49 by cbijman       #+#    #+#                 */
/*   Updated: 2023/02/09 13:29:58 by macbook       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/// @brief function to split paths from the filename.
/// @param filename Path to file.
/// @return Filename
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

bool	validate_filename(char *filename, t_map *map)
{	
	if (ft_strncmp(&filename[ft_strlen(filename) - 4], FILE_EXTENSION, 4) != 0)
		return (false);
	return (true);
}