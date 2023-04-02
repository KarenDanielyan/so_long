/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 19:46:32 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/02 18:33:19 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <libft.h>
#include "game.h"

static void	set_random_texture(void **texture, t_terrain type, t_assets *assets)
{
	int		index;
	void	**ast;

	if (type == PLAINS)
	{
		index = read_rand(0, T_GROUND_COUNT);
		ast = assets->ground;
	}
	if (type == WALLS)
	{
		index = read_rand(0, T_WALL_COUNT);
		ast = &assets->wall;
	}
	*texture = ast[index];
}

void	set_tile_textures(t_assets *assets, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->tiles[i][j].type == PLAINS)
				set_random_texture(&map->tiles[i][j].texture, PLAINS, assets);
			if (map->tiles[i][j].type == WALLS)
				map->tiles[i][j].texture = assets->wall;
			j ++;
		}
		i ++;
	}
}
