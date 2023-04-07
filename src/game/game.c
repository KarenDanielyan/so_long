/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:07:59 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/07 18:46:56 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <libft.h>

/* TODO: Add new_player() and when doing bonus new_enemy(), also e_count. */
void	new_game(t_game *game, char **map)
{
	game->mlx = mlx_init();
	new_assets(game->mlx, &game->assets);
	new_map(&(game->map), map);
	game->w_height = (game->map->height * TEXTURE_SIZE);
	game->w_width = (game->map->width * TEXTURE_SIZE);
	game->c_count = get_col_count(game->map);
	game->c_left = game->c_count;
	game->c_mov = 0;
	new_game_collectibles(&game);
	new_game_exit(&game);
	new_player(game, &game->player);
	set_tile_textures(game->assets, game->map);
	game->window = mlx_new_window(game->mlx, game->w_width,
			game->w_height, GAME_TITLE);
}

void	delete_game(t_game *game)
{
	delete_map(game->map);
	delete_assets(game->mlx, game->assets);
	mlx_destroy_window(game->mlx, game->window);
	free(game->cols);
	free(game->exit);
	free(game->player);
	free(game->mlx);
}
