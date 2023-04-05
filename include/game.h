/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:38:53 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/05 19:11:29 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <mlx.h>
# include "map.h"
# include "enemy.h"
# include "assets.h"
# include "player.h"

# define GAME_TITLE "Put Your Ad here."

# ifndef BONUS

#  define MAPSYMS "01CEP"
# else

#  define MAPSYMS "01^~CEP"
# endif


/* Type Definitions */

typedef enum	e_event
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17,
	NAE = 7
}	t_event;

typedef struct	s_collectible
{
	char	is_collected;
	int		x;
	int		y;
	void	**textures;
}	t_clkt;

typedef struct	s_exit
{
	char	is_open;
	int		x;
	int		y;
	void	**textures;
}	t_exit;

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
	t_clkt		*cols;
	t_exit		*exit;
	t_assets	*assets;
	t_map		*map;
}	t_game;

/* Main Functions */
/*
*	Description: Our "constructor" for game structure.
*	It is setting up our game state.
*/
void	new_game(t_game *game, char **map);
/*
*	Description: Our "destructor".
*/
void	delete_game(t_game *game);

/* Additional Functions */
void	new_game_collectibles(t_game **game);
void	new_game_exit(t_game **game);
void	new_player(t_game *game, t_player **this);

/* Random Generators */
double	rand_normal(double mean, double stddev, int use_last, int seed);
int		read_rand(int min, int max);

/* Platform Specific Code*/

# ifdef __APPLE__

typedef enum	e_keycode
{
	W = 13,
	A = 0,
	S = 1,
	D = 2,
	ESC = 53
}	t_code;

# elif __linux__
	/* TODO: Add Linux Keycodes */
# endif

#endif