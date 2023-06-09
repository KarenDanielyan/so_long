/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terrain.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:00:25 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/11 18:12:19 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "game.h"

t_terrain	get_terrain(char symb)
{
	if (symb == MAPSYMS[0] || symb == MAPSYMS[2]
		|| symb == MAPSYMS[3] || symb == MAPSYMS[4]
		|| symb == MAPSYMS[5])
		return (PLAINS);
	if (symb == MAPSYMS[1])
		return (WALLS);
	return (0);
}
