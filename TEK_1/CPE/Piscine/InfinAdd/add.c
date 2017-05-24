/*
** add.c for add.c in /home/ghikh_r/rendu/Piscine_C_infinadd
** 
** Made by Raphael Ghikh
** Login   <ghikh_r@epitech.net>
** 
** Started on  Mon Oct 19 15:27:59 2015 Raphael Ghikh
** Last update Mon Oct 19 19:53:24 2015 Raphael Ghikh
*/

#include <stdlib.h>
#include "infinadd.h"

char	*inf_add(char *n1, char *n2)
{
  t_operation	op;
  int	i;

  init_number(&op.n1, n1);
  init_number(&op.n2, n2);
  reorder_numbers(&op);
  if (init_result_and_tmp(&op) != 0)
    {
      return (NULL);
    }
  process_operation(&op);
  /* finition */
  free(op.tmp.str);
  /* return */
  i = 0;
  while (i < op.result.lenght)
    {
      op.result.str[op.result.idx] += '0';
      i++;
    }
  return (op.result.str);
}
