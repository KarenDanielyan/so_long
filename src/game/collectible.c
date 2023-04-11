/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:01:00 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/11 17:13:50 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static t_tile	*get_next_collectible(t_tile **tiles, int height, int width)
{
	static int		i;
	static int		j;

	if (i == height)
		i = 0;
	while (i < height)
	{
		if (j == width)
			j = 0;
		while (j < width)
		{
			if (tiles[i][j++].symb == 'C')
				return (&tiles[i][j - 1]);
		}
		i ++;
	}
	return (NULL);
}

int	get_col_ind(t_game *game, int x, int y)
{
	int	i;

	i = 0;
	while (i < game->c_count)
	{
		if (game->cols[i].x == x && game->cols[i].y == y)
			return (i);
		i ++;
	}
	return (-1);
}

void	new_game_collectibles(t_game **game)
{
	int		i;
	t_tile	*tl;

	(*game)->cols = (t_clkt *)malloc((*game)->c_count * sizeof(t_clkt));
	i = 0;
	while (i < (*game)->c_count)
	{
		tl = get_next_collectible((*game)->map->tiles,
				(*game)->map->height, (*game)->map->width);
		(*game)->cols[i].x = tl->x;
		(*game)->cols[i].y = tl->y;
		(*game)->cols[i].is_collected = 0;
		(*game)->cols[i].textures = (*game)->assets->collectible;
		i ++;
	}
}
