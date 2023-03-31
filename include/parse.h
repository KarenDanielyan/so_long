/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:59:51 by kdaniely          #+#    #+#             */
/*   Updated: 2023/03/31 17:56:31 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "game.h"

/*
*	Descirpion: This function parses the provided map
*	and return it in double char array on success.
*	Program will terminate otherwise.
*/
t_game	parse(char *file);

#endif
