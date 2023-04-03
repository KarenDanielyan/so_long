/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_helper.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:48:57 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/03 15:18:30 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSETS_HELPER_H
# define ASSETS_HELPER_H

#include "assets.h"
#include <mlx.h>
#include <ft_printf.h>
#include <stdlib.h>

struct	s_player_paths
{
	char	**idle_paths;
	char	**mv_left_paths;
	char	**mv_right_paths;
	char	**mv_up_paths;
	char	**mv_down_paths;
};

struct	s_paths
{
	char					**g_paths;
	char					**w_paths;
	char					**c_paths;
	struct s_player_paths	*p_paths;
};

char	**get_ground_paths(void);
char	**get_wall_paths(void);
char	**get_col_paths(void);

/* TODO: Add get_char_paths(), get_enemy_paths() and get_col_paths() */

# endif