/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:08:16 by kdaniely          #+#    #+#             */
/*   Updated: 2023/03/31 17:10:51 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_helper.h"

static void	check_on_nl(char *line)
{
	if (ft_strcmp(line, "\n") == 0)
	{
		ft_printf("Error\nMap contains an empty line.\n");
		exit(EXIT_FAILURE);
	}
}

static char	*read_file(int fd)
{
	char	*feed;
	char	*line;
	char	*tmp;

	feed = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		check_on_nl(line);
		if (!feed)
			feed = ft_strdup(line);
		else
		{
			tmp = feed;
			feed = ft_strjoin(feed, line);
			free(tmp);
		}
		free(line);
	}
	if (!feed)
	{
		ft_printf("Error\nEmpty File.\n");
		exit(EXIT_FAILURE);
	}
	return (feed);
}

char	**get_map(int fd)
{
	char	*feed;
	char	**split;

	feed = read_file(fd);
	if (feed[ft_strlen(feed) - 1] == '\n')
	{
		ft_printf("Error\nRedundant new line at end of the map.\n");
		exit(EXIT_FAILURE);
	}
	split = ft_split(feed, '\n');
	if (!split)
	{
		ft_printf("Error\nInsufficient Memory.\n");
		exit(EXIT_FAILURE);
	}
	free(feed);
	return (split);
}
