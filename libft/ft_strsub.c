/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuteba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 18:50:03 by mmuteba           #+#    #+#             */
/*   Updated: 2018/07/07 16:04:27 by mmuteba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	index;

	index = -1;
	str = ft_strnew(len);
	if (!s || !str)
		return (NULL);
	while (++index < len)
		str[index] = s[start + index];
	return (str);
}
