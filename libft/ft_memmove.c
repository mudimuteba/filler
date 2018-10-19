/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuteba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 16:53:39 by mmuteba           #+#    #+#             */
/*   Updated: 2018/07/06 16:04:24 by mmuteba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*p_dst;
	const char	*p_src;

	p_dst = (char*)dst;
	p_src = (const char*)src;
	if (p_dst <= p_src)
		return (ft_memcpy(p_dst, p_src, len));
	p_dst += len;
	p_src += len;
	while (len--)
		*--p_dst = *--p_src;
	return (dst);
}
