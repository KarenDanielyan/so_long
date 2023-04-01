/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helper.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:31:27 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/01 16:00:50 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HELPER_H
# define MAP_HELPER_H

# include "map.h"

t_tile	**get_tiles(char **map, int w, int h);
t_terrain	get_terrain(char symb);

#endif