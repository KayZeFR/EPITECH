/*
** run.c for run in /home/vezia_l/rendu/PSU_2015_myftp
**
** Made by louis vezia
** Login   <vezia_l@epitech.net>
**
** Started on  Thu May 12 18:42:19 2016 louis vezia
** Last update	Tue May 17 16:24:11 2016 Louis Vezia
*/

#include "my_ftp.h"

void		init_data(t_server *server_ftp)
{
  server_ftp->my_cmd_exit = 0;
  server_ftp->user = 0;
  server_ftp->password = 0;
  server_ftp->login = 0;
  server_ftp->my_fd_client = server_ftp->my_fd_client;
  getcwd(server_ftp->my_root, sizeof(server_ftp->my_path));
}

int		run_ftp(t_server *server_ftp)
{
  pid_t		pid;

  server_ftp->nb_client = 0;
  while (server_ftp->nb_client < NB_MAX_CLIENT)
    {
      server_ftp->my_fd_client = my_accept(server_ftp->my_file_descriptor, (struct sockaddr *)&(server_ftp->sock_client), &server_ftp->sock_size);
      server_ftp->address_ip = inet_ntoa(server_ftp->sock_client.sin_addr);
      if ((pid = fork()) == 0)
        {
	  init_data(server_ftp);
	  send_msg(server_ftp->my_fd_client, "220 (vsFTPd 3.0.0)\r\n");
	  while (server_ftp->my_cmd_exit == 0)
	    {
	      if ((server_ftp->my_buffer = my_get_next_line(server_ftp->my_fd_client)))
		server_ftp->my_board = my_str_to_word_tab(server_ftp->my_buffer);
	      fct_cmd(server_ftp);
	    }
          close(server_ftp->my_fd_client);
        }
      else
	close(server_ftp->my_fd_client);
      server_ftp->nb_client += 1;
    }
  return (0);
}
