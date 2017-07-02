/*
** ut_channels.c for irc in /home/kayzefr/EPITECH/TEK/PSU_2016_myirc/sources/server
** 
** Made by Raphaël Ghikh
** Login   <raphael.ghikh@epitech.eu>
** 
** Started on  Sat Jun 03 11:01:32 2017 Raphaël Ghikh
** Last update Sun Jun 11 16:08:20 2017 Raphaël Ghikh
*/

#include "server.h"

void		init_channel(t_channel *node, t_channel **list)
{
  t_channel	*tmp;

  tmp = *list;
  if (!tmp)
    *list = node;
  else
    {
      while (tmp->suiv)
	tmp = tmp->suiv;
      tmp->suiv = node;
    }
  node->suiv = NULL;
}

void		supp_channel(t_channel *my_channel)
{
  if (my_channel != '\0')
    {
      if (my_channel->channel_name)
	free(my_channel->channel_name);
      if (my_channel->the_user)
	{
	  my_channel->go_user->tmp = my_channel->the_user;
	  boucle_sup_channel(my_channel);
	}
      free(my_channel);
    }
}

t_channel	*boucle(t_channel *my_channel, t_channel *stockage)
{
  my_channel->tmp = stockage;
  while (my_channel->tmp != NULL)
    {
      if (my_channel->tmp == my_channel)
	{
	  my_channel->backup->suiv = my_channel->suiv;
	  if (my_channel && my_channel->channel_name)
	    free(my_channel->channel_name);
	  if (my_channel && my_channel->the_user)
	    {
	      my_channel->go_user->tmp = my_channel->the_user;
	      boucle_free_channel(my_channel);
	    }
	  if (my_channel)
	    free(my_channel);
	  return (stockage);
	}
      my_channel->backup = my_channel->tmp;
      my_channel->tmp = my_channel->tmp->suiv;
    }
  return NULL;
}

t_channel	*new_channel(t_channel *my_channel, t_channel *stockage)
{
  if (stockage == my_channel)
    {
      my_channel->tmp = my_channel->suiv;
      supp_channel(my_channel);
      return (my_channel->tmp);
    }
  else
    return (stockage = boucle(my_channel, stockage));
  return (NULL);
}
