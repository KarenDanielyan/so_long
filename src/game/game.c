/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:07:59 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/15 22:49:13 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <libft.h>
#include <signal.h>

static int	audio_init(void)
{
	const char	*args[3] = {AUDIO, BGRND_MUSIC, NULL};
	int			pid;

	pid = fork();
	if (pid == 0)
		exit(execvp(AUDIO, (char **)args));
	return (pid);
}

void	new_game(t_game *game, char **map)
{
	game->mlx = mlx_init();
	game->audio_pid = audio_init();
	new_assets(game->mlx, &game->assets);
	new_map(&(game->map), map);
	game->w_height = (game->map->height * TEXTURE_SIZE);
	game->w_width = (game->map->width * TEXTURE_SIZE) + EVENT_WINDOW_SIZE;
	game->c_count = get_col_count(game->map);
	game->e_count = get_en_count(game->map);
	game->c_left = game->c_count;
	game->c_mov = 0;
	new_game_collectibles(&game);
	new_enemies(&game);
	new_game_exit(&game);
	new_player(game, &game->player);
	set_tile_textures(game->assets, game->map);
	game->window = mlx_new_window(game->mlx, game->w_width,
			game->w_height, GAME_TITLE);
}

void	delete_game(t_game *game)
{
	kill(game->audio_pid, SIGKILL);
	while (wait(NULL) != -1)
		;
	delete_map(game->map);
	delete_assets(game->mlx, game->assets);
	mlx_destroy_window(game->mlx, game->window);
	free(game->cols);
	free(game->exit);
	free(game->player);
	if (game->e_count != 0)
		free(game->enemy);
	if (FREEMLX)
		free(game->mlx);
}
