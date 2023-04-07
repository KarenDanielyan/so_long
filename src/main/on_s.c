/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 19:03:43 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/07 20:00:37 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

static void	after_s(t_game *game, t_tile **tiles, t_point p)
{
	if (tiles[p.y + 1][p.x].symb == 'C')
	{
		get_coll_by_loc(game->cols,
			game->c_count, p.x, (p.y + 1))->is_collected = 1;
		game->c_left --;
	}
	if (tiles[p.y][p.x].symb != 'E')
		tiles[p.y][p.x].symb = tiles[p.y][p.x].type;
	if (tiles[p.y + 1][p.x].symb != 'E')
		tiles[p.y + 1][p.x].symb = 'P';
}

void	on_s(t_game *game)
{
	t_point	p;
	t_tile	**tiles;

	tiles = game->map->tiles;
	p.x = game->player->x;
	p.y = game->player->y;
	render_image_on_tile(game, &tiles[p.y][p.x],
		game->player->textures->mv_down[0]);
	if ((p.y + 1) <= game->map->height
		&& tiles[p.y + 1][p.x].type != WALLS)
	{
		render_image_on_pos(game,
			tiles[p.y][p.x].texture, p.x, p.y);
		render_image_on_tile(game, &tiles[p.y + 1][p.x],
			game->player->textures->mv_down[1]);
		game->player->y = p.y + 1;
		after_s(game, tiles, p);
	}
}
