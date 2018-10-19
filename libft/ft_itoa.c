/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuteba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 16:49:45 by mmuteba           #+#    #+#             */
/*   Updated: 2018/07/13 09:36:43 by mmuteba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numstr_size(long int n)
{
	long int	size;

	size = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = -n;
		size++;
	}
	while (n > 9)
	{
		n = n / 10;
		size++;
	}
	size++;
	return (size);
}

char		*ft_itoa(int n)
{
	char		*str;
	long int	size;
	int			neg;

	neg = 1;
	size = ft_numstr_size(n);
	str = ft_strnew(size);
	if (str == NULL)
		return (NULL);
	str[0] = 48;
	if (n < 0)
	{
		neg = -1;
		str[0] = '-';
	}
	size--;
	while (n)
	{
		str[size] = (((n % 10) * neg) + 48);
		size--;
		n = n / 10;
	}
	return (str);
}
