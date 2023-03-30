/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_helper.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:27:31 by kdaniely          #+#    #+#             */
/*   Updated: 2023/03/30 18:25:51 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PARSE_HELPER_H
# define PARSE_HELPER_H

# include <ft_printf.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <libft.h>
# include <errno.h>

/*
*	Description: extension_check() checks whether provided
*	argument has proper extension or not.
*	If invalid file is provided, program will terminate it's execution.
*	It will return fd of inputted file on success.
*/
int	extension_check(char *file);
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

/*
*	Reference: DNE
*
*	Description: Returns a line read from file pointed by
*	file descriptor. If fd is invalid, function returns
*	NULL;
*	NOTE: In order to not have leaks, run get_next_line() function
*	with -42 parameter in order to free the static allocated space
*	before ending program execution.
*
*	Return Value: C-standard string with nl, or NULL on invalid fd.
*/
char	*get_next_line(int fd);

#endif
