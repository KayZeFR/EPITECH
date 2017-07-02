/*
** gest_thread.c for philosophe in /home/kayzefr/EPITECH/tek2/PSU_tek2/PSU_2016_philo
** 
** Made by Raphaël Ghikh
** Login   <raphael.ghikh@epitech.eu>
** 
** Started on  Sun Mar 12 16:15:54 2017 Raphaël Ghikh
** Last update Sat Mar 18 23:49:06 2017 Raphaël Ghikh
*/

#include "philosophe.h"

void		thread_init(t_philosophe *philo, int nb_philo, int i)
{
  while (i < nb_philo)
    {
      pthread_create(&(philo[i].my_philosophe), NULL, action, &philo[i]);
      i++;
    }
  i = 0;
  while (i < nb_philo)
    pthread_join(philo[i++].my_philosophe, NULL);
  RCFCleanup();
}
