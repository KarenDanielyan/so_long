/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 19:17:55 by kdaniely          #+#    #+#             */
/*   Updated: 2023/03/30 16:54:19 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "parse_helper.h"
#include <ft_printf.h>

t_game	parse(char *file)
{
	t_game koko;
	
	char **map;
	map = NULL;
	ft_dprintf(STDOUT_FILENO, "This is parse() function. It does nothing yet.\n");
	extension_check(file);
	//TODO: add read_file() function
	rectangle_check(map);
	wall_check(map);
	invalid_char_check(map);
	one_start_exit_check(map);
	valid_path_check(map);
	return (koko);
}
