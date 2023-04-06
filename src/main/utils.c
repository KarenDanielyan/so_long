/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 21:43:06 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/06 21:59:16 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

t_clkt	*get_coll_by_loc(t_clkt *cols, int count, int x, int y)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (x == cols[i].x && y == cols[i].y)
			return (&cols[i]);
		i ++;
	}
	return (NULL);
}