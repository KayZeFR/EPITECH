/*
** reorder_numbers.c for  in /home/dacost_f/rendu/Piscine_C_infinadd
** 
** Made by dacosta dylan
** Login   <dacost_f@epitech.net>
** 
** Started on  Mon Oct 19 16:03:10 2015 dacosta dylan
** Last update Mon Oct 19 19:28:46 2015 johan ganem--brunet
*/

#include "infinadd.h"

int	my_swap(int a, int b)
{
  int	c;

  c = a;
  a = b;
  b = c;
  return (a, b);
}

void	reorder_numbers(t_operation *op, int n1, int n2)
{
  if (op->n1.lenght < op->n2.lenght)
    {
      my_swap(n1, n2);
    }
}
