/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuteba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 17:32:59 by mmuteba           #+#    #+#             */
/*   Updated: 2018/09/18 14:34:00 by mmuteba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_token		read_piece(int height, int width, int player)
{
	int		row;
	char	*line;
	t_token token;

	token.x = width;
	token.y = height;
	token.xo = player == 1 ? 'O' : 'X';
	token.s = (char **)malloc(sizeof(char *) * (height + 1));
	row = -1;
	while (++row < height && (get_next_line(0, &line)))
		token.s[row] = ft_strsub(line, 0, width);
	token.s[row] = NULL;
	return (token);
}

int			read_game(int height, int width, int player)
{
	t_game	game;
	int		row;
	int		piece_height;
	int		piece_width;
	char	*line;

	game.x = width;
	game.y = height;
	game.board = (char **)malloc(sizeof(char *) * (height + 1));
	row = -1;
	while (++row < height && (get_next_line(0, &line)))
		game.board[row] = ft_strsub(line, 4, width);
	game.board[row] = NULL;
	get_next_line(0, &line);
	piece_height = ft_atoi(&line[6]);
	piece_width = ft_atoi(&line[8]);
	game.token = read_piece(piece_height, piece_width, player);
	return (move_list(game, game.token));
}
