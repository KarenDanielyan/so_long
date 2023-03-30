/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_2d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 22:06:39 by kdaniely          #+#    #+#             */
/*   Updated: 2023/03/31 00:58:21 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strdup_2d(char const **s)
{
	int		i;
	char	**dup;

	i = ft_strlen_2d(s);
	dup = (char **)malloc(i * sizeof(char *));
	i = 0;
	while (*(s + i))
	{
		*(dup + i) = (char *)malloc((ft_strlen(*(s + i)) + 1) * sizeof(char));
		ft_strcpy(*(dup + i), *(s + i));
		i ++;
	}
	return (dup);
}