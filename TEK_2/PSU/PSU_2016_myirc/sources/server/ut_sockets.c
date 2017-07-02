/*
** ut_sockets.c for irc in /home/kayzefr/EPITECH/TEK/PSU_2016_myirc/sources/server
** 
** Made by Raphaël Ghikh
** Login   <raphael.ghikh@epitech.eu>
** 
** Started on  Sat Jun 03 14:51:27 2017 Raphaël Ghikh
** Last update Sun Jun 11 16:36:19 2017 Raphaël Ghikh
*/

#include "server.h"

int			init_2_connexion(struct addrinfo *i, int *sock)
{
  int		count;

  count = 1;
  *sock = my_socket(i->ai_family, i->ai_socktype, i->ai_protocol);
  my_setsockopt(*sock, SOL_SOCKET, SO_REUSEADDR, &count, sizeof(count));
  my_bind(*sock, i->ai_addr, i->ai_addrlen);

  return (0);
}

int			init_1_connexion(char *port, t_server *server_irc)
{
  int			sock;

  memset(&server_irc->first_addr, 0, sizeof(struct addrinfo));
  server_irc->first_addr.ai_family = AF_UNSPEC;
  server_irc->first_addr.ai_socktype = SOCK_STREAM;
  server_irc->first_addr.ai_flags = AI_PASSIVE;
  my_getaddrinfo(NULL, port, &server_irc->first_addr, &server_irc->switch_addr);
  server_irc->second_addr = server_irc->switch_addr;
  while (server_irc->second_addr != NULL)
    {
      if (!init_2_connexion(server_irc->second_addr, &sock))
	break ;
      server_irc->second_addr = server_irc->second_addr->ai_next;
    }
  if (!server_irc->second_addr)
    my_exit("bind");
  my_freeaddrinfo(server_irc->switch_addr);
  my_listen(sock, 5);
  return (sock);
}
