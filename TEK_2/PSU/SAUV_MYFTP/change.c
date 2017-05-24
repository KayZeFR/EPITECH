/*
** change.c for change in /home/vezia_l/rendu/PSU_2015_myftp/src
**
** Made by louis vezia
** Login   <vezia_l@epitech.net>
**
** Started on  Sun May 15 15:23:37 2016 louis vezia
** Last update	Sun May 15 23:27:54 2016 Louis Vezia
*/

#include "my_ftp.h"

int		cwd_cmd(t_server *server_ftp)
{
  int	len;

  len = strlen(server_ftp->my_board[1]) - 1;
  if (len && server_ftp->my_board[1][len] == '\r')
    server_ftp->my_board[1][len] = 0;
  if (server_ftp->login == 0)
    send_msg(server_ftp->my_fd_client, "530 Please login with USER and PASS.\r\n");
  else
    {
     if (chdir(server_ftp->my_board[1]) == -1)
       send_msg(server_ftp->my_fd_client, "550 Failed to change directory.\r\n");
     else
       {
   if (getcwd(server_ftp->my_path, 1024) == NULL)
          return (send_msg(server_ftp->my_fd_client, "550 Command failed.\r\n"));
   if (strlen(server_ftp->my_root) > strlen(server_ftp->my_path))
     if (chdir(server_ftp->my_root) == -1)
       return (send_msg(server_ftp->my_fd_client, "550 Command failed.\r\n"));
   send_msg(server_ftp->my_fd_client, "200 Directory successfully changed.\r\n");
       }
  }
  return (0);
}

int		cdup_cmd(t_server *server_ftp)
{
  if (server_ftp->login == 0)
    send_msg(server_ftp->my_fd_client, "530 Please login with USER and PASS.\r\n");
  else
    {
     if (chdir("..") == -1)
       send_msg(server_ftp->my_fd_client, "550 Failed to change directory.\r\n");
     else
       {
	 if (getcwd(server_ftp->my_path, 1024) == NULL)
          return (send_msg(server_ftp->my_fd_client, "550 Command failed.\r\n"));
	 if (strlen(server_ftp->my_root) > strlen(server_ftp->my_path))
	   if (chdir(server_ftp->my_root) == -1)
	     return (send_msg(server_ftp->my_fd_client, "550 Command failed.\r\n"));
	 send_msg(server_ftp->my_fd_client, "200 Directory successfully changed.\r\n");
       }
  }
  return (0);
}

int		pasv_cmd(t_server *server_ftp)
{
  server_ftp->nb_client = 0;
  return (0);
}

int		port_cmd(t_server *server_ftp)
{
  server_ftp->nb_client = 0;
  return (0);
}
