/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:51:16 by kdaniely          #+#    #+#             */
/*   Updated: 2023/03/30 14:08:45 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# ifdef BONUS

enum	e_terrain
{
	PLAINS	= '0',
	WALL	= '1',
	HILLS	= '^',
	MARSHES	= '~',
};
# else

enum	e_terrain
{
	PLAINS	= '0',
	WALL	= '1'
};
# endif

typedef enum e_terrain	t_terrain;

typedef struct s_tile
{
	int			x;
	int			y;
	t_terrain	type;
}	t_tile;

typedef struct s_map
{
	int		width;
	int		height;
	t_tile	**tiles;
}	t_map;

#endif