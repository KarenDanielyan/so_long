/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_winlose.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:42:19 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/07 20:01:56 by kdaniely         ###   ########.fr       */
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
		ft_printf("Good Job :)\n");
		exit(EXIT_SUCCESS);
	}
}

int	on_e_opened(t_game *game)
{
	int	x;
	int	y;

	if (game->c_left == 0)
	{
		x = game->exit->x;
		y = game->exit->y;
		mlx_put_image_to_window(game->mlx, game->window,
			game->map->tiles[y][x].texture, x * TEXTURE_SIZE, y * TEXTURE_SIZE);
		mlx_put_image_to_window(game->mlx, game->window,
			game->exit->textures[1], x * TEXTURE_SIZE, y * TEXTURE_SIZE);
	}
	return (EXIT_SUCCESS);
}
