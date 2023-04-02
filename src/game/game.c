/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:07:59 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/02 18:34:09 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <libft.h>

void	new_game(t_game *game, char **map)
{
	new_map(&(game->map), map);
	game->w_height = (game->map->height * TEXTURE_SIZE);
	game->w_width = (game->map->width * TEXTURE_SIZE);
	//TODO: Add new_player()
	//TODO: Add new_enemy()
	game->e_count = 0;
	game->c_count = 0;
	game->mlx = mlx_init();
	new_assets(game->mlx, &game->assets);
	set_tile_textures(game->assets, game->map);
	game->window = mlx_new_window(game->mlx, game->w_width, game->w_height, GAME_TITLE);
}