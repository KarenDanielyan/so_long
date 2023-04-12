/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_attack_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:13:55 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/12 15:54:10 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include <ft_printf.h>

static void	on_up(t_game *game)
{
	t_tile	*player_loc;
	t_point	p;

	player_loc = &game->map->tiles[game->player->y][game->player->x];
	p.x = player_loc->x;
	p.y = player_loc->y - 1;
	render_image_on_tile(game, player_loc,
		game->player->textures->atk_up[0]);
	render_image_on_tile(game, player_loc,
		game->player->textures->atk_up[1]);
	if (game->map->tiles[p.y][p.x].symb == 'e')
		kill_enemy(p, game);
	game->player->ap --;
}

static void	on_down(t_game *game)
{
	t_tile	*player_loc;
	t_point	p;

	player_loc = &game->map->tiles[game->player->y][game->player->x];
	p.x = player_loc->x;
	p.y = player_loc->y + 1;
	render_image_on_tile(game, player_loc, game->player->textures->atk_down[0]);
	render_image_on_tile(game, player_loc, game->player->textures->atk_down[1]);
	if (game->map->tiles[p.y][p.x].symb == 'e')
		kill_enemy(p, game);
	game->player->ap --;
}

static void	on_left(t_game *game)
{
	t_tile	*player_loc;
	t_point	p;

	player_loc = &game->map->tiles[game->player->y][game->player->x];
	p.x = player_loc->x - 1;
	p.y = player_loc->y;
	render_image_on_tile(game, player_loc, game->player->textures->atk_left[0]);
	render_image_on_tile(game, player_loc, game->player->textures->atk_left[1]);
	if (game->map->tiles[p.y][p.x].symb == 'e')
		kill_enemy(p, game);
	game->player->ap --;
}

static void	on_right(t_game *game)
{
	t_point	p;
	t_tile	*player_loc;

	player_loc = &game->map->tiles[game->player->y][game->player->x];
	p.x = player_loc->x + 1;
	p.y = player_loc->y;
	render_image_on_tile(game, player_loc, game->player->textures->atk_right[0]);
	render_image_on_tile(game, player_loc, game->player->textures->atk_right[1]);
	if (game->map->tiles[p.y][p.x].symb == 'e')
		kill_enemy(p, game);
	game->player->ap --;
}

int	on_attack(int key, t_game *game)
{
	if (game->player->ap != 0)
	{
		if (key == UP)
			on_up(game);
		if (key == DOWN)
			on_down(game);
		if (key == LEFT)
			on_left(game);
		if (key == RIGHT)
			on_right(game);
		ft_printf("AP Left: %d\n", game->player->ap);
	}
	return (EXIT_SUCCESS);
}
