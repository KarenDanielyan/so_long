/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_start_exit_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 19:50:46 by kdaniely          #+#    #+#             */
/*   Updated: 2023/03/30 21:57:27 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_helper.h"

void	one_start_exit_check(char **map)
{
	char	*s;
	int		s_c;
	int		e_c;

	s_c = 0;
	e_c = 0;
	while (*map)
	{
		s = *map;
		while (*s)
		{
			if (*s == 'E')
				e_c ++;
			if (*s == 'P')
				s_c ++;
			s ++;
		}
		map ++;
	}
	if (e_c != 1 || s_c != 1)
	{
		ft_printf("Error\nInvalid number of start/exit points.\n");
		exit(EXIT_FAILURE);
	}
}
