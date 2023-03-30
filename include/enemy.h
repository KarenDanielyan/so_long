/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:51:35 by kdaniely          #+#    #+#             */
/*   Updated: 2023/03/30 14:59:06 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_H
# define ENEMY_H

# define TEXTURE_COUNT	5

typedef enum e_type
{
	PAWN,
	BISHOP,
	ROOK
}	t_type;

/*
*	Descritpion: This is our enemy actor class.
*/
typedef struct s_enemy
{
	int		x;
	int		y;
	int		**control_zone;
	t_type	type;
	void	*textures[TEXTURE_COUNT];
}	t_enemy;

int	**get_control_zone(t_type type)
{
	return (NULL);
}

#endif