/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible_render.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:36:24 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/04 16:50:16 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include <ft_printf.h>
#include <libft.h>

struct	s_point
{
	int x;
	int y;
};

static void	render_next_coll(t_game *game, t_clkt *col, int ind)
{
	static int		*i;
	struct s_point	p;

	if (i == NULL)
		i = (int *)ft_calloc(game->c_count, sizeof(int));
	if (i[ind] == T_COLL_COUNT)
		i[ind] = 0;
	p.x = col->x;
	p.y = col->y;
	mlx_put_image_to_window(game->mlx, game->window, game->map->tiles[p.x][p.y].texture, p.x * TEXTURE_SIZE, p.y * TEXTURE_SIZE);
	mlx_put_image_to_window(game->mlx, game->window, col->textures[i[ind]], p.x * TEXTURE_SIZE, p.y * TEXTURE_SIZE);
	i[ind] ++;
}

int	coll_render_loop(t_game *game)
{
	static int	i;
	static int	j;

	if (i == game->c_count)
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
	struct s_point	p;

	if (i == CHAR_IDLE_COUNT)
		i = 0;
	p.x = game->player->x;
	p.y = game->player->y;
	mlx_put_image_to_window(game->mlx, game->window, game->map->tiles[p.x][p.y].texture, p.x * TEXTURE_SIZE, p.y * TEXTURE_SIZE);
	mlx_put_image_to_window(game->mlx, game->window, game->player->textures->idle[i], p.x * TEXTURE_SIZE, p.y * TEXTURE_SIZE);
	i ++;
}

int	char_idle_loop(t_game *game)
{
	static int i;

	if (i % 950 == 0)
		render_next_char_idle(game);
	i ++;
	return (EXIT_SUCCESS);
}

int	default_loop(t_game *game)
{
	return (char_idle_loop(game) & coll_render_loop(game));
}