/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terrain.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:00:25 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/01 20:13:00 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_helper.h"
#include "game.h"

t_terrain	get_terrain(char symb)
{
	if (symb == MAPSYMS[0] || symb == MAPSYMS[2]
		|| symb == MAPSYMS[3] || symb == MAPSYMS[4])
		return (PLAINS);
	if (symb == MAPSYMS[1])
		return (WALLS);
	return (0);
}