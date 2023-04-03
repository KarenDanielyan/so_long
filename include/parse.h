/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:59:51 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/03 16:18:08 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "game.h"

/*
*	Descirpion: This function parses the provided map
*	and returns a game instance.
*	Program will terminate otherwise.
*/
t_game	parse(char *file);

#endif
