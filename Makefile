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

LIBNAME = libmshell.a
NAME = minishell

DIRLIB = ./libft/
DIRSRC = ./srcs/
INCLS = ./includes/
INCLIB = ./libft/includes/
FLAGS = -Wall -Wextra -Werror
INCLUDES = -I $(INCLS)

lib: $(LIBNAME)

all: $(NAME)

$(LIBNAME):
	gcc $(FLAGS) -c $(DIRSRC)*.c $(INCLUDE)
	ar rcs $(LIBNAME) *.o

libdebug:
	gcc $(FLAGS) -c $(DIRSRC)*.c $(INCLUDE) -g
	ar rcs $(LIBNAME) *.o

libsanitize:
	gcc $(FLAGS) -c $(DIRSRC)*.c $(INCLUDE) -g -fsanitize=address
	ar rcs $(LIBNAME) *.o

$(NAME):
	gcc $(FLAGS) -c $(DIRSRC)*.c $(INCLUDE)
	ar rcs $(LIBNAME) *.o
	$(MAKE) -C $(DIRLIB)
	mv $(DIRLIB)libft.a .
	gcc $(FLAGS) $(INCLUDE) -L. -lmshell -lft main.c -o $(NAME)

debug: libdebug
	$(MAKE) debug -C $(DIRLIB)
	mv $(DIRLIB)libft.a .
	gcc $(FLAGS) $(INCLUDE) -L. -lmshell -lft main.c -o $(NAME) -g

sanitize: libsanitize
	$(MAKE) sanitize -C $(DIRLIB)
	gcc $(FLAGS) $(INCLUDE) -L. -lmshell -lft main.c -o $(NAME) -g -fsanitize=address

clean:
	rm -rf *.o
	rm -rf $(DIRSRC)*.o
	rm -rf $(DIRLIB)*.o

fclean: clean
	rm -rf $(NAME)
	rm -rf $(LIBNAME)
	rm -rf libft.a

re: fclean all

