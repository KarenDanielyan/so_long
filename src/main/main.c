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
#include <string.h>
#include <errno.h>
#include "game.h"
#include "parse.h"

void	init_window(t_game *game)
{
	int	i;
	int	j;
	t_tile	**tiles;

	i = 0;
	tiles = game->map->tiles;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			mlx_put_image_to_window(game->mlx, game->window, tiles[i][j].texture, j * TEXTURE_SIZE, i * TEXTURE_SIZE);
			j ++;
		}
		i ++;
	}
}

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
	init_window(&game);
	return (0);
}
