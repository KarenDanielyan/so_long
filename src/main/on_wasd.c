/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_wasd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 21:12:59 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/10 20:29:27 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include <ft_printf.h>

int	on_player_move(int key, t_game *game)
{
	int	rv;
	t_point	p;

	rv = 0;
	p.x = game->player->x;
	p.y = game->player->y;
	if (key == W)
		rv = on_w(game);
	if (key == A)
		rv = on_a(game);
	if (key == S)
		rv = on_s(game);
	if (key == D)
		rv = on_d(game);
	if (rv != 0)
	{
		game->c_mov ++;
		ft_printf("Movement Count: %d\n", game->c_mov);
	}
	if (game->c_left == 0)
		game->exit->is_open = 1;
	on_e_opened(game);
	rerender_exit(game, p.x, p.y);
	on_endgame(game);
	return (EXIT_SUCCESS);
}

int	on_key_press(int key, t_game *game)
{
	return ((on_player_move(key, game) | on_attack(key, game)));
}
