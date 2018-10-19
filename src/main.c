/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuteba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 17:32:59 by mmuteba           #+#    #+#             */
/*   Updated: 2018/09/18 14:33:49 by mmuteba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			main(void)
{
	int		player;
	int		board_height;
	int		board_width;
	char	*line;

	get_next_line(0, &line);
	player = ft_atoi(&line[10]);
	while (1)
	{
		get_next_line(0, &line);
		board_height = ft_atoi(&line[8]);
		board_width = ft_atoi(&line[11]);
		get_next_line(0, &line);
		if (read_game(board_height, board_width, player) == 0)
			break ;
	}
	return (0);
}
