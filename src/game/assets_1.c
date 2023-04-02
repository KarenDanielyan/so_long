/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:49:41 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/02 17:54:17 by kdaniely         ###   ########.fr       */
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

char **get_wall_paths(void)
{
	char **w_paths;

	w_paths = (char **)malloc((T_WALL_COUNT + 1) * sizeof(char *));
	w_paths[0] = TP_WALL;
	w_paths[1] = NULL;
	return (w_paths);
}

/* TODO: Add get_char_paths(), get_enemy_paths() and get_col_paths() */
