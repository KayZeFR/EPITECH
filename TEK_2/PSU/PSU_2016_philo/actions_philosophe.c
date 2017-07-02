/*
** actions_philosophe.c for philosophe in /home/kayzefr/EPITECH/tek2/PSU_tek2/PSU_2016_philo
** 
** Made by Raphaël Ghikh
** Login   <raphael.ghikh@epitech.eu>
** 
** Started on  Sun Mar 12 13:21:02 2017 Raphaël Ghikh
** Last update Sat Mar 18 23:48:36 2017 Raphaël Ghikh
*/

#include "philosophe.h"

void		*action(void *av)
{
  t_philosophe		*philo;

  philo = (t_philosophe*)av;
  while (philo->nb_repas > 0)
    {
      thinker(philo);
      eater(philo);
      lphilo_sleep();
    }
  pthread_exit(NULL);
}

void		eater(t_philosophe *philo)
{
  pthread_mutex_lock(&philo->baguette);
  lphilo_take_chopstick(&philo->baguette);
  pthread_mutex_lock(&philo->baguette_right->baguette);
  lphilo_take_chopstick(&philo->baguette_right->baguette);
  lphilo_eat();
  philo->nb_repas--;
  pthread_mutex_unlock(&philo->baguette);
  lphilo_release_chopstick(&philo->baguette);
  pthread_mutex_unlock(&philo->baguette_right->baguette);
  lphilo_release_chopstick(&philo->baguette_right->baguette);
}

void		thinker(t_philosophe *philo)
{
  pthread_mutex_lock(&philo->baguette);
  lphilo_take_chopstick(&philo->baguette);
  lphilo_think();
  pthread_mutex_unlock(&philo->baguette);
  lphilo_release_chopstick(&philo->baguette);
}
