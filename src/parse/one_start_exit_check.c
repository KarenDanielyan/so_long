/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_start_exit_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 19:50:46 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/04 13:08:50 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	check_count(int s_c, int e_c, int c_c)
{
	if (e_c != 1 || s_c != 1 || c_c == 0)
	{
		ft_printf("Error\n");
		if (e_c != 1 || s_c != 1)
			ft_printf("Invalid number of start/exit points.\n");
		if (c_c == 0)
			ft_printf("No collectibles on the map.\n");
		exit(EXIT_FAILURE);
	}
}

void	one_start_exit_check(char **map)
{
	char	*s;
	int		s_c;
	int		e_c;
	int		c_c;

	s_c = 0;
	e_c = 0;
	c_c = 0;
	while (*map)
	{
		s = *map;
		while (*s)
		{
			if (*s == 'E')
				e_c ++;
			if (*s == 'P')
				s_c ++;
			if (*s == 'C')
				c_c ++;
			s ++;
		}
		map ++;
	}
	check_count(s_c, e_c, c_c);
}
