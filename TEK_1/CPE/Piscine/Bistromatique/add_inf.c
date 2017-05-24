/*
** add.c for addition in /home/ghikh_r/rendu/test_infadd
** 
** Made by Raphael Ghikh
** Login   <ghikh_r@epitech.net>
** 
** Started on  Tue Oct 20 10:43:56 2015 Raphael Ghikh
** Last update Sun Nov  1 16:39:33 2015 johan ganem--brunet
*/

#include <stdlib.h>
#include "include/my.h"

int	size_number(char *n1, char *n2)
{
  int	length1;
  int	length2;

  length1 = 0;
  length2 = 0;
  while (n1[length1] != 0)
    {
      length1 = length1 + 1;
    }
  while (n2[length2] != 0)
    {
      length2 = length2 + 1;
    }
  change(n1, n2, length1, length2);
}

int	change(char *n1, char *n2, int length1, int length2)
{
  if (length1 < length2)
    {
      space(length2, length1, n2, n1);
    }
  else
    {
      space(length1, length2, n1, n2);
    }
}

int	space(int length1, int length2, char *n1, char *n2)
{
  char	*new_n2;
  int	j;
  int	i;
  int	nb_zero;
  int	retenue;

  nb_zero = length1 - length2;
  i = 0;
  j = 0;
  retenue = 0;
  new_n2 = malloc(sizeof(char)*(length1 + 1));
  while (i != nb_zero)
    {
      new_n2[i] = '0';
      i = i + 1;
    }
  while (n2[j] != 0)
    {
      new_n2[i] = n2[j];
      i = i + 1;
      j = j + 1;
    }
  if (length1 == 1 && length2 == 1)
      calc_diz(n1, new_n2, length1);
  else
    calc(n1, new_n2, length1, retenue);
}

int	calc_diz(char *n1, char *n2, int length1)
{
  int   *result;
  int   i;
  int   j;
  int   k;
  int   length3;

  k = 0;
  length3 = length1;
  result = malloc(sizeof(char)*(length3 + 1));
  i = n1[length3 - 1];
  j = n2[length3 - 1];
  k = i + j - 96;
  if (k < 10)
    {
      my_put_nbr(k);
    }
  else
    {
      my_putchar('1');
      my_put_nbr(k % 10);
    }
}

int	calc(char *n1, char *n2, int length1, int retenue)
{
  int	*result;
  int	i;
  int	j;
  int	k;
  int	length3;
  int	count;

  length3 = length1;
  result = malloc(sizeof(char)*(length3 + 1));
  while (length3 != 0)
    {
      count = 0;
      i = n1[length3 - 1];
      j = n2[length3 - 1];
      k = i + j + retenue - 96;
      if (k >= 10)
	{
	  k = (i + j + retenue - 96) % 10;
	  if (k == 0)
	      count = 1;
	  retenue = 1;
	}
      else
	  retenue = 0;
      result[length3] = k;
      length3 = length3 - 1;
    }
  disp(length1, count, result, k);
}
