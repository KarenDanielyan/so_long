/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 19:53:06 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/04 13:08:51 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	rectangle_check(char **map)
{
	int	i;
	int	curr_len;
	int	last_len;

	i = 0;
	last_len = 0;
	while (*(map + i))
	{
		curr_len = ft_strlen(*(map + i));
		if (i != 0 && (curr_len != last_len))
		{
			ft_printf("Error\nMap is not rectangular\n");
			exit(EXIT_FAILURE);
		}
		last_len = curr_len;
		i ++;
	}
}
