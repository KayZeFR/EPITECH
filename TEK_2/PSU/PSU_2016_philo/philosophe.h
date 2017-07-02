/*
** philosophe.h for philosophe in /home/kayzefr/EPITECH/tek2/PSU_tek2/PSU_2016_philo
** 
** Made by Raphaël Ghikh
** Login   <raphael.ghikh@epitech.eu>
** 
** Started on  Fri Mar 10 10:53:57 2017 Raphaël Ghikh
** Last update Sat Mar 18 23:48:49 2017 Raphaël Ghikh
*/

#ifndef _PHILOSOPHE_H_
# define _PHILOSOPHE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <pthread.h>
#include "extern.h"

typedef struct		s_philosophe
{
  int			nb_philo;
  int			nb_repas;
  int			nb_tours;
  int			pos;
  pthread_mutex_t	baguette;
  pthread_t		my_philosophe;
  struct s_philosophe	*baguette_right;
}			t_philosophe;

void			*action(void *);
void			eater(t_philosophe *);
void			thinker(t_philosophe *);
void			thread_init(t_philosophe *, int, int);
void			*xmalloc(int);
int			args_check(char **, t_philosophe *);


#endif /* !_PHILOSOPHE_H_ */
