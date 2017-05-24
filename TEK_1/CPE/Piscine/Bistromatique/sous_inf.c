/*
** sous2.c for sous in /home/ganem-_j/rendu/Piscine_C_bistromathique
** 
** Made by johan ganem--brunet
** Login   <ganem-_j@epitech.net>
** 
** Started on  Thu Oct 29 12:03:06 2015 johan ganem--brunet
** Last update Sun Nov  1 17:10:45 2015 johan ganem--brunet
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
  int	i;
  int	j;
  int	k;

  i = 0;
  j = n1[0];
  k = n2[0];
  if (length1 < length2)
    {
      my_putchar('-');
      space(length2, length1, n2, n1);
    }
  else if (length1 == length2)
    {
      while (n1[i] != 0 && j >= k)
	{
	  j = n1[i];
	  k = n2[i];
	  i = i + 1;
	}
      if (i != length1)
	{
	  my_putchar('-');
	  space(length2, length1, n2, n1);
	}
      else 
	space(length1, length2, n1, n2);
    }
  else
    space(length1, length2, n1, n2);
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
  calc(n1, new_n2, length1, retenue);
}

int	calc(char *n1, char *n2, int length1, int retenue)
{
  int	*result;
  int	i;
  int	j;
  int	k;
  int	length3;

  length3 = length1;
  result = malloc(sizeof(char)*(length3 + 1));
  while (length3 != 0)
    {
      i = n1[length3 - 1];
      j = n2[length3 - 1];
      if (i < j)
	{
	  k = i + 10 - j - retenue;
	  retenue = 1;
	}
      else
	{
	  k = i - j - retenue;
	  retenue = 0;
	}
      if (k < 0)
	k = -k;
      result[length3] = k;
      length3 = length3 - 1;
    }
  disp(length1, result, k);
}
