/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:50:33 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/03 14:08:51 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <libft.h>
#include <stdio.h>
#include "map_helper.h"

static void	err_msg(int	status, const char *str)
{
	if (status)
	{
		perror(str);
		exit(EXIT_FAILURE);
	}
}

void	read_tiles(t_tile **tiles, char **map, int w, int h)
{
	int	i;
	int	j;

	i = 0;
	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			tiles[i][j].symb = map[i][j];
			tiles[i][j].type = get_terrain(map[i][j]);
			tiles[i][j].x = j;
			tiles[i][j].y = i;
			j ++;
		}
		i ++;
	}
}

t_tile	**get_tiles(char **map, int w, int h)
{
	t_tile	**tiles;
	int		i;

	tiles = (t_tile **)malloc(h * sizeof(t_tile *));
	err_msg(!tiles, "Malloc");
	i = 0;
	while (i < h)
	{
		*(tiles + i) = (t_tile *)malloc(w * sizeof(t_tile));
		err_msg(!*(tiles + i), "Malloc");
		i ++;
	}
	read_tiles(tiles, map, w, h);
	return (tiles);
}
