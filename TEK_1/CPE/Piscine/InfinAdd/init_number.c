/*
** init_number.c for init in /home/ganem-_j/rendu/Piscine_C_infinadd
** 
** Made by johan ganem--brunet
** Login   <ganem-_j@epitech.net>
** 
** Started on  Mon Oct 19 15:51:29 2015 johan ganem--brunet
** Last update Mon Oct 19 19:13:32 2015 johan ganem--brunet
*/

#include "infinadd.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      i = i + 1;
    }
  return (i);
}

void	init_number(t_number *n, char *str)
{
  int	i;
  n->str = str;
  n->lenght = my_strlen(str);
  n->idx = n->lenght;
  i = 0;
  while (i < n->lenght)
    {
      n->str[i] -= '0';
      i = i + 1;
    }
}
