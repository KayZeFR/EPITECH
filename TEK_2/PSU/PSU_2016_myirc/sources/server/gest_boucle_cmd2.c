/*
** gest_boucle_cmd2.c for irc in /home/kayzefr/EPITECH/TEK/PSU_2016_myirc/sources/server
** 
** Made by Raphaël Ghikh
** Login   <raphael.ghikh@epitech.eu>
** 
** Started on  Wed May 31 12:11:23 2017 Raphaël Ghikh
** Last update Sun Jun 11 16:44:12 2017 Raphaël Ghikh
*/

#include "server.h"

void		boucle_sup_channel(t_channel *my_channel)
{
  while (my_channel->go_user->tmp)
    {
      my_channel->go_user->backup = my_channel->go_user->tmp->suiv;
      if (my_channel->go_user->tmp != '\0')
	{
	  if (my_channel->go_user->tmp->address_ip != '\0')
	    free(my_channel->go_user->tmp->address_ip);
	  if (my_channel->go_user->tmp->name_user != '\0')
	    free(my_channel->go_user->tmp->name_user);
	  if (my_channel->go_user->tmp->real != '\0')
	    free(my_channel->go_user->tmp->real);
	  if (my_channel->go_user->tmp->nm_channel != '\0')
	    free(my_channel->go_user->tmp->nm_channel);
	  if (my_channel->go_user->tmp->my_socket != '\0')
	    close(my_channel->go_user->tmp->my_socket);
	  if (my_channel->go_user->tmp->my_buffer != '\0')
	    free(my_channel->go_user->tmp->my_buffer);
	  free(my_channel->go_user->tmp);
	}
      my_channel->go_user->tmp = my_channel->go_user->backup;
    }
}

void		boucle_free_channel(t_channel *my_channel)
{
  while (my_channel->go_user->tmp)
    {
      my_channel->go_user->backup = my_channel->go_user->tmp->suiv;

      if (my_channel->go_user->tmp != '\0')
	{
	  if (my_channel->go_user->tmp->address_ip != '\0')
	    free(my_channel->go_user->tmp->address_ip);
	  if (my_channel->go_user->tmp->name_user != '\0')
	    free(my_channel->go_user->tmp->name_user);
	  if (my_channel->go_user->tmp->real != '\0')
	    free(my_channel->go_user->tmp->real);
	  if (my_channel->go_user->tmp->nm_channel != '\0')
	    free(my_channel->go_user->tmp->nm_channel);
	  if (my_channel->go_user->tmp->my_socket != '\0')
	    close(my_channel->go_user->tmp->my_socket);
	  if (my_channel->go_user->tmp->my_buffer != '\0')
	    free(my_channel->go_user->tmp->my_buffer);
	  free(my_channel->go_user->tmp);
	}
      my_channel->go_user->tmp = my_channel->go_user->backup;
    }
}

void		boucle_checker(char tmp[4096], t_user *my_user, int i)
{
  while (tmp[i] != '\0')
    {
      *my_user->my_buffer->wrb = tmp[i];
      my_user->my_buffer->wrb =
	&my_user->my_buffer->rb[(((size_t)my_user->my_buffer->wrb + 1)
				 - (size_t)my_user->my_buffer->rb) % 4096];
      i++;
    }
}

void		gest_see_in(char *input, t_user *my_user,
			    t_server *server_irc)
{
  char		*tok;

  if (pwd_gest(input, "\r\n") > 1)
    {
      tok = input;
      for (tok = strtok(tok, "\r\n"); tok; (tok = strtok(tok, "\r\n")))
	{
	  run_args(tok, my_user, server_irc);
	  tok = NULL;
	}
    }
  else
    run_args(input, my_user, server_irc);
}

void		boucle_del_serv(t_server *server_irc)
{
  if (server_irc->one_user != '\0')
    {
      server_irc->go_user->tmp = server_irc->one_user;
      while (server_irc->go_user->tmp)
	{
	  server_irc->go_user->backup = server_irc->go_user->tmp->suiv;
	  if (server_irc->go_user->tmp != '\0')
	    {
	      if (server_irc->go_user->tmp->address_ip != '\0')
		free(server_irc->go_user->tmp->address_ip);
	      if (server_irc->go_user->tmp->name_user != '\0')
		free(server_irc->go_user->tmp->name_user);
	      if (server_irc->go_user->tmp->real != '\0')
		free(server_irc->go_user->tmp->real);
	      if (server_irc->go_user->tmp->nm_channel != '\0')
		free(server_irc->go_user->tmp->nm_channel);
	      if (server_irc->go_user->tmp->my_socket != '\0')
		close(server_irc->go_user->tmp->my_socket);
	      if (server_irc->go_user->tmp->my_buffer != '\0')
		free(server_irc->go_user->tmp->my_buffer);
	      free(server_irc->go_user->tmp);
	    }
	  server_irc->go_user->tmp = server_irc->go_user->backup;
	}
    }
}
