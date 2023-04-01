/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 19:17:55 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/01 20:33:47 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "parse_helper.h"
#include "game.h"
#include <ft_printf.h>

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
	new_game(&game, map);
	free_2d(map);
	return (game);
}
