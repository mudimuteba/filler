/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuteba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 17:29:09 by mmuteba           #+#    #+#             */
/*   Updated: 2018/06/27 18:25:52 by mmuteba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	unsigned int i;
	unsigned int j;
	unsigned int k;

	i = 0;
	if (little[i] == '\0' && big[i] == '\0')
		return ((char*)big);
	while (big[i])
	{
		j = i;
		k = 0;
		if (little[k] == '\0')
			return ((char*)big + i);
		while (big[j] && little[k] && big[j] == little[k])
		{
			k++;
			j++;
			if (little[k] == '\0')
				return ((char*)big + i);
		}
		i++;
	}
	return (0);
}
