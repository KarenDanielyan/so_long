/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:46:24 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/17 13:57:16 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

static void	init_actors(t_game *game, t_tile tl)
{
	if (tl.symb == 'C')
		mlx_put_image_to_window(game->mlx, game->window,
			game->assets->collectible[0],
			tl.x * TEXTURE_SIZE, tl.y * TEXTURE_SIZE);
	if (tl.symb == 'E')
		mlx_put_image_to_window(game->mlx, game->window,
			game->assets->exit[0],
			tl.x * TEXTURE_SIZE, tl.y * TEXTURE_SIZE);
	if (tl.symb == 'P')
		mlx_put_image_to_window(game->mlx, game->window,
			game->assets->player.idle[0],
			tl.x * TEXTURE_SIZE, tl.y * TEXTURE_SIZE);
	if (tl.symb == 'e')
		mlx_put_image_to_window(game->mlx, game->window,
			game->assets->enemy.idle[0],
			tl.x * TEXTURE_SIZE, tl.y * TEXTURE_SIZE);
}

static void	init_strings(t_game *game)
{
	char	*atk_count;
	char	*join;

	atk_count = ft_itoa(game->player->ap);
	join = ft_strjoin("Atk count: ", atk_count);
	mlx_string_put(game->mlx, game->window,
		game->map->width * TEXTURE_SIZE, MOVCOUNT_ROW,
		0x78FF00, "Mov count: 0");
	mlx_string_put(game->mlx, game->window,
		game->map->width * TEXTURE_SIZE, ATKCOUNT_ROW,
		0x78FF00, join);
	free(join);
	free(atk_count);
}

void	init_map(t_game *game)
{
	int		i;
	int		j;
	t_tile	**tiles;

	i = 0;
	tiles = game->map->tiles;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			mlx_put_image_to_window(game->mlx, game->window,
				tiles[i][j].texture, j * TEXTURE_SIZE, i * TEXTURE_SIZE);
			init_actors(game, tiles[i][j]);
			j ++;
		}
		i ++;
	}
	init_strings(game);
}
