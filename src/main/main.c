/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:48:57 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/15 22:52:23 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "events.h"
#include "parse.h"

static void	child(int ac, char **av, int fd[2])
{
	t_game	game;

	close(fd[0]);
	game.write_fd = fd[1];
	if (ac > 2 || ac == 1)
	{
		if (ac == 1)
			ft_printf("Error:\nArgument list too short.\n");
		else
			ft_printf("Error:\n%s.\n", strerror(E2BIG));
		exit(EXIT_FAILURE);
	}
	game = parse(av[1]);
	init_map(&game);
	mlx_hook(game.window, ON_DESTROY, 1L << 2, &on_exit_destroy, &game);
	mlx_hook(game.window, ON_KEYDOWN, 1 << 0L, &on_exit_keypress, &game);
	mlx_hook(game.window, ON_KEYUP, 1 << 1L, &on_key_press, &game);
	mlx_loop_hook(game.mlx, &default_loop, &game);
	mlx_loop(game.mlx);
}

int	main(int ac, char **av)
{
	int		pid;
	int		status;
	int		fd[2];

	pipe(fd);
	pid = fork();
	if (pid == 0)
		child(ac, av, fd);
	close(fd[1]);
	waitpid(pid, NULL, 0);
	read(fd[0], &status, sizeof(int));
	msg_window(status);
	return (0);
}
