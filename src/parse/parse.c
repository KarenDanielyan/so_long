/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 19:17:55 by kdaniely          #+#    #+#             */
/*   Updated: 2023/03/30 18:26:08 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "parse_helper.h"
#include <ft_printf.h>

t_game	parse(char *file)
{
	int		fd;
	t_game	game;
	
	fd = extension_check(file);
	//TODO: add read_file() function
	rectangle_check(NULL);
	wall_check(NULL);
	invalid_char_check(NULL);
	one_start_exit_check(NULL);
	valid_path_check(NULL);
	return (game);
}
