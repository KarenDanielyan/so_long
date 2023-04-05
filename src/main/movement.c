/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 21:12:59 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/05 17:32:09 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include <ft_printf.h>

int	on_player_move(int key, t_game *game)
{
	// if (key == 13)
	// 	on_move_up(game);
	// if (key == 0)
	// 	;
	// if (key == 1)
	// 	;
	// if (key == 2)
	// 	;
	if (key == 13 && game)
		ft_printf("Instead of printing into console character will move up.\n");
	return (EXIT_SUCCESS);
}