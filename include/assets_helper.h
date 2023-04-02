/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_helper.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:48:57 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/02 17:54:35 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSETS_HELPER_H
# define ASSETS_HELPER_H

#include "assets.h"
#include <mlx.h>
#include <ft_printf.h>
#include <stdlib.h>


struct s_paths
{
	char **g_paths;
	char **w_paths;
};

char **get_ground_paths(void);
char **get_wall_paths(void);

/* TODO: Add get_char_paths(), get_enemy_paths() and get_col_paths() */

# endif