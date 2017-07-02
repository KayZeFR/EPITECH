/*
** commands3.c for irc in /home/kayzefr/EPITECH/TEK/PSU_2016_myirc/sources/server
** 
** Made by Raphaël Ghikh
** Login   <raphael.ghikh@epitech.eu>
** 
** Started on  Sun May 28 18:41:42 2017 Raphaël Ghikh
** Last update Sun Jun 11 15:51:04 2017 Raphaël Ghikh
*/

#include "server.h"

void		my_exit(char *str)
{
  fprintf(stderr, "%s\n", str);
  exit(0);
}

int		my_getaddrinfo(const char *node, const char *service,
			       const struct addrinfo *hints,
			       struct addrinfo **res)
{
  int num;

  num = getaddrinfo(node, service, hints, res);
  if (num == -1)
    my_exit("Error on getaddrinfo()");
  return (num);
}

void		my_freeaddrinfo(struct addrinfo *hints)
{
  freeaddrinfo(hints);
}

void		def_cmd(void *params, t_user *my_user,
			t_server *server_irc)
{
  (void)server_irc;
  if (!my_user->nm_channel)
    {
      if (((char *)params)[0] == '/')
	my_error(my_user->my_socket, NOT_DEF);
      else
	my_error(my_user->my_socket, USER_NO);
    }
  else
    aff_msg(params, my_user);
}
