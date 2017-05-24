/*
** main2.c for main2 in /home/ganem-_j/rendu/Piscine_C_bistromathique
** 
** Made by johan ganem--brunet
** Login   <ganem-_j@epitech.net>
** 
** Started on  Tue Oct 27 09:15:45 2015 johan ganem--brunet
** Last update Sun Nov  1 16:06:58 2015 Raphael Ghikh
*/

#include "include/my.h"

int	check_arg1(char *str)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  if (my_strlen(str) < 2)
    {
      my_putstr("Error");
      return (1);
    }
  while (str[i] != 0)
    {
      j = i + 1;
      while (str[j] != 0)
	{
	  if (str[j] == str[i])
	    {
	      my_putstr("Error");
	      return (1);
	    }
	  j = j + 1;
	}
      i = i + 1;
    }
}

int	check_arg2(char *str)
{
  int	i;
  int	j;

  i = 0;
  if (my_strlen(str) != 7)
    {
      my_putstr("Error");
      return (1);
    }
  while (str[i] != 0)
    {
      j = i + 1;
      while (str[j] != 0)
	{
	  if (str[j] == str[i])
	    {
	      my_putstr("Error");
	      return (1);
	    }
	  j = j + 1;
	}
      i = i + 1;
    }
}

int	check_arg_all(char *str, char *str2)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i] != 0)
    {
      j = 0;
      while (str2[j] != 0)
	{
	  if (str2[j] == str[i])
	    {
	      my_putstr("Error");
	      return (1);
	    }
	  j = j + 1;
	}
      i = i + 1;
    }
}

int	main(int argc, char **argv)
{
  if (argc != 4)
    {
      my_putstr("Usage : ");
      my_putstr(argv[0]);
      my_putstr(" base ops\"()+-*/%\" exp_len");
      return (1);
    }
  check_arg1(argv[1]);
  check_arg2(argv[2]);
  check_arg_all(argv[1], argv[2]);
  check_brackets(argv[1]);
}
