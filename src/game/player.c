/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:58:40 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/11 15:48:41 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static t_point	get_player_point(t_map *map)
{
	int		i;
	int		j;
	t_point	p;

	i = 1;
	p.x = 0;
	p.y = 0;
	while (i < map->height)
	{
		j = 1;
		while (j < map->width)
		{
			if (map->tiles[i][j].symb == 'P')
			{
				p.x = j;
				p.y = i;
				return (p);
			}
			j ++;
		}
		i ++;
	}
	return (p);
}

void	new_player(t_game *game, t_player **this)
{
	t_point	p;

	*this = (t_player *)malloc(sizeof(t_player));
	p = get_player_point(game->map);
	(*this)->ap = PLAYER_AP;
	(*this)->textures = &game->assets->player;
	(*this)->x = p.x;
	(*this)->y = p.y;
}
