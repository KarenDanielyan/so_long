/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:51:16 by kdaniely          #+#    #+#             */
/*   Updated: 2023/03/31 17:58:05 by kdaniely         ###   ########.fr       */
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
	NAT		= 0
};
# else

enum	e_terrain
{
	PLAINS	= '0',
	WALL	= '1',
	NAT		= 0
};
# endif

typedef enum e_terrain	t_terrain;

typedef struct s_tile
{
	int			x;
	int			y;
	char		symb;
	t_terrain	type;
	void		*texture;
}	t_tile;

typedef struct s_map
{
	int		width;
	int		height;
	t_tile	**tiles;
}	t_map;

/* Functions */

#endif