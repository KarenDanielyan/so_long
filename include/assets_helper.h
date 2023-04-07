/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_helper.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:48:57 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/07 18:37:21 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSETS_HELPER_H
# define ASSETS_HELPER_H

# include "assets.h"
# include <mlx.h>
# include <ft_printf.h>
# include <stdlib.h>

typedef struct s_player_paths
{
	char	*idle_paths[CHAR_IDLE_COUNT + 1];
	char	*mv_left_paths[CHAR_MVL_COUNT + 1];
	char	*mv_right_paths[CHAR_MVR_COUNT + 1];
	char	*mv_up_paths[CHAR_MVUP_COUNT + 1];
	char	*mv_down_paths[CHAR_MVD_COUNT + 1];
	char	*atk_left_paths[CHAR_ATKL_COUNT + 1];
	char	*atk_right_paths[CHAR_ATKR_COUNT + 1];
	char	*atk_up_paths[CHAR_ATKU_COUNT + 1];
	char	*atk_down_paths[CHAR_ATKD_COUNT + 1];
}	t_paths_p;

struct	s_paths
{
	char		**g_paths;
	char		**w_paths;
	char		**c_paths;
	char		**e_paths;
	t_paths_p	*p_paths;
};

char		**get_ground_paths(void);
char		**get_wall_paths(void);
char		**get_col_paths(void);
char		**get_exit_paths(void);
t_paths_p	*get_player_paths(void);

/* TODO: get_enemy_paths() */
#endif