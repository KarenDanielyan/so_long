/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_wasd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 21:12:59 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/05 19:14:17 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include <ft_printf.h>

int	on_player_move(int key, t_game *game)
{
	(void)game;
	if (key == W)
		ft_printf("I will move up soon...\n");
	if (key == A)
		ft_printf("I will move left soon...\n");
	if (key == S)
		ft_printf("I will move down soon...\n");
	if (key == D)
		ft_printf("I will move right soon...\n");
	return (EXIT_SUCCESS);
}