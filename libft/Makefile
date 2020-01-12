# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcouto <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/30 00:21:14 by mcouto            #+#    #+#              #
#    Updated: 2019/08/30 00:21:18 by mcouto           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

DIRBST = ./binary_tree/
DIRPRINTF = ./printf/
DIRGNL = ./get_next_line/
INCLS = ./includes/
FLAGS = -Wall -Wextra -Werror
INCLUDE = -I $(INCLS)

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(DIRBST)*.c $(DIRPRINTF)*.c $(DIRGNL)*.c *.c $(INCLUDE)
	ar rcs $(NAME) *.o

debug:
	gcc $(FLAGS) -c $(DIRBST)*.c $(DIRPRINTF)*.c $(DIRGNL)*.c *.c $(INCLUDE) -g
	ar rcs $(NAME) *.o

sanitize:
	gcc $(FLAGS) -c $(DIRBST)*.c $(DIRPRINTF)*.c $(DIRGNL)*.c *.c $(INCLUDE) -g -fsanitize=address
	ar rcs $(NAME) *.o

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

