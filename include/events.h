/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:40:21 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/04 21:14:55 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "game.h"

void	init_map(t_game *game);

int	coll_render_loop(t_game *game);
int	char_idle_loop(t_game *game);
int	default_loop(t_game *game);

int	on_exit_keypress(int key, t_game *game);
int	on_exit_destroy(t_game *game);
int	print_key(int key);

int	on_player_move(int key, t_game *game);

#endif