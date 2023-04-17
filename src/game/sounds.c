/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sounds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 19:14:57 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/17 14:00:45 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	make_sound(char *sound)
{
	const char	*args[3] = {AUDIO, sound, NULL};
	int			pid;

	pid = fork();
	if (pid == 0)
		exit(execvp(AUDIO, (char **)args));
}
