##
## Makefile for irc in /home/kayzefr/EPITECH/TEK/PSU_2016_myirc
## 
## Made by Raphaël Ghikh
## Login   <raphael.ghikh@epitech.eu>
## 
## Started on  Sat May 27 10:55:44 2017 Raphaël Ghikh
## Last update Mon Jun 12 00:05:59 2017 Raphaël Ghikh
##

CC		=	gcc -g

INC		=	include

CFLAGS		=	-W -Wall -Wextra -I$(INC) -D_GNU_SOURCE

RM		=	rm -f

SERVER		=	sources/server

CLIENT		=	sources/client

NAME_SERVER	=	server

NAME_CLIENT	=	client

SRC_SERVER	=	$(SERVER)/main.c		\
			$(SERVER)/my_functions.c	\
			$(SERVER)/my_functions2.c	\
			$(SERVER)/gest_errors_cmd.c	\
			$(SERVER)/gest_errors_cmd2.c	\
			$(SERVER)/gest_boucle_cmd.c	\
			$(SERVER)/gest_boucle_cmd2.c	\
			$(SERVER)/my_aff_msg.c		\
			$(SERVER)/server.c		\
			$(SERVER)/gest_users.c		\
			$(SERVER)/new_client.c		\
			$(SERVER)/new_server.c		\
			$(SERVER)/ut_channels.c		\
			$(SERVER)/ut_sockets.c		\
			$(SERVER)/ut_users.c		\
			$(SERVER)/commands.c		\
			$(SERVER)/commands2.c		\
			$(SERVER)/commands3.c		\
			$(SERVER)/ut_buffer.c		\
			$(SERVER)/my_str_to_wordtab.c	\
			$(SERVER)/init_buffer.c		\
			$(SERVER)/ut_socks.c

SRC_CLIENT	=	$(CLIENT)/client.c		\
			$(CLIENT)/select.c		\
			$(CLIENT)/rserv.c		\
			$(CLIENT)/buffer.c		\
			$(CLIENT)/channel.c		\
			$(CLIENT)/my_str_to_wordtab.c	\
			$(CLIENT)/wrserv.c		\
			$(CLIENT)/object.c		\
			$(CLIENT)/command.c		\
			$(CLIENT)/error.c		\
			$(CLIENT)/file.c		\
			$(CLIENT)/return_msg.c		\
			$(CLIENT)/return_msg2.c		\
			$(CLIENT)/strcat.c		\
			$(CLIENT)/user.c		\
			$(CLIENT)/write_c.c		\

OBJS		=	$(SRC_SERVER:.c=.o)

OBJC		=	$(SRC_CLIENT:.c=.o)


all		:
			@$(MAKE) --no-print-directory $(NAME_SERVER)
			@$(MAKE) --no-print-directory $(NAME_CLIENT)

server		:	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME_SERVER)

client		:	$(OBJC)
			$(CC) $(CFLAGS) $(OBJC) -o $(NAME_CLIENT) -lncurses

clean		:
			$(RM) $(OBJS) $(OBJC)

fclean		:	clean
			$(RM) $(NAME_SERVER) $(NAME_CLIENT)

re		:	fclean all
