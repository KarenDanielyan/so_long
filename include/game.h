/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:38:53 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/01 16:15:50 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <mlx.h>
# include "map.h"
# include "enemy.h"
# include "player.h"

# define TEXTURE_SIZE 64
# define GAME_TITLE "Realmbreak: The Lost Labyrinth"

# ifndef BONUS

#  define MAPSYMS "01CEP"
# else

#  define MAPSYMS "01^~CEP"
# endif

/*
*	Description: Our game instance. It contains
*	everything we need to know to figure out status
*	of our game. There is only one game instance in our
*	architecture.
*/
typedef struct s_game
{
	void		*mlx;
	void		*window;
	int			w_height;
	int			w_width;
	int			col_count;
	int			enemy_count;
	t_map		*map;
	t_player	*player;
	t_enemy		*enemy;
}	t_game;

/*
*	Description: Our "constructor" for game structure.
*	It is setting up our game state.
*/
void	new_game(t_game *game, char **map);

#endif