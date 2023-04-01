/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:51:16 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/01 21:19:49 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# ifdef BONUS

enum	e_terrain
{
	PLAINS	= '0',
	WALLS	= '1',
	HILLS	= '^',
	MARSHES	= '~',
	T_COUNT		= 4
};
# else

enum	e_terrain
{
	PLAINS	= '0',
	WALLS	= '1',
	T_COUNT		= 2
};
# endif

typedef enum e_terrain	t_terrain;

typedef struct s_tile
{
	char		symb;
	int			x;
	int			y;
	t_terrain	type;
	void		*texture;
}	t_tile;

typedef struct s_map
{
	int		width;
	int		height;
	t_tile	**tiles;
}	t_map;

void	new_map(t_map **map, char **mp);

#endif