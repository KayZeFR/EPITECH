/*
** test2.c for test in /home/ghikh_r/rendu/Bootstrap_Pushwap/test
** 
** Made by Raphael Ghikh
** Login   <ghikh_r@epitech.net>
** 
** Started on  Wed Nov 18 15:29:16 2015 Raphael Ghikh
** Last update Sun Nov 22 12:25:19 2015 Raphael Ghikh
*/

#include <stdio.h>
#include <stdlib.h>

int     *swap_elem_two(int *l_a, int index, int index2)
{
  int   swap;

  swap = l_a[index];
  l_a[index] = l_a[index2];
  l_a[index2] = swap;
  return (l_a);
}

int     sa(int *l_a, int size)
{
  int   i;
  int	test;

  i = 0;
  while (i != 1)
    {
      swap_elem_two(l_a, i, i + 1);
      i = i + 1;
    }
  if (test == 0)
    my_putchar(' ');
  else
    test = 0;
  my_putstr("sa");
}

int     ra(int *l_a, int size)
{
  int   i;
  int	test;

  i = 0;
  while (i != size - 1)
    {
      l_a = swap_elem_two(l_a, i, i + 1);
      i = i + 1;
    }
  if (test == 0)
    my_putchar(' ');
  else
    test = 0;
  my_putstr("ra");
}

int	check(int size, int *l_a)
{
  int	i;

  i = 0;
  while (i < size - 1)
    {
      if (l_a[i] > l_a[i + 1])
	return (1);
      i = i + 1;
    }
  return (0);
}

int	push_swap(int size, int *l_a)
{
  int	i;
  int	test;

  test = 1;
  while (check(size, l_a))
    {
      i = 0;
      while (i < size - 1)
	{
	  if (l_a[0] > l_a[1])
	    {
	      sa(l_a, size);
	    }
	  if (l_a[0] < l_a[1])
	    {
	      ra(l_a, size);
	    }
	  i = i + 1;
	}
      ra(l_a, size);
    }
  return (*l_a);
}
