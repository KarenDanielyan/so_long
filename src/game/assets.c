/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 13:58:32 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/04 13:09:08 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assets_helper.h"

static void	check_size(int w, int h)
{
	if (w != TEXTURE_SIZE || h != TEXTURE_SIZE)
	{
		ft_printf("Error\nInvalid Texture Size.\n");
		exit(EXIT_FAILURE);
	}
}

static void	set_assets(void *mlx, void **textures, char **paths)
{
	int	w;
	int	h;
	int	i;

	i = 0;
	while (*(paths + i) && *(textures + i))
	{
		*(textures + i) = mlx_xpm_file_to_image(mlx, *(paths + i), &w, &h);
		if (*(textures + i) == NULL)
		{
			ft_printf("Error\nInvalid Path for Assets are specified.\n");
			exit(EXIT_FAILURE);
		}
		check_size(w, h);
		i ++;
	}
}

static void	set_player_assets(void *mlx, t_player_a *player, t_paths_p *p_paths)
{
	set_assets(mlx, player->idle, p_paths->idle_paths);
	set_assets(mlx, player->mv_up, p_paths->mv_up_paths);
	set_assets(mlx, player->mv_down, p_paths->mv_down_paths);
	set_assets(mlx, player->mv_left, p_paths->mv_left_paths);
	set_assets(mlx, player->mv_right, p_paths->mv_right_paths);
	/* TODO: Atk assets when they're ready. */
}

void	new_assets(void *mlx, t_assets **this)
{
	struct s_paths	p;

	*this = (t_assets *)malloc(sizeof(t_assets));
	p.g_paths = get_ground_paths();
	p.w_paths = get_wall_paths();
	p.c_paths = get_col_paths();
	p.e_paths = get_exit_paths();
	p.p_paths = get_player_paths();
	set_assets(mlx, (*this)->ground, p.g_paths);
	set_assets(mlx, (*this)->wall, p.w_paths);
	set_assets(mlx, (*this)->collectible, p.c_paths);
	set_assets(mlx, (*this)->exit, p.e_paths);
	set_player_assets(mlx, &(*this)->player, p.p_paths);
	free(p.g_paths);
	free(p.w_paths);
	free(p.c_paths);
	free(p.e_paths);
	free(p.p_paths);
}
