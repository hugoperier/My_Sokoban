##
## Makefile for Makefile in /home/hugo/Projet/sysUnix/PSU_2016_my_ls_bootstrap
## 
## Made by Hugo Perier
## Login   <hugo@epitech.net>
## 
## Started on  Wed Nov 23 14:20:42 2016 Hugo Perier
## Last update Fri Mar 17 11:46:12 2017 Hugo Perier
##

CC	= gcc

RM	= rm -f

NAME	= my_sokoban

SRCS	= main.c	\
	  getstr.c	\
	  fonc1.c	\
	  fonc2.c	\
	  movecaisse.c	\
	  fonc3.c	\
	  fonc4.c

OBJS	= $(SRCS:.c=.o)

LIB	=  libmy.a

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIB) -o $(NAME) -lncurses

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
