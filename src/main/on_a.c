/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_a.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 19:03:17 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/16 00:03:07 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

static void	after_a(t_game *game, t_tile **tiles, t_point p)
{
	if (tiles[p.y][p.x - 1].symb == 'C')
	{
		make_sound(COLLECT_COIN);
		get_coll_by_loc(game->cols, game->c_count,
			(p.x - 1), p.y)->is_collected = 1;
		game->c_left --;
	}
	if (tiles[p.y][p.x].symb != 'E' && tiles[p.y][p.x].symb != 7)
		tiles[p.y][p.x].symb = tiles[p.y][p.x].type;
	if (tiles[p.y][p.x - 1].symb != 'E' && tiles[p.y][p.x - 1].symb != 7)
		tiles[p.y][p.x - 1].symb = 'P';
}

int	on_a(t_game *game)
{
	t_point	p;
	t_tile	**tiles;

	tiles = game->map->tiles;
	p.x = game->player->x;
	p.y = game->player->y;
	render_image_on_tile(game, &tiles[p.y][p.x],
		game->player->textures->mv_left[0]);
	if ((p.x - 1) >= 0
		&& tiles[p.y][p.x - 1].type != WALLS)
	{
		render_image_on_pos(game,
			tiles[p.y][p.x].texture, p.x, p.y);
		render_image_on_tile(game, &tiles[p.y][p.x - 1],
			game->player->textures->mv_left[1]);
		game->player->x = p.x - 1;
		after_a(game, tiles, p);
		return (1);
	}
	return (0);
}
