/*
** ut_users.c for irc in /home/kayzefr/EPITECH/TEK/PSU_2016_myirc/sources/server
** 
** Made by Raphaël Ghikh
** Login   <raphael.ghikh@epitech.eu>
** 
** Started on  Thu Jun 01 12:17:21 2017 Raphaël Ghikh
** Last update Sun Jun 11 16:03:40 2017 Raphaël Ghikh
*/

#include "server.h"

void		init_user(t_user *noeud, t_user **my_list)
{
  noeud->tmp = *my_list;
  if (!noeud->tmp)
    *my_list = noeud;
  else
    {
      while (noeud->tmp->suiv)
	noeud->tmp = noeud->tmp->suiv;
      noeud->tmp->suiv = noeud;
    }
  noeud->suiv = NULL;
  noeud->my_list = my_list;
}

void		test_user(t_user *my_user)
{
  if (my_user != '\0')
    {
      if (my_user->address_ip != '\0')
	free(my_user->address_ip);
      if (my_user->name_user != '\0')
	free(my_user->name_user);
      if (my_user->real != '\0')
	free(my_user->real);
      if (my_user->nm_channel != '\0')
	free(my_user->nm_channel);
      if (my_user->my_socket != '\0')
	    close(my_user->my_socket);
      if (my_user->my_buffer != '\0')
	free(my_user->my_buffer);
      free(my_user);
    }
}

t_user		*new_user(t_user *my_user, t_user *stockage)
{
  if (stockage == my_user)
    {
      my_user->tmp = my_user->suiv;
      test_user(my_user);
      return (my_user->tmp);
    }
  else
    {
      my_user->tmp = stockage;
      while (my_user->tmp != NULL)
	{
	  if (my_user->tmp == my_user)
	    {
	      my_user->backup->suiv = my_user->suiv;
	      test_user(my_user);
     	      return (stockage);
	    }
	  my_user->backup = my_user->tmp;
	  my_user->tmp = my_user->tmp->suiv;
	}
    }
  return (NULL);
}

void		gest_tran(t_user *my_user, t_user **my_list)
{
  if (*my_user->my_list == my_user)
    *my_user->my_list = my_user->suiv;
  else
    {
      my_user->tmp = *my_user->my_list;
      while (my_user->tmp != NULL)
	{
	  if (my_user->tmp == my_user)
	    {
	      my_user->backup->suiv = my_user->suiv;
	      break ;
	    }
	  my_user->backup = my_user->tmp;
	  my_user->tmp = my_user->tmp->suiv;
	}
    }
  init_user(my_user, my_list);
}
