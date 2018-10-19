/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuteba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 15:08:04 by mmuteba           #+#    #+#             */
/*   Updated: 2018/09/18 15:08:11 by mmuteba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strarrdel(char **strarr)
{
	int index;

	if (strarr)
	{
		index = 0;
		while (strarr[index])
		{
			free(strarr[index]);
			index++;
		}
		free(strarr);
	}
	strarr = NULL;
}
