/*
** my_put_in_list.c for my_put_in_list in /home/ghikh_r/rendu/Piscine_C_J11
** 
** Made by raphael ghikh
** Login   <ghikh_r@epitech.net>
** 
** Started on  Mon Oct 12 22:05:54 2015 raphael ghikh
** Last update Tue Oct 13 20:27:53 2015 raphael ghikh
*/

#include <stdlib.h>
#include "mylist.h"

t_list	*my_list_add(void *data, t_list *list)
{
  t_list	*new;

  new = malloc(sizeof(*new));
  if (new == NULL)
    return (1);
  new->data = data;
  new->next = *list;

  return (new);
}

t_list	*my_params_in_list(int ac, char **av)
{
  int		i;
  t_list	*new;

  new = NULL;
  i = 0;
  while (i < ac)
    {
      my_list_add(&list, av[i]);
      i = i + 1;
    }
  return (list);
}
