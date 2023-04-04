/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:47:08 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/04 13:08:53 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "map.h"


int		get_col_count(t_map *map)
{
	int	i;
	int	j;
	int	res;

	i = 1;
	res = 0;
	while (i < map->height)
	{
		j = 1;
		while (j < map->width)
		{
			if (map->tiles[i][j].symb == 'C')
				res ++;
			j ++;
		}
		i ++;
	}
	return (res);
}

void	new_map(t_map **map, char **mp)
{
	(*map) = (t_map *)malloc(sizeof(t_map));
	(*map)->height = ft_strlen_2d((const char **)mp);
	(*map)->width = ft_strlen(*mp);
	(*map)->tiles = get_tiles(mp, (*map)->width, (*map)->height);
}

void	delete_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(*(map->tiles + i));
		i ++;
	}
	free(map->tiles);
	free(map);
}
