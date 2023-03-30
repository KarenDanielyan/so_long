/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:38:53 by kdaniely          #+#    #+#             */
/*   Updated: 2023/03/30 13:09:27 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

/*
*	Description: This is our playable actor class.
*/
typedef struct s_player
{
	/* data */
}	t_player;

/*
*	Descritpion: This is our enemy actor class.
*/
typedef struct	s_enemy
{

}	t_enemy;

/*
*	Description: Our game instance. It contains
*	everything we need to know to figure out status
*	of our game. There is only one game instance in our
*	architecture.
*/
typedef struct	s_game
{
	// TODO: add more fields that we need.
	t_player	*player;
	t_enemy		*enemy;
}	t_game;

#endif