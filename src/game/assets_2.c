/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:15:18 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/12 20:41:24 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assets_helper.h"

static void	set_idle_paths(t_paths_p *paths)
{
	paths->idle_paths[0] = TP_CHAR_IDLE_1;
	paths->idle_paths[1] = TP_CHAR_IDLE_2;
	paths->idle_paths[2] = NULL;
}

static void	set_mv_paths(t_paths_p *paths)
{
	paths->mv_up_paths[0] = TP_CHAR_MVUP_1;
	paths->mv_up_paths[1] = TP_CHAR_MVUP_2;
	paths->mv_up_paths[2] = NULL;
	paths->mv_down_paths[0] = TP_CHAR_MVD_1;
	paths->mv_down_paths[1] = TP_CHAR_MVD_2;
	paths->mv_down_paths[2] = NULL;
	paths->mv_left_paths[0] = TP_CHAR_MVL_1;
	paths->mv_left_paths[1] = TP_CHAR_MVL_2;
	paths->mv_left_paths[2] = NULL;
	paths->mv_right_paths[0] = TP_CHAR_MVR_1;
	paths->mv_right_paths[1] = TP_CHAR_MVR_2;
	paths->mv_right_paths[2] = NULL;
}

static void	set_atk_paths(t_paths_p *paths)
{
	paths->atk_up_paths[0] = TP_CHAR_ATKU_1;
	paths->atk_up_paths[1] = TP_CHAR_ATKU_2;
	paths->atk_down_paths[0] = TP_CHAR_ATKD_1;
	paths->atk_down_paths[1] = TP_CHAR_ATKD_2;
	paths->atk_left_paths[0] = TP_CHAR_ATKL_1;
	paths->atk_left_paths[1] = TP_CHAR_ATKL_2;
	paths->atk_right_paths[0] = TP_CHAR_ATKR_1;
	paths->atk_right_paths[1] = TP_CHAR_ATKR_2;
	paths->atk_up_paths[2] = NULL;
	paths->atk_down_paths[2] = NULL;
	paths->atk_left_paths[2] = NULL;
	paths->atk_right_paths[2] = NULL;
}

t_paths_p	*get_player_paths(void)
{
	t_paths_p	*paths;

	paths = (t_paths_p *)malloc(sizeof(t_paths_p));
	set_idle_paths(paths);
	set_atk_paths(paths);
	set_mv_paths(paths);
	return (paths);
}

t_paths_e	*get_enemy_paths(void)
{
	t_paths_e	*paths;

	paths = (t_paths_e *)malloc(sizeof(t_paths_e));
	paths->die_paths[0] = TP_ENEMY_DIE_1;
	paths->die_paths[1] = TP_ENEMY_DIE_2;
	paths->die_paths[2] = TP_ENEMY_DIE_3;
	paths->die_paths[3] = TP_ENEMY_DIE_4;
	paths->die_paths[4] = TP_ENEMY_DIE_5;
	paths->idle_paths[0] = TP_ENEMY_IDLE_1;
	paths->idle_paths[1] = TP_ENEMY_IDLE_2;
	paths->idle_paths[2] = TP_ENEMY_IDLE_3;
	paths->idle_paths[3] = TP_ENEMY_IDLE_4;
	paths->idle_paths[4] = TP_ENEMY_IDLE_5;
	paths->idle_paths[5] = TP_ENEMY_IDLE_6;
	paths->idle_paths[6] = TP_ENEMY_IDLE_7;
	paths->idle_paths[7] = TP_ENEMY_IDLE_8;
	paths->idle_paths[8] = NULL;
	paths->die_paths[5] = NULL;
	return (paths);
}
