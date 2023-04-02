/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 01:07:44 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/03 01:56:34 by kdaniely         ###   ########.fr       */
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

# define CHAR_IDLE_COUNT 6
# define TP_CHAR_IDLE_1 "./assets/textures/character/MC_Idle_1.xpm"
# define TP_CHAR_IDLE_2 "./assets/textures/character/MC_Idle_2.xpm"
# define TP_CHAR_IDLE_3 "./assets/textures/character/MC_Idle_3.xpm"
# define TP_CHAR_IDLE_4 "./assets/textures/character/MC_Idle_4.xpm"
# define TP_CHAR_IDLE_5 "./assets/textures/character/MC_Idle_5.xpm"
# define TP_CHAR_IDLE_6 "./assets/textures/character/MC_Idle_6.xpm"

# define CHAR_MVUP_COUNT 3
# define TP_CHAR_MVUP_1 "./assets/textures/character/MC_Run_Up_1.xpm"
# define TP_CHAR_MVUP_2 "./assets/textures/character/MC_Run_Up_2.xpm"
# define TP_CHAR_MVUP_3 "./assets/textures/character/MC_Run_Up_3.xpm"

# define CHAR_MVD_COUNT 3
# define TP_CHAR_MVD_1 "./assets/textures/character/MC_Run_Down_1.xpm"
# define TP_CHAR_MVD_2 "./assets/textures/character/MC_Run_Down_2.xpm"
# define TP_CHAR_MVD_3 "./assets/textures/character/MC_Run_Down_3.xpm"

# define CHAR_MVL_COUNT 3
# define TP_CHAR_MVL_1 "./assets/textures/character/MC_Run_Left_1.xpm"
# define TP_CHAR_MVL_2 "./assets/textures/character/MC_Run_Left_2.xpm"
# define TP_CHAR_MVL_3 "./assets/textures/character/MC_Run_Left_3.xpm"

# define CHAR_MVR_COUNT 3
# define TP_CHAR_MVR_1 "./assets/textures/character/MC_Run_Right_1.xpm"
# define TP_CHAR_MVR_2 "./assets/textures/character/MC_Run_Right_2.xpm"
# define TP_CHAR_MVR_3 "./assets/textures/character/MC_Run_Right_3.xpm"

# define CHAR_ATKL_COUNT 1
# define CHAR_ATKR_COUNT 1
# define CHAR_ATKU_COUNT 1
# define CHAR_ATKD_COUNT 1

typedef struct	s_player_a
{
	void	**idle;
	void	**mv_left;
	void	**mv_right;
	void	**mv_up;
	void	**mv_down;
	void	**atk_down;
	void	**atk_up;
	void	**atk_right;
	void	**atk_left;
	void	**die;
}	t_player_a;

typedef struct s_enemy_a
{
	void	**idle;
	void	**mv;
	void	**defend;
	void	**die;
}	t_enemy_a;


typedef struct s_assets
{
	void		**ground;
	void		*wall;
	t_enemy_a	*enemy;
	t_player_a	*mc;
}	t_assets;

void	new_assets(void *mlx, t_assets **this);
void	delete_assets(void *mlx, t_assets *this);

#endif