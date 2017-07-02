/*
** main.c for philosophe in /home/kayzefr/EPITECH/tek2/PSU_tek2/PSU_2016_philo
** 
** Made by Raphaël Ghikh
** Login   <raphael.ghikh@epitech.eu>
** 
** Started on  Fri Mar 10 15:25:10 2017 Raphaël Ghikh
** Last update Sat Mar 18 23:51:15 2017 Raphaël Ghikh
*/

#include "philosophe.h"

int		main(int ac, char **av)
{
  t_philosophe		*philo;

  if (ac != 5)
    return (-1);
  if ((philo = xmalloc(sizeof(t_philosophe) * atoi(av[2]))) == NULL)
    return (-1);
  if (args_check(av, philo) == -1)
    return (-1);
  RCFStartup(ac, av);
  philo->pos = 0;
  while (philo->pos < philo->nb_philo)
    {
      pthread_mutex_init(&philo[philo->pos].baguette, NULL);
      if (philo->pos == philo->nb_philo - 1)
	philo[philo->pos].baguette_right = &philo[0];
      else
	philo[philo->pos].baguette_right = &philo[philo->pos + 1];
      philo[philo->pos].nb_repas = philo->nb_tours;
      philo->pos++;
    }
  philo->pos = 0;
  thread_init(philo, philo->nb_philo, philo->pos);
  return (0);
}
