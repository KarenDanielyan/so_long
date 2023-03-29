/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:50:08 by kdaniely          #+#    #+#             */
/*   Updated: 2023/03/29 14:45:18 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"

int	ft_putunbr_fd(int fd, unsigned int nbr)
{
	char	*num;
	int		count;

	num = ft_itoa_base(nbr, DECIMAL);
	count = ft_putstr_fd(fd, num);
	free(num);
	return (count);
}

int	ft_putnbr_fd(int fd, int nbr)
{
	char	*num;
	int		count;

	count = 0;
	num = ft_itoa_base(nbr, DECIMAL);
	count += ft_putstr_fd(fd, num);
	free(num);
	return (count);
}

int	ft_putptr_fd(int fd, uintptr_t ptr, char *base)
{
	uintptr_t	temp;
	uintptr_t	base_len;	
	int			count;

	temp = ptr;
	count = 0;
	base_len = ft_strlen(base);
	if (temp > (base_len - 1))
	{
		count += ft_putptr_fd(fd, temp / base_len, base);
		count += ft_putptr_fd(fd, temp % base_len, base);
	}
	else
	{
		write(fd, (base + temp), 1);
		count ++;
	}
	return (count);
}

int	ft_puthex_fd(int fd, unsigned int nbr, const char *f_str)
{
	char	*num;
	int		count;

	count = 0;
	if (*f_str == 'x')
		num = ft_itoa_base(nbr, L_HEX);
	else
		num = ft_itoa_base(nbr, B_HEX);
	count += ft_putstr_fd(fd, num);
	free(num);
	return (count);
}
