/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_winlose.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:42:19 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/17 12:21:40 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include <ft_printf.h>

void	on_endgame(t_game *game)
{
	t_player	*player;
	t_exit		*ext;

	ext = game->exit;
	player = game->player;
	if (ext->is_open
		&& (ext->x == player->x) && (ext->y == player->y))
	{
		delete_game(game);
		exit(WIN);
	}
}

int	on_e_opened(t_game *game)
{
	int	x;
	int	y;
	static int first_call;

	if (game->c_left == 0)
	{
		if (first_call == 0)
		{
			make_sound(DOOR_OPENED);
			first_call ++;
		}
		x = game->exit->x;
		y = game->exit->y;
		mlx_put_image_to_window(game->mlx, game->window,
			game->map->tiles[y][x].texture, x * TEXTURE_SIZE, y * TEXTURE_SIZE);
		mlx_put_image_to_window(game->mlx, game->window,
			game->exit->textures[1], x * TEXTURE_SIZE, y * TEXTURE_SIZE);
	}
	return (EXIT_SUCCESS);
}

void	on_lose(t_game	*game)
{
	int	is_on_enemy;

	if (game->e_count != 0)
	{
		is_on_enemy = get_enemy_ind(game, game->player->x,
				game->player->y);
		if (is_on_enemy != -1 && game->enemy[is_on_enemy].is_killed != 1)
		{
			delete_game(game);
			exit(LOSE);
		}
	}
}
