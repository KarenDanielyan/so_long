/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 19:00:35 by kdaniely          #+#    #+#             */
/*   Updated: 2023/03/29 19:56:50 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERS_H
# define HELPERS_H

/*
*	Description: extension_check() checks whether provided
*	argument has proper extension or not.
*	If invalid file is provided, program will terminate it's execution.
*/
void	extension_check(char *file);
/*
*	Description: rectangular_map() will check whether the provided map
*	rectangular or not.
*	If the map is not rectangular, program will terminate it's execution.
*/
void	rectangle_check(char **map);
/*
*	Description: wall_check() checks the map to be surrounded by walls.
*	Program will terminate it's execuion if that is not the case.
*/
void	wall_check(char **map);
/*
*	Description: invalid_character() checks map on invalid characters.
*	Program will terminate it's execution if invalid characters are present.
*/
void	invalid_char_check(char **map);
/*
*	Description: one_start_exit_check() checks map to contain only one exit
*	and starting position.
*	Program will terminate it's execution otherwise.
*/
void	one_start_exit_check(char **map);
/*
*	Decription: valid_path_check() will try to find a valid path from starting position
*	towards collectibles and exit.
*	Program will terminate it's execution if no valid path was found.
*/
void	valid_path_check(char **map);

/* Additional functions */

// TODO: Add flood_fill()

#endif
