/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 21:43:06 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/12 20:48:40 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

t_clkt	*get_coll_by_loc(t_clkt *cols, int count, int x, int y)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (x == cols[i].x && y == cols[i].y && !cols[i].is_collected)
			return (&cols[i]);
		i ++;
	}
	return (NULL);
}

void	render_image_on_tile(t_game *game, t_tile *tile, void *img)
{
	int	x;
	int	y;

	x = tile->x;
	y = tile->y;
	mlx_put_image_to_window(game->mlx, game->window,
		tile->texture, x * TEXTURE_SIZE, y * TEXTURE_SIZE);
	mlx_put_image_to_window(game->mlx, game->window,
		img, x * TEXTURE_SIZE, y * TEXTURE_SIZE);
}

void	render_image_on_pos(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window,
		img, x * TEXTURE_SIZE, y * TEXTURE_SIZE);
}

void	rerender_exit(t_game *game, int x, int y)
{
	int	e_ind;

	if (x == game->exit->x && y == game->exit->y)
	{
		if (!game->exit->is_open)
		{
			mlx_put_image_to_window(game->mlx, game->window,
				game->exit->textures[0], game->exit->x * TEXTURE_SIZE,
				game->exit->y * TEXTURE_SIZE);
		}
		else
			on_e_opened(game);
	}
	if (game->e_count != 0)
	{
		e_ind = get_enemy_ind(game, x, y);
		if (e_ind != -1)
		{
			mlx_put_image_to_window(game->mlx, game->window,
				game->enemy[e_ind].textures->die[4],
				x * TEXTURE_SIZE, y * TEXTURE_SIZE);
		}
	}
}
