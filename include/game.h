/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:38:53 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/03 18:42:40 by kdaniely         ###   ########.fr       */
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

typedef struct	s_collectible
{
	char	is_collected;
	int		x;
	int		y;
	void	**textures;
}	t_clkt;

typedef struct	s_exit
{
	char	*is_open;
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


/*
*	Description: Our "constructor" for game structure.
*	It is setting up our game state.
*/
void	new_game(t_game *game, char **map);
/*
*	Description: Our "destructor".
*/
void	delete_game(t_game *game);

/* Random Generators */
double	rand_normal(double mean, double stddev, int use_last, int seed);
int		read_rand(int min, int max);

/* Additional Functions */
void	set_game_collectibles(t_game **game);
void	set_game_exit(t_game **game);

#endif