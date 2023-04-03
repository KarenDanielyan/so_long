/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:15:18 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/03 20:56:04 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assets_helper.h"

static void	set_idle_paths(t_paths_p *paths)
{
	paths->idle_paths[0] = TP_CHAR_IDLE_1;
	paths->idle_paths[1] = TP_CHAR_IDLE_2;
	paths->idle_paths[2] = TP_CHAR_IDLE_3;
	paths->idle_paths[3] = TP_CHAR_IDLE_4;
	paths->idle_paths[4] = TP_CHAR_IDLE_5;
	paths->idle_paths[5] = TP_CHAR_IDLE_6;
	paths->idle_paths[6] = NULL;
}

static void set_mv_paths(t_paths_p *paths)
{
	paths->mv_up_paths[0] = TP_CHAR_MVUP_1;
	paths->mv_up_paths[1] = TP_CHAR_MVUP_2;
	paths->mv_up_paths[2] = TP_CHAR_MVUP_3;
	paths->mv_up_paths[3] = NULL;
	paths->mv_down_paths[0] = TP_CHAR_MVD_1;
	paths->mv_down_paths[1] = TP_CHAR_MVD_2;
	paths->mv_down_paths[2] = TP_CHAR_MVD_3;
	paths->mv_down_paths[3] = NULL;
	paths->mv_left_paths[0] = TP_CHAR_MVL_1;
	paths->mv_left_paths[1] = TP_CHAR_MVL_2;
	paths->mv_left_paths[2] = TP_CHAR_MVL_3;
	paths->mv_left_paths[3] = NULL;
	paths->mv_right_paths[0] = TP_CHAR_MVR_1;
	paths->mv_right_paths[1] = TP_CHAR_MVR_2;
	paths->mv_right_paths[2] = TP_CHAR_MVR_3;
	paths->mv_right_paths[3] = NULL;
}

static void	set_atk_paths(t_paths_p *paths)
{
	paths->atk_up_paths[0] = NULL;
	paths->atk_up_paths[1] = NULL;
	paths->atk_down_paths[0] = NULL;
	paths->atk_down_paths[1] = NULL;
	paths->atk_left_paths[0] = NULL;
	paths->atk_left_paths[1] = NULL;
	paths->atk_right_paths[0] = NULL;
	paths->atk_right_paths[1] = NULL;
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
