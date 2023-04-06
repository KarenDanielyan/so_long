/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_wasd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 21:12:59 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/06 18:45:53 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include <ft_printf.h>

typedef struct	s_point
{
	int	x;
	int	y;
}	t_point;

static void	on_w(t_game *game)
{
	t_point		p;
	t_tile		**tiles;
	t_player	*player;

	player = game->player;
	tiles = game->map->tiles;
	p.x = player->x;
	p.y = player->y;
	mlx_put_image_to_window(game->mlx, game->window,
		player->textures->mv_up[0], p.x * TEXTURE_SIZE, p.y * TEXTURE_SIZE);
	if ((p.y - 1) >= 0 && tiles[p.y - 1][p.x].type != WALLS)
	{
		mlx_put_image_to_window(game->mlx, game->window,
			tiles[p.y][p.x].texture, p.x * TEXTURE_SIZE, p.y * TEXTURE_SIZE);
		mlx_put_image_to_window(game->mlx, game->window,
			player->textures->mv_up[1], p.x * TEXTURE_SIZE, (p.y - 1) * TEXTURE_SIZE);
		player->y = p.y - 1;
		tiles[p.y][p.x].symb = tiles[p.y][p.x].type;
		tiles[p.y - 1][p.x].symb = 'P';
	}
}

int	on_player_move(int key, t_game *game)
{
	(void)game;
	if (key == W)
		on_w(game);
	if (key == A)
		ft_printf("I will move left soon...\n");
	if (key == S)
		ft_printf("I will move down soon...\n");
	if (key == D)
		ft_printf("I will move right soon...\n");
	return (EXIT_SUCCESS);
}