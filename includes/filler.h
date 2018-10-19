/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuteba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 18:11:53 by mmuteba           #+#    #+#             */
/*   Updated: 2018/09/18 12:51:20 by mmuteba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"

typedef struct		s_token
{
	int		x;
	int		y;
	char	xo;
	char	**s;
}					t_token;

typedef struct		s_game
{
	int		x;
	int		y;
	char	**board;
	t_token token;
}					t_game;

typedef struct		s_moves
{
	int				x;
	int				y;
	struct s_moves	*next;
}					t_moves;

int					read_game(int height, int width, int player);
t_token				read_piece(int height, int width, int player);
int					valid_move(t_game game, t_token token, int row, int col);
void				add_node(t_moves **moves, int row, int col);
int					move_list(t_game board, t_token token);
int					best_move(t_moves *moves);

#endif
