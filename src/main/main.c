/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:41:00 by kdaniely          #+#    #+#             */
/*   Updated: 2023/03/29 20:21:16 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <parse.h>

int	main(void)
{
	ft_dprintf(STDOUT_FILENO, "Hello World\n");
	parse(NULL);
	return (0);
}
