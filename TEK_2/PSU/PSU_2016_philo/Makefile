##
## Makefile for philo in /home/kayzefr/EPITECH/tek2/PSU_tek2/PSU_2016_philo
## 
## Made by Raphaël Ghikh
## Login   <raphael.ghikh@epitech.eu>
## 
## Started on  Fri Mar 10 16:31:01 2017 Raphaël Ghikh
## Last update Sun Mar 19 12:31:24 2017 dylan bonhomme
##

CC	=	gcc

RM	=	rm -f

CFLAGS	+=	-I. -W -Wall -Wextra -Werror -g3

LDFLAGS	=	-pthread -L. -lriceferee -Wl,-rpath=.

NAME	=	philo

SRCS	=	gest_erreur.c		\
		gest_thread.c		\
		actions_philosophe.c	\
		main.c

OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(LDFLAGS) $(CFLAGS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
