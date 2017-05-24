/*
** my_functions.c for myftp in /home/kayzefr/EPITECH/TEK/TEK_2/PSU/PSU_2016_myftp
** 
** Made by Raphaël Ghikh
** Login   <raphael.ghikh@epitech.eu>
** 
** Started on  Thu May 18 21:28:25 2017 Raphaël Ghikh
** Last update Fri May 19 11:03:11 2017 Raphaël Ghikh
*/

#include "my_ftp.h"

int	my_socket(int fam, int type, int prot)
{
  int	num;

  num = socket(fam, type, prot);
  if (num == -1)
    my_exit("Error on socket()");
  return (num);
}

int	my_bind(int my_fd_sock, const struct sockaddr *addr, socklen_t addrlen)
{
  int	num;

  num = bind(my_fd_sock, addr, addrlen);
  if (num == -1)
    {
      close(my_fd_sock);
      my_exit("Error on bind()");
    }
  return (num);
}

int	my_listen(int my_fd_sock, int log)
{
  int	num;

  num = listen(my_fd_sock, log);
  if (num == -1)
    {
      close(my_fd_sock);
      my_exit("Error on listen()");
    }
  return (num);
}

int	my_accept(int my_fd_sock, struct sockaddr *addr, socklen_t *addrlen)
{
  int	num;

  num = accept(my_fd_sock, addr, addrlen);
  if (num == -1)
    {
      close(my_fd_sock);
      my_exit("Error on accept()");
    }
  return (num);
}

int	my_connect(int my_fd_sock, struct sockaddr *addr, socklen_t addrlen)
{
  int	num;

  num = connect(my_fd_sock, addr, addrlen);
  if (num == -1)
    {
      close(my_fd_sock);
      my_exit("Error on connect");
    }
  return (num);
}

void	my_error(int my_fd_sock, char *str)
{
  write(my_fd_sock, str, strlen(str));
  exit (0);
}

void	my_exit(char *str)
{
  fprintf(stderr, "%s\n", str);
  exit(0);
}

void	gest_error(int num)
{
  if (num != 3)
    my_exit("Usage : ./server port path\n");
}

int	gest_error_dir(char *my_dir)
{
  if (chdir(my_dir) == -1)
    {
      fprintf(stderr, "Invalid path: %s\n", my_dir);
      return (-1);
    }
  return (0);
}
