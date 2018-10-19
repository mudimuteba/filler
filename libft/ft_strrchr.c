/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuteba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 17:27:10 by mmuteba           #+#    #+#             */
/*   Updated: 2018/07/05 15:04:55 by mmuteba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *s_index_zero;

	s_index_zero = s;
	while (*s != '\0')
		s++;
	while (*s != (char)c && *s != *s_index_zero)
		s--;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
