/*
** gest_boucle_cmd.c for irc in /home/kayzefr/EPITECH/TEK/PSU_2016_myirc/sources/server
** 
** Made by Raphaël Ghikh
** Login   <raphael.ghikh@epitech.eu>
** 
** Started on  Wed May 31 10:10:56 2017 Raphaël Ghikh
** Last update Sun Jun 11 15:58:15 2017 Raphaël Ghikh
*/

#include "server.h"

void		boucle_nick(void *command, t_server *server_irc, t_user *my_user)
{
  while (server_irc->i < 133)
    {
      if (server_irc->my_user[server_irc->i]
	            && server_irc->my_user[server_irc->i]->name_user &&
	  !strcmp(server_irc->my_user[server_irc->i]->name_user, command))
	{
	  my_error(my_user->my_socket, NICK_USE);
	  return ;
	}
      server_irc->i++;
    }
}

void		boucle_channel(t_channel *tmp, char *params,
			       t_user *my_user, t_server *server_irc)
{
  while (tmp != '\0')
    {
      if (!strcmp(tmp->channel_name, params))
	{
	  gest_tran(my_user, &tmp->the_user);
	  my_user->nm_channel = strdup(tmp->channel_name);
	  names_cmd(params, my_user, server_irc);
	  return ;
	}
      tmp = tmp->suiv;
    }
}

void		boucle_channel_repart(t_user *my_s_user, t_user *my_user,
				      t_server *server_irc)
{
  while (my_s_user != '\0')
    {
      if (my_s_user == my_user)
	{
	  gest_tran(my_user, &server_irc->one_user);
	  my_user->nm_channel = 0;
	  return ;
	}
      my_s_user = my_s_user->suiv;
    }
}

void		boucle_quit(t_user *my_s_user, t_user *my_user, char *msg)
{
  while (my_s_user != NULL)
    {
      if (my_s_user == my_user)
	continue ;
      my_aff_quit_cmd(my_s_user->my_socket, my_user->name_user, msg);
      my_s_user = my_s_user->suiv;
    }
}

void		boucle_del_co(t_channel *my_channel, t_user *my_s_user,
			      t_user *my_user, t_server *server_irc)
{
  while (my_channel != NULL)
    {
      my_s_user = my_channel->the_user;
      while (my_s_user != NULL)
	{
	  if (my_s_user == my_user)
	    {
	      server_irc->my_user[my_user->my_socket] = NULL;
	      my_channel->the_user = new_user(my_user, my_channel->the_user);
	      return ;
	    }
	  my_s_user = my_s_user->suiv;
	}
      my_channel = my_channel->suiv;
    }
}
