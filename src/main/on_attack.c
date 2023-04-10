/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_attack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:13:55 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/10 20:51:13 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include <ft_printf.h>

static void	on_up(t_game *game)
{
	t_tile *player_loc;

	player_loc = &game->map->tiles[game->player->y][game->player->x];
	render_image_on_tile(game, player_loc, game->player->textures->atk_up[0]);
	render_image_on_tile(game, player_loc, game->player->textures->atk_up[1]);
}

static void	on_down(t_game *game)
{
	t_tile *player_loc;

	player_loc = &game->map->tiles[game->player->y][game->player->x];
	render_image_on_tile(game, player_loc, game->player->textures->atk_down[0]);
	render_image_on_tile(game, player_loc, game->player->textures->atk_down[1]);
}

static void	on_left(t_game *game)
{
	t_tile *player_loc;

	player_loc = &game->map->tiles[game->player->y][game->player->x];
	render_image_on_tile(game, player_loc, game->player->textures->atk_left[0]);
	render_image_on_tile(game, player_loc, game->player->textures->atk_left[1]);
}

static void	on_right(t_game *game)
{
	t_tile *player_loc;

	player_loc = &game->map->tiles[game->player->y][game->player->x];
	render_image_on_tile(game, player_loc, game->player->textures->atk_right[0]);
	render_image_on_tile(game, player_loc, game->player->textures->atk_right[1]);
}

/* TODO: Add enemy impact detection when implementing enemies. */
int	on_attack(int key, t_game *game)
{
	if (key == UP)
		on_up(game);
	if (key == DOWN)
		on_down(game);
	if (key == LEFT)
		on_left(game);
	if (key == RIGHT)
		on_right(game);
	return (EXIT_SUCCESS);
}