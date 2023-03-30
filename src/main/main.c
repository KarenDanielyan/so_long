/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:41:00 by kdaniely          #+#    #+#             */
/*   Updated: 2023/03/30 17:09:59 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <parse.h>
#include <string.h>
#include <errno.h>

void	print_err_msg(int err)
{
	char	*msg;

	msg = ft_strdup(strerror(err));
	ft_printf("%s", msg);
	free(msg);
}

int	main(int ac, char **av)
{
	if (ac > 2)
	{
		print_err_msg(E2BIG);
		exit(EXIT_FAILURE);
	}
	ft_dprintf(STDOUT_FILENO, "Hello World\n");
	parse(NULL);
	return (0);
}
