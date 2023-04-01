/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extension_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 19:49:36 by kdaniely          #+#    #+#             */
/*   Updated: 2023/04/01 14:54:14 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_helper.h"
#include <libft.h>

#define MAPPATH "./assets/maps"

static int	open_from(char *path, char *file)
{
	char	*file_w_slash;
	char	*join;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		file_w_slash = ft_strjoin("/", file);
		join = ft_strjoin(path, file_w_slash);
		fd = open(join, O_RDONLY);
		free(join);
		free(file_w_slash);
	}
	return (fd);
}

int	extension_check(char *file)
{
	int		fd;

	fd = open_from(MAPPATH, file);
	if (fd == -1)
	{
		ft_printf("Error\n%s\n", strerror(ENOENT));
		exit(EXIT_FAILURE);
	}
	if (ft_strcmp(ft_strrchr(file, '.'), ".ber") != 0)
	{
		ft_printf("Error\nWrong file format.\n");
		exit(EXIT_FAILURE);
	}
	return (fd);
}
