/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_idle.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:36:24 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/12 20:46:02 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include <ft_printf.h>

static void	render_next_coll(t_game *game, t_clkt *col, int ind)
{
	static int	*i;
	t_point		p;

	if (i == NULL)
		i = (int *)ft_calloc(game->c_count, sizeof(int));
	if (!col->is_collected)
	{
		if (i[ind] == T_COLL_COUNT)
			i[ind] = 0;
		p.x = col->x;
		p.y = col->y;
		mlx_put_image_to_window(game->mlx, game->window,
			game->map->tiles[p.y][p.x].texture,
			p.x * TEXTURE_SIZE, p.y * TEXTURE_SIZE);
		mlx_put_image_to_window(game->mlx, game->window,
			col->textures[i[ind]], p.x * TEXTURE_SIZE, p.y * TEXTURE_SIZE);
		i[ind]++;
	}
}

int	coll_render_loop(t_game *game)
{
	int			i;
	static int	j;

	i = 0;
	while (i < game->c_count)
	{
		if (j % 1500 == 0)
			render_next_coll(game, &game->cols[i], i);
		i ++;
	}
	j ++;
	return (EXIT_SUCCESS);
}

static void	render_next_char_idle(t_game *game)
{
	static int	i;
	t_point		p;

	if (i == CHAR_IDLE_COUNT)
		i = 0;
	p.x = game->player->x;
	p.y = game->player->y;
	mlx_put_image_to_window(game->mlx, game->window,
		game->map->tiles[p.y][p.x].texture,
		p.x * TEXTURE_SIZE, p.y * TEXTURE_SIZE);
	mlx_put_image_to_window(game->mlx, game->window,
		game->player->textures->idle[i],
		p.x * TEXTURE_SIZE, p.y * TEXTURE_SIZE);
	i ++;
}

int	char_idle_loop(t_game *game)
{
	static int	i;

	if (i % 5000 == 0)
		render_next_char_idle(game);
	i ++;
	return (EXIT_SUCCESS);
}

int	default_loop(t_game *game)
{
	return (char_idle_loop(game) & coll_render_loop(game)
		& enemy_idle_loop(game));
}
