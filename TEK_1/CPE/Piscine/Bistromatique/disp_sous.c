/*
** disp_sous.c for display inf in /home/ganem-_j/rendu/Piscine_C_bistromathique
** 
** Made by johan ganem--brunet
** Login   <ganem-_j@epitech.net>
** 
** Started on  Sun Nov  1 14:57:24 2015 johan ganem--brunet
** Last update Sun Nov  1 17:15:00 2015 johan ganem--brunet
*/

#include "include/my.h"

int     disp(int length1, int *result)
{
  int   i;

  i = 1;
  while (length1 != 0)
    {
      if (i == 1 && result[i] == 0)
	  my_putchar('\0');
      else
	{
	my_put_nbr(result[i]);
    	}
      i = i + 1;
      length1 = length1 - 1;
    }
}
