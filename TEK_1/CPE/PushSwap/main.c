/*
** main.c for push_swap.c in /home/ghikh_r/rendu/Bootstrap_Pushwap
** 
** Made by Raphael Ghikh
** Login   <ghikh_r@epitech.net>
** 
** Started on  Sat Nov 21 20:29:11 2015 Raphael Ghikh
** Last update Sat Nov 21 21:12:54 2015 Raphael Ghikh
*/

#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
  int   *l_a;
  int   i;

  i = 0;
  l_a = malloc(sizeof(int)*(ac));
  while (av[i + 1] != 0)
    {
      l_a[i] = my_atoi(av[i + 1]);
      i = i + 1;
    }
  push_swap((ac - 1), l_a);
  my_putchar('\n');
}
