/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:57:37 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/15 22:45:52 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include "game.h"
#include <ft_printf.h>

int	on_exit_destroy(t_game *game)
{
	int	status;

	status = SIGEXIT;
	write(game->write_fd, &status, sizeof(int));
	delete_game(game);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

int	on_exit_keypress(int key, t_game *game)
{
	if (key == ESC)
		on_exit_destroy(game);
	return (EXIT_SUCCESS);
}

int	print_key(int key)
{
	if (key != 53)
	{
		ft_printf("I pressed this key: %d\n", key);
		return (EXIT_SUCCESS);
	}
	return (EXIT_SUCCESS);
}
