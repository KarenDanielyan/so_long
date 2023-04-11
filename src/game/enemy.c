/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:57:32 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/11 20:45:19 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <ft_printf.h>

static t_tile	*get_next_enemy(t_tile **tiles, int height, int width)
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
			if (tiles[i][j++].symb == 'e')
				return (&tiles[i][j - 1]);
		}
		i ++;
	}
	return (NULL);
}

int	get_enemy_ind(t_game *game, int x, int y)
{
	int	i;

	i = 0;
	while (i < game->c_count)
	{
		if (game->enemy[i].x == x && game->enemy[i].y == y)
			return (i);
		i ++;
	}
	return (-1);
}

void	kill_enemy(t_point p, t_game *game)
{
	int	i;
	int	ind;
	
	ind = get_enemy_ind(game, p.x, p.y);
	i = 0;
	while (i < ENEMY_DIE_COUNT)
	{
		render_image_on_tile(game, &game->map->tiles[p.y][p.x],
			game->enemy[ind].textures->die[i]);
		i ++;
	}
	game->enemy[ind].is_killed = 1;
	game->map->tiles[p.y][p.x].symb = 7;
}

void	new_enemies(t_game **game)
{
	int		i;
	t_tile	*tl;

	if ((*game)->e_count != 0)
	{
		(*game)->enemy = (t_enemy *)malloc((*game)->e_count * sizeof(t_enemy));
		i = 0;
		while (i < (*game)->e_count)
		{
			tl = get_next_enemy((*game)->map->tiles,
					(*game)->map->height, (*game)->map->width);
			(*game)->enemy[i].x = tl->x;
			(*game)->enemy[i].y = tl->y;
			(*game)->enemy[i].is_killed = 0;
			(*game)->enemy[i].textures = &(*game)->assets->enemy;
			i ++;
		}
	}
}