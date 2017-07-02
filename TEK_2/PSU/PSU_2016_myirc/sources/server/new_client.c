/*
** new_client.c for irc in /home/kayzefr/EPITECH/TEK/PSU_2016_myirc/sources/server
** 
** Made by Raphaël Ghikh
** Login   <raphael.ghikh@epitech.eu>
** 
** Started on  Thu Jun 01 15:34:33 2017 Raphaël Ghikh
** Last update Sun Jun 11 16:44:36 2017 Raphaël Ghikh
*/

#include "server.h"

void				too_much_client(t_user *my_user, t_server *server_irc)
{
  my_error(my_user->my_socket, TOO_MUCH);
  server_irc->my_user[my_user->my_socket] = NULL;
  FD_CLR(my_user->my_socket, &server_irc->master);
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

void		gest_redirect(t_server *server_irc, t_user *my_user)
{
  if (server_irc->my_user[133 - 1])
    too_much_client(my_user, server_irc);
  else
    init_user(my_user, &server_irc->one_user);  
}

void				new_connexion(t_mysocket *my_socket,
					      t_server *server_irc)
{
  t_user			*my_user;

  if (!(my_user = malloc(sizeof(t_user))))
    my_exit("Error on malloc()");
  my_user->len = sizeof(my_user->r);
  my_user->my_socket = my_accept(server_irc->my_socket,
				 (struct sockaddr *)&my_user->r,
				 &my_user->len);
  FD_SET(my_user->my_socket, &server_irc->master);
  if (my_user->my_socket > my_socket->busy)
    my_socket->busy = my_user->my_socket;
  my_user->address_ip = strdup(inet_ntop(my_user->r.ss_family,
					 ipvx((struct sockaddr *)&my_user->r),
					 my_user->ip, INET6_ADDRSTRLEN));
  my_user->my_buffer = malloc(sizeof(t_ring_buffer));
  memset(my_user->my_buffer->rb, 0, 4096);
  my_user->my_buffer->rrb = my_user->my_buffer->rb;
  my_user->my_buffer->wrb = my_user->my_buffer->rb;
  my_user->my_buffer->available = 4096;
  my_user->name_user = NULL;
  my_user->real = NULL;
  my_user->user = 0;
  my_user->nm_channel = 0;
  server_irc->my_user[my_user->my_socket] = my_user;
  gest_redirect(server_irc, my_user);
}

void		delete_connexion(t_user *my_user, t_server *server_irc)
{
  t_channel	*my_channel;
  t_user	*my_s_user;

  my_s_user = server_irc->one_user;
  while (my_s_user != NULL)
    {
      if (error_delete(my_s_user, my_user, server_irc) == 1)
	return ;
      my_s_user = my_s_user->suiv;
    }
  my_channel = server_irc->my_chans;
  boucle_del_co(my_channel, my_s_user, my_user, server_irc);
}

void		run_args(char *command, t_user *my_user, t_server *server_irc)
{
  char		*cr;
  int		i;

  if ((cr = strstr(command, "\r\n")))
    *cr = 0;
  i = 0;
  while (i < 11)
    {
      if (!(strncmp(command, server_irc->my_cmd[i],
		    strlen(server_irc->my_cmd[i]))))
  	{
  	  server_irc->cmd_handler[i](strchrnul(command, ' '),
				     my_user, server_irc);
  	  return ;
  	}
      i++;
    }
  if (i == 11 - 1)
    def_cmd(command, my_user, server_irc);
}
