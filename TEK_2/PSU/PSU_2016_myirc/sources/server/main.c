/*
** main.c for irc in /home/kayzefr/EPITECH/TEK/PSU_2016_myirc/sources/server
** 
** Made by Raphaël Ghikh
** Login   <raphael.ghikh@epitech.eu>
** 
** Started on  Sat May 27 10:32:10 2017 Raphaël Ghikh
** Last update Sun Jun 11 15:40:31 2017 Raphaël Ghikh
*/

#include "server.h"

int	connexion(int i, t_user *my_user, t_server *server_irc, char *n)
{
  int	x;

  x = 0;
  if (server_irc->my_user[i] && server_irc->my_user[i]->name_user
      && !strcmp(server_irc->my_user[i]->name_user, n))
    {
      x++;
      if (x > 1)
	{
	  my_error(my_user->my_socket, USER_CO);
	  return (1);
	}
    }
  return (0);
}

int		gest_args(int nb)
{
  if (nb != 2)
    {
      printf("[USAGE]: ./server [PORT]\n");
      return (1);
    }
  return (0);
}

int		main(int ac, char **av)
{
  int                 i;
  t_server            *server_irc;

  if (gest_args(ac) == 1)
    return (1);
  i = 0;
  if (!(server_irc = malloc(sizeof(t_server))))
    my_exit("malloc");
  server_irc->my_chans = NULL;
  server_irc->one_user = NULL;
  server_irc->my_port_use = strdup(av[1]);
  server_irc->my_socket = init_1_connexion(av[1], server_irc);
  while (i < 133)
    {
      server_irc->my_user[i] = NULL;
      i++;
    }
  FD_ZERO(&server_irc->master);
  FD_SET(server_irc->my_socket, &server_irc->master);
  set_handler(server_irc);
  server_irc->g_run = 1;
  check_serv(server_irc);
  delete_serv(server_irc);
  return (0);
}
