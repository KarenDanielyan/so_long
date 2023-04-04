/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:57:37 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/04 17:59:23 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include "game.h"
#include <ft_printf.h>

int	on_exit_keypress(int key, t_game *game)
{
	if (key == 53)
	{
		delete_game(game);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
int	on_exit_destroy(int key, t_game *game)
{
	ft_printf("Game address %p\n", game);
	delete_game(game);
	exit(EXIT_SUCCESS);
	return (0);
}

int	print_key(int key)
{
	ft_printf("I pressed this key: %d\n", key);
	return (EXIT_SUCCESS);
}