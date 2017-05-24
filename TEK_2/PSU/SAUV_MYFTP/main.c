/*
** main.c for main in /home/vezia_l/rendu/ftp
**
** Made by louis vezia
** Login   <vezia_l@epitech.net>
**
** Started on  Wed May  4 17:00:30 2016 louis vezia
** Last update	Sun May 15 22:09:38 2016 Louis Vezia
*/

#include "my_ftp.h"

int				init_socket(t_server *server_ftp)
{
  struct sockaddr_in	addrin;
  int		sock_num;

  sock_num = 1;
  server_ftp->my_protoent = getprotobyname("TCP");
  
  server_ftp->sock_size = sizeof(server_ftp->sock_client);
  addrin.sin_family = AF_INET;
  addrin.sin_port = htons(server_ftp->port);
  addrin.sin_addr.s_addr = INADDR_ANY;

  server_ftp->my_file_descriptor = my_socket(AF_INET, SOCK_STREAM, server_ftp->my_protoent->p_proto);
  if (setsockopt(server_ftp->my_file_descriptor, SOL_SOCKET, SO_REUSEADDR, &sock_num, sizeof(int)) < 0)
    return (1);
  my_bind(server_ftp->my_file_descriptor, (const struct sockaddr *)&addrin, sizeof(addrin));
  my_listen(server_ftp->my_file_descriptor, NB_MAX_CLIENT);
  return (0);
}

int				main(int ac, char **av)
{
  t_server	server_ftp;

  gest_error(ac);
  server_ftp.port = atoi(av[1]);
  gest_error_dir(av[2]);
  if (init_socket(&server_ftp) == 1)
    return (1);
  if (run_ftp(&server_ftp) == 1)
    return (1);
  if (close(server_ftp.my_file_descriptor) == -1)
    return (1);
  return (0);
}
