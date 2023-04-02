/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 13:58:32 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/02 17:53:39 by kdaniely         ###   ########.fr       */
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
		check_size(w, h);
		i ++;
	}
}

void	new_assets(void *mlx, t_assets **this)
{
	struct s_paths	p;

	*this = (t_assets *)malloc(sizeof(t_assets));
	(*this)->ground = (void **)malloc(T_GROUND_COUNT * sizeof(void *));
	// Where there will be more wall textures 
	p.g_paths = get_ground_paths();
	p.w_paths = get_wall_paths();
	set_assets(mlx, (*this)->ground, p.g_paths);
	set_assets(mlx, &(*this)->wall, p.w_paths);
	free(p.g_paths);
	free(p.w_paths);
}