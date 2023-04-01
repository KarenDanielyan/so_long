/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 01:07:44 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/02 01:45:33 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSETS_H
# define ASSETS_H

# define TEXTURE_SIZE 48

# define TP_GROUND_1 "./assets/textures/ground/ground_1.xpm"
# define TP_GROUND_2 "./assets/textures/ground/ground_2.xpm"
# define TP_GROUND_3 "./assets/textures/ground/ground_3.xpm"

# define TP_WALL

/* TODO: Define them when doing character animations.
# define CHAR_IDLE_COUNT 5
# define TP_CHAR_IDLE_1
# define TP_CHAR_IDLE_2
# define TP_CHAR_IDLE_3
# define TP_CHAR_IDLE_4
# define TP_CHAR_IDLE_5
*/

typedef struct s_assets
{
	void	**ground;
	void	*wall;
	/* TODO: Add appropriate pointers to player and enemy characters;
		void	*player;
		void	*enemy;
	*/
}	t_assets;

void	new_assets(t_assets *this);
void	delete_assets(t_assets *this);

#endif