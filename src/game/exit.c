/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:37:09 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/07 18:46:25 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static t_tile	*get_exit(t_map *map)
{
	int	i;
	int	j;

	i = 1;
	while (i < map->height)
	{
		j = 1;
		while (j < map->width)
		{
			if (map->tiles[i][j].symb == 'E')
				return (&map->tiles[i][j]);
			j ++;
		}
		i ++;
	}
	return (NULL);
}

void	new_game_exit(t_game **game)
{
	t_tile	*tl;

	(*game)->exit = (t_exit *)malloc(sizeof(t_exit));
	tl = get_exit((*game)->map);
	(*game)->exit->is_open = 0;
	(*game)->exit->x = tl->x;
	(*game)->exit->y = tl->y;
	(*game)->exit->textures = (*game)->assets->exit;
}
