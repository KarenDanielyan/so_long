/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:38:53 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/02 01:19:33 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <mlx.h>
# include "map.h"
# include "enemy.h"
# include "assets.h"
# include "player.h"

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
*
*	c_count -> collectibles count,
*	e_count -> enemies count.
*/
typedef struct s_game
{
	int			w_width;
	int			w_height;
	int			c_count;
	int			e_count;
	void		*mlx;
	void		*window;
	t_player	*player;
	t_enemy		*enemy;
	t_assets	*assets;
	t_map		*map;
}	t_game;

/*
*	Description: Our "constructor" for game structure.
*	It is setting up our game state.
*/
void	new_game(t_game *game, char **map);
void	delete_game(t_game *game);

/* Additional Functions */
void	set_tile_textures(void *mlx, t_map *map);

#endif