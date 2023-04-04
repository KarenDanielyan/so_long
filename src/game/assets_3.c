/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:07:55 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/04 13:55:26 by kdaniely         ###   ########.fr       */
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
	i = 0;
	while (i < CHAR_MVL_COUNT)
		mlx_destroy_image(mlx, this->mv_left[i++]);
	i = 0;
	while (i < CHAR_MVR_COUNT)
		mlx_destroy_image(mlx, this->mv_right[i++]);
	i = 0;
	while (i < CHAR_MVD_COUNT)
		mlx_destroy_image(mlx, this->mv_down[i++]);
	i = 0;
	while (i < CHAR_MVUP_COUNT)
		mlx_destroy_image(mlx, this->mv_up[i++]);
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
