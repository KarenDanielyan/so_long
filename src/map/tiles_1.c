/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 19:46:32 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/01 20:17:49 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <libft.h>
#include "game.h"

static char	**get_texture_paths(void)
{
	char	**texture_paths;

	texture_paths = (char **)malloc(T_COUNT * sizeof(char *));
	texture_paths[0] = PLAINS_TEXTURE;
	texture_paths[1] = WALLS_TEXTURE;
	return (texture_paths);
}

static void	load_textures(void *mlx, void **textures, char **texture_paths)
{
	int	i;
	int	w;
	int	h;
	
	i = 0;
	while (i < T_COUNT)
	{
		textures[i] = mlx_xpm_file_to_image(mlx, texture_paths[i], &w, &h);
		i ++;
	}
	free(texture_paths);
}

void	set_tile_textures(void *mlx, t_map *map)
{
	int	i;
	int	j;
	void	**textures;

	i = 0;
	textures = (void **)malloc(T_COUNT * sizeof(void *));
	load_textures(mlx, textures, get_texture_paths());
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->tiles[i][j].type == PLAINS)
				map->tiles[i][j].texture = textures[0];
			if (map->tiles[i][j].type == WALLS)
				map->tiles[i][j].texture = textures[1];
			j ++;
		}
		i ++;
	}
}
