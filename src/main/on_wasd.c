/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_wasd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 21:12:59 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/07 20:01:02 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include <ft_printf.h>

int	on_player_move(int key, t_game *game)
{
	t_point	p;

	p.x = game->player->x;
	p.y = game->player->y;
	if (key == W)
		on_w(game);
	if (key == A)
		on_a(game);
	if (key == S)
		on_s(game);
	if (key == D)
		on_d(game);
	game->c_mov ++;
	if (game->c_left == 0)
		game->exit->is_open = 1;
	on_e_opened(game);
	rerender_exit(game, p.x, p.y);
	ft_printf("Movement Count: %d\n", game->c_mov);
	on_endgame(game);
	return (EXIT_SUCCESS);
}
