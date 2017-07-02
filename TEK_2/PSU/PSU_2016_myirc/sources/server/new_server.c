/*
** new_server.c for irc in /home/kayzefr/EPITECH/TEK/PSU_2016_myirc/sources/server
** 
** Made by Raphaël Ghikh
** Login   <raphael.ghikh@epitech.eu>
** 
** Started on  Thu Jun 02 07:18:28 2017 Raphaël Ghikh
** Last update Sun Jun 11 16:45:49 2017 Raphaël Ghikh
*/

#include "server.h"

int		pwd_gest(char *str, char *pattern)
{
  int		i;
  char		*res;

  i = 0;
  res = str;
  while ((res = strstr(res, pattern)))
    {
      res++;
      i++;
    }
  return (i);
}

void		see_in(t_user *my_user, t_server *server_irc)
{
  char		*input;
  int           size;
  int           i;

  size = ((my_user->my_buffer->wrb >= my_user->my_buffer->rrb)
	  ? (int)(my_user->my_buffer->wrb - my_user->my_buffer->rrb)
	  : (4096 - (int)(my_user->my_buffer->rrb - my_user->my_buffer->wrb)));
  if (!(input = malloc(size + 1)))
    error("malloc");
  memset(input, 0, size + 1);
  i = 0;
  while (i < size)
    {
      input[i] = *my_user->my_buffer->rrb;
      my_user->my_buffer->rrb =
	&my_user->my_buffer->rb[(((size_t)my_user->my_buffer->rrb + 1)
			     - (size_t)my_user->my_buffer->rb) % 4096];
      i++;
    }
  gest_see_in(input, my_user, server_irc);
  free(input);
}

void		check_connexion(t_user *my_user, t_server *server_irc)
{
  char		tmp[4096];

  memset(tmp, 0, 4096);
  if ((server_irc->rbc = recv(my_user->my_socket, tmp,
		 rb_available(my_user->my_buffer), 0)) > 0)
    {
      my_user->my_buffer->wrb = (my_user->my_buffer->wrb)
	? my_user->my_buffer->wrb : my_user->my_buffer->rb;
      server_irc->a = 0;
      boucle_checker(tmp, my_user, server_irc->a);
      if (buffer_in(my_user->my_buffer, -1) == '\n'
	  && buffer_in(my_user->my_buffer, -2) == '\r')
	see_in(my_user, server_irc);
    }
  else
    {
      if (server_irc->rbc == 0)
	printf("%s Disconnected\n", (my_user->name_user)
	       ? my_user->name_user : my_user->address_ip);
      else
      	my_exit("recv");
      FD_CLR(my_user->my_socket, &server_irc->master);
      delete_connexion(my_user, server_irc);
    }
}

void		boucle_check_ser(t_mysocket *my_socket, t_server *server_irc)
{
  while (my_socket->fd <= my_socket->busy)
    {
      if (FD_ISSET(my_socket->fd, &server_irc->catch))
	{
	  if (my_socket->fd == server_irc->my_socket)
	    new_connexion(my_socket, server_irc);
	  else
	    check_connexion(server_irc->my_user[my_socket->fd],
			    server_irc);
	}
      my_socket->fd++;
    }
}

void		check_serv(t_server *server_irc)
{
  t_mysocket		*my_socket;

  my_socket->busy = server_irc->my_socket;
  FD_ZERO(&server_irc->catch);
  while (server_irc->g_run)
    {
      server_irc->catch = server_irc->master;
      if (select(my_socket->busy + 1, &server_irc->catch,
		 NULL, NULL, NULL) == -1)
	{
	  if (!server_irc->g_run)
	    return ;
	  error("select");
	}
      my_socket->fd = 0;
      boucle_check_ser(my_socket, server_irc);
    }
}
