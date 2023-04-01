/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:47:08 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/01 16:29:17 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "map_helper.h"

void	new_map(t_map **map, char **mp)
{
	(*map) = (t_map *)malloc(sizeof(t_map));
	(*map)->height = ft_strlen_2d((const char **)mp);
	(*map)->width = ft_strlen(*mp);
	(*map)->tiles = get_tiles(mp, (*map)->width, (*map)->height);
}
