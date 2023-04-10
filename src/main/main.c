/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:48:57 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/10 20:30:34 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "events.h"
#include "parse.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac > 2 || ac == 1)
	{
		if (ac == 1)
			ft_printf("Error:\nArgument list too short.\n");
		else
			ft_printf("Error:\n%s.\n", strerror(E2BIG));
		exit(EXIT_FAILURE);
	}
	game = parse(av[1]);
	init_map(&game);
	mlx_hook(game.window, ON_DESTROY, 1L << 2, &on_exit_destroy, &game);
	mlx_hook(game.window, ON_KEYDOWN, 1 << 0L, &on_exit_keypress, &game);
	mlx_hook(game.window, ON_KEYUP, 1 << 1L, &on_key_press, &game);
	mlx_loop_hook(game.mlx, &default_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
