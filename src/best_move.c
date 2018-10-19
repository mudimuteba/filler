/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuteba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 12:32:37 by mmuteba           #+#    #+#             */
/*   Updated: 2018/09/18 14:34:16 by mmuteba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			valid_move(t_game game, t_token token, int row, int col)
{
	int		t_r;
	int		t_c;
	int		overlap;

	t_r = -1;
	overlap = 0;
	while (++t_r < token.y)
	{
		t_c = -1;
		while (++t_c < token.x)
		{
			if (game.board[row + t_r][col + t_c] != '.' &&
					game.board[row + t_r][col + t_c] != token.xo &&
					game.board[row + t_r][col + t_c] != token.xo + 32 &&
					token.s[t_r][t_c] == '*')
				return (0);
			if ((game.board[row + t_r][col + t_c] == token.xo ||
						game.board[row + t_r][col + t_c] == token.xo + 32) &&
					token.s[t_r][t_c] == '*')
				overlap++;
		}
	}
	return (overlap);
}

void		add_node(t_moves **moves, int row, int col)
{
	t_moves *temp;

	temp = (t_moves *)malloc(sizeof(t_moves));
	temp->y = row;
	temp->x = col;
	temp->next = *moves;
	*moves = temp;
}

int			best_move(t_moves *moves)
{
	static int		play_upfield = 1;
	t_moves			*head;
	t_moves			*trash;

	head = moves;
	if (play_upfield == 1 && moves)
		while (head->next)
			head = head->next;
	play_upfield == 1 ? play_upfield = 0 : play_upfield;
	moves ? ft_putnbr(head->y) : ft_putnbr(0);
	ft_putchar(' ');
	moves ? ft_putnbr(head->x) : ft_putnbr(0);
	ft_putchar('\n');
	if (!moves)
		return (0);
	while (moves)
	{
		trash = moves;
		moves = moves->next;
		free(trash);
	}
	return (1);
}

int			move_list(t_game board, t_token token)
{
	int			row;
	int			col;
	t_moves		*moves;

	row = -1;
	moves = NULL;
	while (++row <= board.y - token.y)
	{
		col = -1;
		while (++col <= board.x - token.x)
			if (valid_move(board, token, row, col) == 1)
				add_node(&moves, row, col);
	}
	return (best_move(moves));
}
