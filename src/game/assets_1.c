/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:49:41 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/13 13:25:24 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assets_helper.h"

char	**get_ground_paths(void)
{
	char	**g_paths;

	g_paths = (char **)malloc((T_GRND_COUNT + 1) * sizeof(char *));
	g_paths[0] = TP_GROUND_1;
	g_paths[1] = TP_GROUND_2;
	g_paths[2] = TP_GROUND_3;
	g_paths[3] = NULL;
	return (g_paths);
}

char	**get_wall_paths(void)
{
	char	**w_paths;

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

char	**get_exit_paths(void)
{
	char	**e_paths;

	e_paths = (char **)malloc((T_EXIT_COUNT + 1) * sizeof(char *));
	e_paths[0] = TP_EXIT_1;
	e_paths[1] = TP_EXIT_2;
	e_paths[2] = NULL;
	return (e_paths);
}

char	**get_black_paths(void)
{
	char	**black;

	black = (char **)malloc(2 * sizeof(char *));
	black[0] = BLACK;
	black[1] = NULL;
	return (black);
}
