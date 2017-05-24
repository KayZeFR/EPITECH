##
## Makefile for makefile in /home/ghikh_r/rendu/Piscine_C_J10
## 
## Made by raphael ghikh
## Login   <ghikh_r@epitech.net>
## 
## Started on  Mon Oct 12 08:56:35 2015 raphael ghikh
## Last update Mon Oct 12 16:54:17 2015 raphael ghikh
##

SRCS	= my_putchar.c \
	  my_isneg.c \
          my_put_nbr.c \
          my_swap.c \
          my_putstr.c \
          my_strlen.c \
          my_getnbr.c \
          my_sort_int_tab.c \
          my_power_rec.c \
          my_square_root.c \
          my_is_prime.c \
          my_find_prime_sup.c \
          my_strcpy.c \
          my_strncpy.c \
          my_revstr.c \
          my_strstr.c \
          my_strcmp.c \
          my_strncmp.c \
          my_strupcase.c \
          my_strlowcase.c \
          my_strcapitalize.c \
          my_str_isalpha.c \
          my_str_isnum.c \
          my_str_islower.c \
          my_str_isupper.c \
          my_str_isprintable.c \
          my_showstr.c \
          my_showmem.c \
          my_strcat.c \
          my_strncat.c \

NAME	= libmy.a

NEW_N	= ../libmy.a

OBJS	= $(SRCS:.c=.o)

HEADER	= my.h

NEW_H	= ../../include/my.h

CP	= cp -f

RM	= rm -f

AR	= ar

all:	$(NAME)

$(NAME): $(OBJS)
	$(AR) rc $(NAME) $(OBJS)
	$(CP) $(HEADER) $(NEW_H)
	$(CP) $(NAME) $(NEW_N)

clean:	
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME) $(NEW_H) $(NEW_N)

re:	fclean all
