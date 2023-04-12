/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_wasd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 21:12:59 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/13 00:47:58 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include <ft_printf.h>

int	on_player_move(int key, t_game *game)
{
	int		rv;
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
	on_lose(game);
	if (rv != 0)
		game->c_mov ++;
	if (game->c_left == 0)
		game->exit->is_open = 1;
	on_e_opened(game);
	rerender_exit(game, p.x, p.y);
	on_endgame(game);
	return (EXIT_SUCCESS);
}

int	on_key_press(int key, t_game *game)
{
	char	*tmp;
	char	*mov_count;
	char	*atk_count;
	int		rv;

	rv = on_player_move(key, game) | on_attack(key, game);
	tmp = ft_itoa(game->c_mov);
	mov_count = ft_strjoin("Mov count: ", tmp);
	free(tmp);
	tmp = ft_itoa(game->player->ap);
	atk_count = ft_strjoin("Atk count: ", tmp);
	free(tmp);
	render_image_on_pos(game, game->assets->black, game->map->width, 0);
	render_image_on_pos(game, game->assets->black, game->map->width + 1, 0);
	render_image_on_pos(game, game->assets->black, game->map->width + 2, 0);
	render_image_on_pos(game, game->assets->black, game->map->width, 1);
	render_image_on_pos(game, game->assets->black, game->map->width + 1, 1);
	render_image_on_pos(game, game->assets->black, game->map->width + 2, 1);
	mlx_string_put(game->mlx, game->window,
		game->map->width * TEXTURE_SIZE, 10, 0x78FF00, mov_count);
	mlx_string_put(game->mlx, game->window,
		game->map->width * TEXTURE_SIZE, 21, 0x78FF00, atk_count);
	free(mov_count);
	free(atk_count);
	return (rv);
}
