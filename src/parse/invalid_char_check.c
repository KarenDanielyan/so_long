/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_char_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 19:50:15 by kdaniely          #+#    #+#             */
/*   Updated: 2023/03/30 21:45:49 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_helper.h"
#include "game.h"
#include <ft_printf.h>
#include <libft.h>

void	invalid_char_check(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*(map + i))
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr(MAPSYMS, map[i][j]) == NULL)
			{
				ft_printf("Error\nInvalid character in the map.\n");
				exit(EXIT_FAILURE);
			}
			j ++;
		}
		i ++;
	}
}
