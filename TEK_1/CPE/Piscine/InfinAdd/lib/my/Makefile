##
## Makefile for make in /home/ganem-_j/rendu/Piscine_C_infinadd/lib/my
## 
## Made by johan ganem--brunet
## Login   <ganem-_j@epitech.net>
## 
## Started on  Mon Oct 19 15:36:34 2015 johan ganem--brunet
## Last update Mon Oct 19 15:47:11 2015 johan ganem--brunet
##

cc		=	gcc

NAME		=	poc

SRCS		=	main.c add.c

OBJS		=	$(SRCS:.c=.o)

CFLAGS		=	-W -Wall -Wextra

RM		=	rm -rf

all		:	$(NAME)

$(NAME)		:	$(OBJS)
			$(CC) -o $(NAME) $(OBJS)

clean		:
			$(RM) $(OBJS)

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY		:	all clean fclean re

