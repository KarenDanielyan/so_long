/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_enemy_idle_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 18:43:52 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/11 21:41:30 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

static void	render_next_enemy(t_game *game, t_enemy *enemy, int ind)
{
	static int	*i;
	t_point		p;

	if (i == NULL)
		i = (int *)ft_calloc(game->e_count, sizeof(int));
	p.x = enemy->x;
	p.y = enemy->y;
	if (!enemy->is_killed)
	{
		if (i[ind] == ENEMY_IDLE_COUNT)
			i[ind] = 0;
		mlx_put_image_to_window(game->mlx, game->window,
			game->map->tiles[p.y][p.x].texture,
			p.x * TEXTURE_SIZE, p.y * TEXTURE_SIZE);
		mlx_put_image_to_window(game->mlx, game->window,
			enemy->textures->idle[i[ind]], p.x * TEXTURE_SIZE, p.y * TEXTURE_SIZE);
		i[ind]++;
	}
}

int		enemy_idle_loop(t_game *game)
{
	int			i;
	static int	j;

	i = 0;
	if (game->e_count != 0)
	{
		while (i < game->c_count)
		{
			if (j % 1500 == 0)
				render_next_enemy(game, &game->enemy[i], i);
			i ++;
		}
		j ++;
	}
	return (EXIT_SUCCESS);
}