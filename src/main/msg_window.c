/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 21:32:44 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/16 00:13:34 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

typedef struct s_win
{
	void	*mlx;
	void	*window;
}	t_win;

static int	on_kill(t_win *tmp)
{
	mlx_destroy_window(tmp->mlx, tmp->window);
	if (FREEMLX)
		free(tmp->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

static int	on_kpress(int key, t_win *tmp)
{
	if (key == ESC)
		on_kill(tmp);
	return (0);
}

static void put_message(t_status status, t_win *tmp)
{
	if (status == WIN)
	{
		mlx_string_put(tmp->mlx, tmp->window, 50, 50,
				0x78FF00, "Good Job :)");
	}
	if (status == LOSE)
	{
		mlx_string_put(tmp->mlx, tmp->window, 50, 50,
				0x78FF00, "Slime Ate You!!!");
	}
	if (status == SIGEXIT)
	{
		mlx_string_put(tmp->mlx, tmp->window, 50, 50,
				0x78FF00, "Game exited abnormally.");
	}
}

void	msg_window(t_status status)
{
	t_win	tmp;

	tmp.mlx = mlx_init();
	tmp.window = mlx_new_window(tmp.mlx, 500, 100, "Message Window");
	put_message(status, &tmp);
	mlx_hook(tmp.window, ON_KEYDOWN, 1 << 0L, &on_kpress, &tmp);
	mlx_hook(tmp.window, ON_DESTROY, 1L << 2, &on_kill, &tmp);
	mlx_loop(tmp.mlx);
}