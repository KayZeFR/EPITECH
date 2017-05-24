##
## Makefile for Makefile in /home/ghikh_r/rendu/Piscine_C_bistromathique/lib/my
## 
## Made by Raphael Ghikh
## Login   <ghikh_r@epitech.net>
## 
## Started on  Mon Oct 19 11:19:39 2015 Raphael Ghikh
## Last update Tue Oct 27 09:22:18 2015 Raphael Ghikh
##

SRC =	my_find_prime_sup.c \
	my_getnbr.c \
	my_isneg.c \
	my_is_prime.c \
	my_power_rec.c \
	my_putchar.c \
	my_put_nbr.c \
	my_putstr.c \
	my_revstr.c \
	my_showmem.c \
	my_showstr.c \
	my_sort_int_tab.c \
	my_square_root.c \
	my_strcapitalize.c \
	my_strcat.c \
	my_strcmp.c \
	my_strcpy.c \
	my_str_isalpha.c \
	my_str_islower.c \
	my_str_isnum.c \
	my_str_isprintable.c \
	my_str_isupper.c \
	my_strlen.c \
	my_strlowcase.c \
	my_strncmp.c \
	my_strncpy.c \
	my_strstr.c \
	my_strupcase.c \
	my_swap.c \
	my_strncat.c \

NAME =	libmy.a

OBJ = 	$(SRC:.c=.o)

RM =	rm -f

all:	$(NAME)

$(NAME):
	gcc -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	cp $(NAME) ..
	cp my.h ../../include

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(NAME)


re: fclean all
