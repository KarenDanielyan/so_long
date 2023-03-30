/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extension_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 19:49:36 by kdaniely          #+#    #+#             */
/*   Updated: 2023/03/30 18:27:47 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_helper.h"

int	extension_check(char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
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
