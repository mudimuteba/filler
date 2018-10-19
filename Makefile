# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmuteba <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/12 12:43:28 by mmuteba           #+#    #+#              #
#    Updated: 2018/09/18 14:17:22 by mmuteba          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler

CC = gcc $(FLAGS)

FLAGS = -Wall -Werror -Wextra

SRC = src/*

all:	$(NAME)

$(NAME):
		@make -C libft/
		@$(CC) -o $(NAME) $(SRC) libft/libft.a -I./includes/
		@echo "$(NAME) is ready to use."

clean:
	@make clean -C libft/

fclean: clean
	@make fclean -C libft/
	@rm $(NAME)

re: fclean all
