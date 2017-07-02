/*
** gest_erreur.c for philosophe in /home/kayzefr/EPITECH/tek2/PSU_tek2/PSU_2016_philo
** 
** Made by Raphaël Ghikh
** Login   <raphael.ghikh@epitech.eu>
** 
** Started on  Sun Mar 12 15:12:22 2017 Raphaël Ghikh
** Last update Sun Mar 19 19:54:43 2017 Raphaël Ghikh
*/

#include "philosophe.h"

int		args_check(char **av, t_philosophe *philo)
{
  if (strcmp(av[1], "-p") == 0)
    philo->nb_philo = atoi(av[2]);
  else
    return (-1);
  if (strcmp(av[3], "-e") == 0)
    philo->nb_tours = atoi(av[4]);
  else
    return (-1);
  return (0);
}

void		*xmalloc(int length)
{
  void		*str;

  str = NULL;
  if ((str = malloc(length)) == NULL)
    {
      fprintf(stderr, "malloc failure\n");
      exit(EXIT_FAILURE);
    }
  return (str);
}
