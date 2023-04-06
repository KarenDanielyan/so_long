/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_wasd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 21:12:59 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/06 22:11:10 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include <ft_printf.h>

typedef struct	s_point
{
	int	x;
	int	y;
}	t_point;

static void	on_w(t_game *game)
{
	t_point		p;
	t_tile		**tiles;
	t_player	*player;

	player = game->player;
	tiles = game->map->tiles;
	p.x = player->x;
	p.y = player->y;
	mlx_put_image_to_window(game->mlx, game->window,
		player->textures->mv_up[0], p.x * TEXTURE_SIZE, p.y * TEXTURE_SIZE);
	if ((p.y - 1) >= 0 && tiles[p.y - 1][p.x].type != WALLS)
	{
		mlx_put_image_to_window(game->mlx, game->window,
			tiles[p.y][p.x].texture, p.x * TEXTURE_SIZE, p.y * TEXTURE_SIZE);
		mlx_put_image_to_window(game->mlx, game->window,
			player->textures->mv_up[1], p.x * TEXTURE_SIZE, (p.y - 1) * TEXTURE_SIZE);
		player->y = p.y - 1;
		if (tiles[p.y - 1][p.x].symb == 'C')
			get_coll_by_loc(game->cols, game->c_count, p.y, (p.x - 1))->is_collected = 1;
		tiles[p.y][p.x].symb = tiles[p.y][p.x].type;
		tiles[p.y - 1][p.x].symb = 'P';
	}
}

static void	on_a(t_game *game)
{
	t_point		p;
	t_tile		**tiles;
	t_player	*player;

	player = game->player;
	tiles = game->map->tiles;
	p.x = player->x;
	p.y = player->y;
	mlx_put_image_to_window(game->mlx, game->window,
		player->textures->mv_left[0], p.x * TEXTURE_SIZE, p.y * TEXTURE_SIZE);
	if ((p.x - 1) >= 0 && tiles[p.y][p.x - 1].type != WALLS)
	{
		mlx_put_image_to_window(game->mlx, game->window,
			tiles[p.y][p.x].texture, p.x * TEXTURE_SIZE, p.y * TEXTURE_SIZE);
		mlx_put_image_to_window(game->mlx, game->window,
			player->textures->mv_left[1], (p.x - 1) * TEXTURE_SIZE, p.y * TEXTURE_SIZE);
		player->x = p.x - 1;
		if (tiles[p.y][p.x - 1].symb == 'C')
			get_coll_by_loc(game->cols, game->c_count, p.y, (p.x - 1))->is_collected = 1;
		tiles[p.y][p.x].symb = tiles[p.y][p.x].type;
		tiles[p.y][p.x - 1].symb = 'P';
	}
}

static void	on_s(t_game *game)
{
	t_point		p;
	t_tile		**tiles;
	t_player	*player;

	player = game->player;
	tiles = game->map->tiles;
	p.x = player->x;
	p.y = player->y;
	mlx_put_image_to_window(game->mlx, game->window,
		player->textures->mv_down[0], p.x * TEXTURE_SIZE, p.y * TEXTURE_SIZE);
	if ((p.y + 1) <= game->map->height && tiles[p.y + 1][p.x].type != WALLS)
	{
		mlx_put_image_to_window(game->mlx, game->window,
			tiles[p.y][p.x].texture, p.x * TEXTURE_SIZE, p.y * TEXTURE_SIZE);
		mlx_put_image_to_window(game->mlx, game->window,
			player->textures->mv_down[1], p.x * TEXTURE_SIZE, (p.y + 1) * TEXTURE_SIZE);
		player->y = p.y + 1;
		if (tiles[p.y + 1][p.x].symb == 'C')
			get_coll_by_loc(game->cols, game->c_count, (p.y + 1), p.x)->is_collected = 1;
		tiles[p.y][p.x].symb = tiles[p.y][p.x].type;
		tiles[p.y + 1][p.x].symb = 'P';
	}
}

static void	on_d(t_game *game)
{
	t_point		p;
	t_tile		**tiles;
	t_player	*player;

	player = game->player;
	tiles = game->map->tiles;
	p.x = player->x;
	p.y = player->y;
	mlx_put_image_to_window(game->mlx, game->window,
		player->textures->mv_right[0], p.x * TEXTURE_SIZE, p.y * TEXTURE_SIZE);
	if ((p.x + 1) <= game->map->width && tiles[p.y][p.x + 1].type != WALLS)
	{
		mlx_put_image_to_window(game->mlx, game->window,
			tiles[p.y][p.x].texture, p.x * TEXTURE_SIZE, p.y * TEXTURE_SIZE);
		mlx_put_image_to_window(game->mlx, game->window,
			player->textures->mv_right[1], (p.x + 1) * TEXTURE_SIZE, p.y * TEXTURE_SIZE);
		player->x = p.x + 1;
		if (tiles[p.y][p.x + 1].symb == 'C')
			get_coll_by_loc(game->cols, game->c_count, (p.x + 1), p.y)->is_collected = 1;
		tiles[p.y][p.x].symb = tiles[p.y][p.x].type;
		tiles[p.y][p.x + 1].symb = 'P';
	}
}

int	on_player_move(int key, t_game *game)
{
	if (key == W)
		on_w(game);
	if (key == A)
		on_a(game);
	if (key == S)
		on_s(game);
	if (key == D)
		on_d(game);
	return (EXIT_SUCCESS);
}