/*
** main_sous.c for soustraction in /home/ghikh_r/rendu/Piscine_C_bistromathique
** 
** Made by Raphael Ghikh
** Login   <ghikh_r@epitech.net>
** 
** Started on  Sun Nov  1 17:29:18 2015 Raphael Ghikh
** Last update Sun Nov  1 17:29:25 2015 Raphael Ghikh
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
