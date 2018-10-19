/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuteba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 17:31:29 by mmuteba           #+#    #+#             */
/*   Updated: 2018/07/12 18:55:34 by mmuteba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int i;
	unsigned int j;
	unsigned int k;

	i = 0;
	if (needle[i] == '\0' && haystack[i] == '\0')
		return ((char*)haystack);
	while (haystack[i])
	{
		j = i;
		k = 0;
		if (needle[k] == '\0')
			return ((char*)haystack + i);
		while (haystack[j] && needle[k] && haystack[j] == needle[k] && j < len)
		{
			k++;
			j++;
			if (needle[k] == '\0')
				return ((char*)haystack + i);
		}
		i++;
	}
	return (0);
}
