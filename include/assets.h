/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 01:07:44 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/07 18:36:27 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSETS_H
# define ASSETS_H

# define TEXTURE_SIZE 48

# define T_GRND_COUNT 3
# define TP_GROUND_1 "./assets/textures/ground/ground_1.xpm"
# define TP_GROUND_2 "./assets/textures/ground/ground_2.xpm"
# define TP_GROUND_3 "./assets/textures/ground/ground_3.xpm"

# define T_WALL_COUNT 1
# define TP_WALL "./assets/textures/obstacles/Walls.xpm"

# define T_EXIT_COUNT 2
# define TP_EXIT_1 "./assets/textures/misc/Exit_1.xpm"
# define TP_EXIT_2 "./assets/textures/misc/Exit_2.xpm"

# define T_COLL_COUNT 4
# define TP_COLLECT_1 "./assets/textures/misc/collectible_1.xpm"
# define TP_COLLECT_2 "./assets/textures/misc/collectible_2.xpm"
# define TP_COLLECT_3 "./assets/textures/misc/collectible_3.xpm"
# define TP_COLLECT_4 "./assets/textures/misc/collectible_4.xpm"

# define CHAR_IDLE_COUNT 2
# define TP_CHAR_IDLE_1 "./assets/textures/character/MC_Idle_1.xpm"
# define TP_CHAR_IDLE_2 "./assets/textures/character/MC_Idle_5.xpm"

# define CHAR_MVUP_COUNT 2
# define TP_CHAR_MVUP_1 "./assets/textures/character/MC_Run_Up_1.xpm"
# define TP_CHAR_MVUP_2 "./assets/textures/character/MC_Run_Up_2.xpm"

# define CHAR_MVD_COUNT 2
# define TP_CHAR_MVD_1 "./assets/textures/character/MC_Run_Down_1.xpm"
# define TP_CHAR_MVD_2 "./assets/textures/character/MC_Run_Down_2.xpm"

# define CHAR_MVL_COUNT 2
# define TP_CHAR_MVL_1 "./assets/textures/character/MC_Run_Left_1.xpm"
# define TP_CHAR_MVL_2 "./assets/textures/character/MC_Run_Left_2.xpm"

# define CHAR_MVR_COUNT 2
# define TP_CHAR_MVR_1 "./assets/textures/character/MC_Run_Right_1.xpm"
# define TP_CHAR_MVR_2 "./assets/textures/character/MC_Run_Right_2.xpm"

# define CHAR_ATKL_COUNT 1
# define CHAR_ATKR_COUNT 1
# define CHAR_ATKU_COUNT 1
# define CHAR_ATKD_COUNT 1

# define CHAR_DIE_COUNT 1

typedef struct s_player_a
{
	void	*idle[CHAR_IDLE_COUNT];
	void	*mv_left[CHAR_MVL_COUNT];
	void	*mv_right[CHAR_MVR_COUNT];
	void	*mv_up[CHAR_MVUP_COUNT];
	void	*mv_down[CHAR_MVD_COUNT];
	void	*atk_down[CHAR_ATKD_COUNT];
	void	*atk_up[CHAR_ATKU_COUNT];
	void	*atk_right[CHAR_ATKR_COUNT];
	void	*atk_left[CHAR_ATKL_COUNT];
	void	*die[CHAR_DIE_COUNT];
}	t_player_a;

typedef struct s_enemy_a
{
	void	**idle;
	void	**mv;
	void	**defend;
	void	**die;
}	t_enemy_a;

/* TODO: Add enemies Later */
typedef struct s_assets
{
	void		*wall[T_WALL_COUNT];
	void		*exit[T_EXIT_COUNT];
	void		*ground[T_GRND_COUNT];
	void		*collectible[T_COLL_COUNT];
	t_player_a	player;
}	t_assets;

void	new_assets(void *mlx, t_assets **this);
void	delete_assets(void *mlx, t_assets *this);

#endif