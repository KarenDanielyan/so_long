/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 19:17:55 by kdaniely          #+#    #+#             */
/*   Updated: 2023/03/30 22:16:59 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "parse_helper.h"
#include <ft_printf.h>

static	void	free_2d(char **s)
{
	int	i;
	while (*(s + i))
	{
		free(*(s + i));
		i ++;
	}
	free (s);
}


t_game	parse(char *file)
{
	int		fd;
	char	**map;
	t_game	game;
	
	fd = extension_check(file);
	map = get_map(fd);
	rectangle_check(map);
	wall_check(map);
	invalid_char_check(map);
	one_start_exit_check(map);
	valid_path_check(map);
	// TODO: At this point we set our game instance. write the function for it.
	free_2d(map);
	return (game);
}
