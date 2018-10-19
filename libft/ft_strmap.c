/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuteba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 17:35:18 by mmuteba           #+#    #+#             */
/*   Updated: 2018/07/08 14:31:47 by mmuteba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	char	*ptr_str;

	if (!s || !*s)
		return (NULL);
	if (!(str = ft_strdup(s)))
		return (NULL);
	ptr_str = str;
	while (*s)
		*str++ = f(*s++);
	*str = '\0';
	return (ptr_str);
}
