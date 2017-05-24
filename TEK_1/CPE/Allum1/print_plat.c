/*
** print_plat.c for allum1 in /home/ghikh_r/rendu/CPE_2015_Allum1
** 
** Made by raphael ghikh
** Login   <ghikh_r@epitech.net>
** 
** Started on  Tue Feb  9 15:03:51 2016 raphael ghikh
** Last update Fri Feb 26 15:01:20 2016 Raphael Ghikh
*/

#include "allum.h"

void	print_plateau(int nbr_match, int space_before)
{
  int	i;
  int	espace;

  i = 0;
  while (i < nbr_match)
    {
      my_putstr("|");
      i++;
    }
  espace = 7 - i - space_before;
  while (espace > 0)
    {
      my_putchar(' ');
      espace = espace - 1;
    }
  my_putchar('*');
  my_putchar('\n');
}

void	print_match(int *line)
{
  my_putstr("*********\n");
  my_putstr("*   ");
  print_plateau(line[0], 3);
  my_putstr("*  ");
  print_plateau(line[1], 2);
  my_putstr("* ");
  print_plateau(line[2], 1);
  my_putstr("*");
  print_plateau(line[3], 0);
  my_putstr("*********");
  my_putchar('\n');
}
