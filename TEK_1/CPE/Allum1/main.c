/*
** main.c for allum1 in /home/ghikh_r/rendu/CPE_2015_Allum1
** 
** Made by raphael ghikh
** Login   <ghikh_r@epitech.net>
** 
** Started on  Tue Feb  9 15:02:22 2016 raphael ghikh
** Last update Fri Feb 26 16:08:49 2016 Raphael Ghikh
*/

#include <stdlib.h>
#include <time.h>
#include "allum.h"

int	main()
{
  int	*line;

  line = malloc(sizeof(int));
  line[0] = 1;
  line[1] = 3;
  line[2] = 5;
  line[3] = 7;
  print_match(line);
  my_putchar('\n');
  while (count_allum(line) != 0)
    {
      if (player_one(line) == 1)
	return (1);
      if (count_allum(line) == 0)
	return (EXIT_SUCCESS);
      player_two(line);
      if (count_allum(line) == 0)
	return (EXIT_SUCCESS);
      my_putchar('\n');
    }
  return (0);
  free(line);
}
