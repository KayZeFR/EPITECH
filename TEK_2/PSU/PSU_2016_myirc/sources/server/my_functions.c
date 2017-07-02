/*
** my_functions.c for irc in /home/kayzefr/EPITECH/TEK/PSU_2016_myirc/sources/server
** 
** Made by Raphaël Ghikh
** Login   <raphael.ghikh@epitech.eu>
** 
** Started on  Mon May 29 09:45:47 2017 Raphaël Ghikh
** Last update Sun Jun 11 16:17:24 2017 Raphaël Ghikh
*/

#include <server.h>

int	my_setsockopt(int my_sock_fd, int level, int optname,
		      const void *optval, socklen_t addrlen)
{
  int	num;

  num = setsockopt(my_sock_fd, level, optname, optval, addrlen);
  if (num == -1)
    my_exit("Error on setsockopt()");
  return (num);
}

int	my_socket(int fam, int type, int prot)
{
  int   num;

  num = socket(fam, type, prot);
  if (num == -1)
    my_exit("Error on socket()");
  return (num);
}

int	my_bind(int my_sock_fd, const struct sockaddr *addr, socklen_t addrlen)
{
  int   num;

  num = bind(my_sock_fd, addr, addrlen);
  if (num == -1)
    {
      close(my_sock_fd);
      my_exit("Error on bind()");
    }
  return (num);
}

int	my_listen(int my_sock_fd, int log)
{
  int   num;

  num = listen(my_sock_fd, log);
  if (num == -1)
    {
      close(my_sock_fd);
      my_exit("Error on listen()");
    }
  return (num);
}

int	my_accept(int my_sock_fd, struct sockaddr *addr, socklen_t *addrlen)
{
  int   num;

  num = accept(my_sock_fd, addr, addrlen);
  if (num == -1)
    {
      close(my_sock_fd);
      my_exit("Error on accept()");
    }
  return (num);
}
