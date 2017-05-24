/*
** main_add.c for main add in /home/ganem-_j/rendu/Piscine_C_bistromathique
** 
** Made by johan ganem--brunet
** Login   <ganem-_j@epitech.net>
** 
** Started on  Sun Nov  1 14:12:59 2015 johan ganem--brunet
** Last update Sun Nov  1 16:07:21 2015 Raphael Ghikh
*/

#include "include/my.h"

int     main(int ac, char **av)
{
  char  *n1;
  char  *n2;

  if (ac ==  3)
    {
      n1 = av[1];
      n2 = av[2];
      size_number(n1, n2);
      my_putchar('\n');
    }
  else
    {
      my_putchar('\n');
      return (1);
    }
}
