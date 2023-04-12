/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:38:53 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/12 20:20:51 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <mlx.h>
# include <libft.h>
# include "map.h"
# include "assets.h"

# define GAME_TITLE "Put Your Ad here."
# define EVENT_WINDOW_SIZE 200
# define MAPSYMS "01CEeP"
# define PLAYER_AP 6

/* Type Definitions */

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef enum e_event
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

typedef struct s_collectible
{
	char	is_collected;
	int		x;
	int		y;
	void	**textures;
}	t_clkt;

typedef struct s_exit
{
	char	is_open;
	int		x;
	int		y;
	void	**textures;
}	t_exit;

/*
*	Description: This is our playable actor class.
*/
typedef struct s_player
{
	int			x;
	int			y;
	int			ap;
	t_player_a	*textures;
}	t_player;

/*
*	Descritpion: This is our enemy actor class.
*/
typedef struct s_enemy
{
	int			x;
	int			y;
	int			is_killed;
	t_enemy_a	*textures;
}	t_enemy;

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
	int			c_left;
	int			e_left;
	int			c_mov;
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
void	new_enemies(t_game **game);
void	new_game_exit(t_game **game);
void	new_game_collectibles(t_game **game);
void	new_player(t_game *game, t_player **this);

void	render_image_on_tile(t_game *game, t_tile *tile, void *img);
void	render_image_on_pos(t_game *game, void *img, int x, int y);
void	rerender_exit(t_game *game, int x, int y);

void	kill_enemy(t_point enemy_loc, t_game *game);
int		get_enemy_ind(t_game *game, int x, int y);

t_clkt	*get_coll_by_loc(t_clkt *cols, int count, int x, int y);

/* Random Generators */
double	rand_normal(double mean, double stddev, int use_last, int seed);
int		read_rand(int min, int max);

/* Platform Specific Code*/
# ifdef __APPLE__

typedef enum e_keycode
{
	W = 13,
	A = 0,
	S = 1,
	D = 2,
	ESC = 53,
	UP = 126,
	DOWN = 125,
	RIGHT = 124,
	LEFT = 123
}	t_code;

# elif __linux__

typedef enum e_keycode
{
	W = 119,
	A = 97,
	S = 115,
	D = 100,
	ESC = 65307,
	UP = 65362,
	DOWN = 65364,
	RIGHT = 65363,
	LEFT = 65361
}	t_code;

# endif

#endif