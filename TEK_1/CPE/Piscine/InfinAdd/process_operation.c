/*
** process_operation.c for operation in /home/ghikh_r/rendu/Piscine_C_infinadd
** 
** Made by Raphael Ghikh
** Login   <ghikh_r@epitech.net>
** 
** Started on  Mon Oct 19 16:45:13 2015 Raphael Ghikh
<<<<<<< HEAD
** Last update Mon Oct 19 19:55:10 2015 Raphael Ghikh
=======
** Last update Mon Oct 19 19:19:16 2015 johan ganem--brunet
>>>>>>> 43b4ed17860d68c19021bcb019d33478ea7464d0
*/

#include <stdlib.h>
#include "infinadd.h"

void	addition(t_operation *op)
{
  int	somme;
  int	retenue;

  retenue = 0;
  op->n1.idx = op->n1.lenght;
  while (op->n1.idx)
    {
      somme = (op->n1.str[op->n1.idx - 1] + op->n2.str[op->n2.idx - 1]) + retenue;
      op->tmp.str[op->tmp.idx - 1] = somme % 10;
      retenue = somme / 10;
      op->n1.idx--;
      op->tmp.idx--;
    }
  while (op->tmp.idx > 0)
    {
      op->tmp.str[op->tmp.idx - 1] = retenue;
      retenue = 0;
      op->tmp.idx--;
    }
}

void	add_tmp_to_result(t_operation *op)
{
  int	somme;
  int	retenue;

  retenue = 0;
  op->result.idx = op->result.lenght;
  while (op->result.idx > 0)
    {
      somme = op->tmp.str[op->result.idx - 1] + op->result.str[op->result.idx - 1] + retenue;
      op->result.str[op->result.idx - 1] = somme % 10;
      retenue = somme / 10;
      op->result.idx--;
    }
}

void	process_operation(t_operation *op)
{
  unsigned int zero;
  unsigned int a;

  zero = 0;
  while (op->n2.idx > 0)
    {
      op->tmp.idx = op->tmp.lenght;
      a = 0;
      while (a < zero)
	{
	  op->tmp.str[op->tmp.idx - 1] = 0;
	  a++;
	  op->tmp.idx--;
	}
      add_tmp_to_result(op);
      op->n2.idx--;
      zero++;
    }
}
