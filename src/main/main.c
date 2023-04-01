/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:41:00 by kdaniely          #+#    #+#             */
/*   Updated: 2023/03/31 18:48:33by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <parse.h>
#include <string.h>
#include <errno.h>

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
	mlx_loop(game.mlx);
	return (0);
}
