/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 00:39:43 by kdaniely          #+#    #+#             */
/*   Updated: 2023/03/29 14:29:50 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"

size_t	printf_strlen(const char *str)
{
	int	len;

	len = 0;
	while (*(str + len))
		len ++;
	return (len);
}
