/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 01:07:44 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/02 20:58:08 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSETS_H
# define ASSETS_H

# define TEXTURE_SIZE 48

# define T_GROUND_COUNT 3
# define TP_GROUND_1 "./assets/textures/ground/ground_1.xpm"
# define TP_GROUND_2 "./assets/textures/ground/ground_2.xpm"
# define TP_GROUND_3 "./assets/textures/ground/ground_3.xpm"

# define T_WALL_COUNT 1
# define TP_WALL "./assets/textures/Wall_3-2.xpm"

/* TODO: Define them when doing character animations.
# define CHAR_IDLE_COUNT 5
# define TP_CHAR_IDLE_1
# define TP_CHAR_IDLE_2
# define TP_CHAR_IDLE_3
# define TP_CHAR_IDLE_4
# define TP_CHAR_IDLE_5
*/

typedef struct s_assets
{
	void	**ground;
	void	*wall;
	/* TODO: Add appropriate pointers to player and enemy characters;
		void	*player;
		void	*enemy;
	*/
}	t_assets;

/*
typedef struct s_player_a
{
	void	**idle;
	void	**mov_left;
	void	**mov_right;
	void	**mov_up;
	void	**mov_down;
	void	**attack;
}	t_player_a;

typedef struct s_enemy_a
{
	void	**idle;
	void	**mov_left;
	void	**mov_right;
}	t_enemy_a;
*/

void	new_assets(void *mlx, t_assets **this);
void	delete_assets(void *mlx, t_assets *this);

#endif