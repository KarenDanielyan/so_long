/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:49:41 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/03 15:18:52 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assets_helper.h"



char **get_ground_paths(void)
{
	char	**g_paths;

	g_paths = (char **)malloc((T_GROUND_COUNT + 1) * sizeof(char *));
	g_paths[0] = TP_GROUND_1;
	g_paths[1] = TP_GROUND_2;
	g_paths[2] = TP_GROUND_3;
	g_paths[3] = NULL;
	return (g_paths);
}

char	**get_wall_paths(void)
{
	char **w_paths;

	w_paths = (char **)malloc((T_WALL_COUNT + 1) * sizeof(char *));
	w_paths[0] = TP_WALL;
	w_paths[1] = NULL;
	return (w_paths);
}

char	**get_col_paths(void)
{
	char	**c_paths;

	c_paths = (char **)malloc((T_COLL_COUNT + 1) * sizeof(char *));
	c_paths[0] = TP_COLLECT_1;
	c_paths[1] = TP_COLLECT_2;
	c_paths[2] = TP_COLLECT_3;
	c_paths[3] = TP_COLLECT_4;
	c_paths[4] = NULL;
	return (c_paths);
}

/* TODO: Add get_char_paths(), get_enemy_paths() */
