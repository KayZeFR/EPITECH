##
## Makefile for Makefile in /home/vezia_l/rendu/PSU_2015_myftp
##
## Made by louis vezia
## Login   <vezia_l@epitech.net>
##
## Started on  Tue May 10 14:49:23 2016 louis vezia
## Last update Thu May 18 23:02:08 2017 Raphaël Ghikh
##

SRC			=       main.c	\
				change.c	\
				commands.c	\
				data_transfer.c	\
				dir.c	\
				log_ftp.c	\
				my_get_next_line.c \
				my_str_to_word_tab.c \
				run.c	\
				send_msg.c	\
				my_functions.c	\

CC                      =       gcc

RM                      =       rm -f

NAME                    =       server

CFLAGS                  +=      -Wall -Wextra -Werror

OBJ               	=       $(SRC:.c=.o)

$(NAME)			:       $(OBJ)
				@$(CC) -o $(NAME) $(OBJ)

all			:	$(NAME)
				@echo -e "\e[0;32mObjects creates !\e[0;m"
				@echo -e "\e[0;32mServer creates !\e[0;m"

clean			:
				@echo -e "\e[0;33mObjects deleted !\e[0;m"
				@$(RM) $(OBJ)

fclean			:	clean
				@echo -e "\e[0;33mServer deleted !\e[0;m"
				@$(RM) $(NAME)

re			:	fclean all

.PHONY			:	all clean fclean re
