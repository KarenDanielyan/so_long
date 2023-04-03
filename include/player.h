/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:51:00 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/03 19:57:50 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include <libft.h>

# define START_AP	5

/*
*	Description: This is our playable actor class.
*/
typedef struct s_player
{
	int		x;
	int		y;
	void	**textures;
	int		ap;
}	t_player;

#endif