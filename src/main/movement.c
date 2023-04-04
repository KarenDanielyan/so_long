/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 21:12:59 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/04 21:53:51 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

static void	on_move_up(t_game *game)
{
	void		**textures;
	t_tile		**tiles;
	t_player	*player;
	int			i;

	i = 0;
	textures = game->player->textures->mv_up;
	tiles = game->map->tiles;
	player = game->player;
		while (i < CHAR_MVUP_COUNT - 1)
		{
			if (i != 0)
			{
				mlx_put_image_to_window(game->mlx, game->window, tiles[player->y - i - 1][player->x].texture, player->x * TEXTURE_SIZE,
						(player->y - i - 1) * TEXTURE_SIZE);
			}
			mlx_put_image_to_window(game->mlx, game->window, textures[i], player->x * TEXTURE_SIZE,
					(player->y - i) * TEXTURE_SIZE);
			i ++;
		}
		tiles[player->y][player->x].symb = tiles[player->y][player->x].type;
		player->y = player->y - 1;
		tiles[player->y][player->x].symb = 'P';
}

int	on_player_move(int key, t_game *game)
{
	if (key == 13)
		on_move_up(game);
	if (key == 0)
		;
	if (key == 1)
		;
	if (key == 2)
		;
	return (EXIT_SUCCESS);
}