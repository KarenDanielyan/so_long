/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 19:54:05 by kdaniely          #+#    #+#             */
/*   Updated: 2023/03/30 21:37:59 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_helper.h"
#include "game.h"

static void	err_msg()
{
	ft_printf("Error\nMap is not surrounded by walls\n");
	exit(EXIT_FAILURE);
}

void	wall_check(char **map)
{
	int	i;
	int	last_c;
	int	last_r;

	i = 0;
	last_c = ft_strlen((const char *)map[0]);
	last_r = ft_strlen_2d((const char **)map);
	while (i < last_c)
	{
		if (map[0][i] != WALL || map[last_r - 1][i] != WALL)
			err_msg();
		i ++;
	}
	i = 0;
	while (i < last_r)
	{
		if (map[i][0] != WALL || map[i][last_c - 1] != WALL)
			err_msg();
		i ++;
	}
}
