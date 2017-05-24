/*
** init_result_and_tmp.c for Vérifies le retour in /home/ghikh_r/rendu/Piscine_C_infinadd
** 
** Made by Raphael Ghikh
** Login   <ghikh_r@epitech.net>
** 
** Started on  Mon Oct 19 15:57:05 2015 Raphael Ghikh
** Last update Mon Oct 19 19:31:18 2015 johan ganem--brunet
*/

#include <string.h>
#include <stdlib.h>
#include "infinadd.h"

int	init_result_and_tmp(t_operation *op)
{
  unsigned int i;

  op->result.lenght = op->n1.lenght + op->n2.lenght;
  op->tmp.lenght = op->result.lenght;
  op->result.idx = op->result.lenght;
  op->tmp.idx = op->tmp.lenght;
  op->result.str = malloc(sizeof(char) * (op->result.lenght + 1));
  op->tmp.str = malloc(sizeof(char) * (op->tmp.lenght + 1));
  if (op->result.str == NULL || op->tmp.str == NULL)
    {
      free(op->result.str);
      free(op->tmp.str);
      return (1);
    }
  i = 0;
  while (i < op->result.lenght)
    {
      op->result.str[i] = 0;
      i++;
    }
  op->result.str[i] = '\0';
  return (0);
}
