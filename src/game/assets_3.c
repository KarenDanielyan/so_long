/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:07:55 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/10 17:28:26 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

/* TODO: Add mlx_destroy for attack sprites when you will add them. */
static void	delete_char_assets(void *mlx, t_player_a *this)
{
	int	i;

	i = 0;
	while (i < CHAR_IDLE_COUNT)
		mlx_destroy_image(mlx, this->idle[i++]);
	mlx_destroy_image(mlx, this->mv_left[0]);
	mlx_destroy_image(mlx, this->mv_left[1]);
	mlx_destroy_image(mlx, this->mv_right[0]);
	mlx_destroy_image(mlx, this->mv_right[1]);
	mlx_destroy_image(mlx, this->mv_down[0]);
	mlx_destroy_image(mlx, this->mv_down[1]);
	mlx_destroy_image(mlx, this->mv_up[0]);
	mlx_destroy_image(mlx, this->mv_up[1]);
	mlx_destroy_image(mlx, this->atk_down[0]);
	mlx_destroy_image(mlx, this->atk_down[1]);
	mlx_destroy_image(mlx, this->atk_up[0]);
	mlx_destroy_image(mlx, this->atk_up[1]);
	mlx_destroy_image(mlx, this->atk_left[0]);
	mlx_destroy_image(mlx, this->atk_left[1]);
	mlx_destroy_image(mlx, this->atk_right[0]);
	mlx_destroy_image(mlx, this->atk_right[1]);
}

static void	delete_env_assets(void *mlx, t_assets *this)
{
	int	i;

	i = 0;
	while (i < T_GRND_COUNT)
		mlx_destroy_image(mlx, this->ground[i++]);
	i = 0;
	while (i < T_COLL_COUNT)
		mlx_destroy_image(mlx, this->collectible[i++]);
	i = 0;
	while (i < T_EXIT_COUNT)
		mlx_destroy_image(mlx, this->exit[i++]);
	i = 0;
	while (i < T_WALL_COUNT)
		mlx_destroy_image(mlx, this->wall[i++]);
}

void	delete_assets(void *mlx, t_assets *this)
{
	delete_env_assets(mlx, this);
	delete_char_assets(mlx, &this->player);
	free(this);
}
