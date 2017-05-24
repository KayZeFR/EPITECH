##
## Makefile for allum1 in /home/ghikh_r/rendu/CPE_2015_Allum1
## 
## Made by raphael ghikh
## Login   <ghikh_r@epitech.net>
## 
## Started on  Wed Feb 17 07:23:43 2016 raphael ghikh
## Last update Fri Feb 26 15:27:39 2016 Raphael Ghikh
##

CC	=	gcc

CFLAGS	+=	-Wall -Werror -Wextra

NAME	=	allum1

SRCS	=	allumette.c \
		game_player_one.c \
		game_player_two.c \
		get_next_line.c \
		print_plat.c \
		my_functions.c \
		main.c 

OBJS	=	$(SRCS:.c=.o)

RM	=	rm -f

all:		$(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
