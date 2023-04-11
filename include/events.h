/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:40:21 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/11 15:33:57 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "game.h"

void	init_map(t_game *game);
void	on_endgame(t_game *game);

int		on_w(t_game *game);
int		on_a(t_game *game);
int		on_s(t_game *game);
int		on_d(t_game *game);

int		coll_render_loop(t_game *game);
int		enemy_idle_loop(t_game *game);
int		char_idle_loop(t_game *game);
int		default_loop(t_game *game);
int		on_e_opened(t_game *game);

int		on_exit_keypress(int key, t_game *game);
int		on_exit_destroy(t_game *game);
int		print_key(int key);

int		on_player_move(int key, t_game *game);
int		on_attack(int key, t_game *game);
int		on_key_press(int key, t_game *game);

#endif