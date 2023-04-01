/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 19:53:34 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/01 23:19:03 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_helper.h"
#include <libft.h>

#define COLOR "0PCE"

struct s_loc
{
	int	x;
	int	y;
};

static void	flood(char **map, int sr, int sc, char new_color)
{
	if (sr < 0 || sc < 0 || sr >= (int)ft_strlen_2d((const char **)map)
		|| sc >= (int)ft_strlen(*map) || ft_strchr(COLOR, map[sr][sc]) == NULL)
		return ;
	map[sr][sc] = new_color;
	flood(map, sr + 1, sc, new_color);
	flood(map, sr - 1, sc, new_color);
	flood(map, sr, sc + 1, new_color);
	flood(map, sr, sc - 1, new_color);
}

static void	flood_fill(char **map, int sr, int sc, char new_color)
{
	flood(map, sr, sc, new_color);
}

struct s_loc	get_flood_start(char **map)
{
	struct s_loc	loc;
	int				i;
	int				j;

	i = 0;
	while (*(map + i))
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				loc.x = j;
				loc.y = i;
				return (loc);
			}
			j ++;
		}
		i ++;
	}
	loc.x = -1;
	loc.y = -1;
	return (loc);
}

void	valid_path_check(char **map)
{
	struct s_loc	start;
	char			**dup;
	int				j;
	int				i;

	dup = ft_strdup_2d((const char **)map);
	start = get_flood_start(map);
	flood_fill(dup, start.y, start.x, 'f');
	i = 0;
	while (*(dup + i))
	{
		j = 0;
		while (dup[i][j])
		{
			if (dup[i][j] == 'C' || dup[i][j] == 'E')
			{
				ft_printf("Error\nNo valid path in the map.\n");
				exit(EXIT_FAILURE);
			}
			j ++;
		}
		i ++;
	}
	free_2d(dup);
}
