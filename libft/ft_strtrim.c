/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuteba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 15:00:55 by mmuteba           #+#    #+#             */
/*   Updated: 2018/07/07 15:06:28 by mmuteba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	begin;
	size_t	end;
	size_t	len;

	if (!s)
		return (NULL);
	begin = 0;
	end = ft_strlen(s) - 1;
	while (begin < ft_strlen(s) && ft_isspace(s[begin]))
		begin++;
	while (end > begin && ft_isspace(s[end]))
		end--;
	len = end - begin + 1;
	return (ft_strsub(s, begin, len));
}
