/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_w.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 19:03:56 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/10 18:21:01 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

static void	after_w(t_game *game, t_tile **tiles, t_point p)
{
	if (tiles[p.y - 1][p.x].symb == 'C')
	{
		get_coll_by_loc(game->cols, game->c_count,
			p.x, (p.y - 1))->is_collected = 1;
		game->c_left--;
	}
	if (tiles[p.y][p.x].symb != 'E')
		tiles[p.y][p.x].symb = tiles[p.y][p.x].type;
	if (tiles[p.y - 1][p.x].symb != 'E')
		tiles[p.y - 1][p.x].symb = 'P';
}

int	on_w(t_game *game)
{
	t_point	p;
	t_tile	**tiles;

	tiles = game->map->tiles;
	p.x = game->player->x;
	p.y = game->player->y;
	render_image_on_tile(game, &tiles[p.y][p.x],
		game->player->textures->mv_up[0]);
	if ((p.y - 1) >= 0 && tiles[p.y - 1][p.x].type != WALLS)
	{
		render_image_on_pos(game,
			tiles[p.y][p.x].texture, p.x, p.y);
		render_image_on_tile(game,
			&tiles[p.y - 1][p.x], game->player->textures->mv_up[1]);
		game->player->y = p.y - 1;
		after_w(game, tiles, p);
		return (1);
	}
	return (0);
}
