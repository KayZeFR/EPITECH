/*
** allumette.c for allum1 in /home/ghikh_r/rendu/CPE_2015_Allum1
** 
** Made by raphael ghikh
** Login   <ghikh_r@epitech.net>
** 
** Started on  Tue Feb  9 15:51:19 2016 raphael ghikh
** Last update Fri Feb 26 15:00:30 2016 Raphael Ghikh
*/

#include "allum.h"

int	count_allum(int *line)
{
  int	i;
  int	nbr;

  i = 0;
  nbr = 4;
  while (i < 4)
    {
      if (line[i] == 0)
	nbr = nbr - 1;
      i++;
    }
  return (nbr);
}
