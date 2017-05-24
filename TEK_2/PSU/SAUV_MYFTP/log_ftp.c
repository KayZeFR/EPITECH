/*
** log_ftp.c for log in /home/vezia_l/rendu/PSU_2015_myftp/src
**
** Made by louis vezia
** Login   <vezia_l@epitech.net>
**
** Started on  Sun May 15 15:22:08 2016 louis vezia
** Last update	Sun May 15 23:23:29 2016 Louis Vezia
*/

#include "my_ftp.h"

int		user_cmd(t_server *server_ftp)
{
  int	len;

  len = strlen(server_ftp->my_board[1]) - 1;
  if (len && server_ftp->my_board[1][len] == '\r')
    server_ftp->my_board[1][len] = 0;
  if (server_ftp->my_board == '\0' || server_ftp->my_board[1] == '\0' ||
      strlen(server_ftp->my_board[1]) == 0)
    write(server_ftp->my_fd_client, "Permission denied.\r\n", 20);
  else
    {
      if (server_ftp->my_board && server_ftp->my_board[1]
	  && strcmp(server_ftp->my_board[1], "Anonymous") == 0)
	server_ftp->user = 2;
      else
	server_ftp->user = 1;
      write(server_ftp->my_fd_client, "331 User name okay, need password.\r\n", 36);
    }
  return (0);
}

int		passw_cmd(t_server *server_ftp)
{
  if (server_ftp->login == 1)
    write(server_ftp->my_fd_client, "230 Already logged in.\r\n", 24);
  else if (server_ftp->my_board == '\0' || server_ftp->user == '\0')
    write(server_ftp->my_fd_client, "503 Login with USER first.\r\n", 31);
  else if (server_ftp->user == 2)
    {
      server_ftp->password = 1;
      server_ftp->login = 1;
      write(server_ftp->my_fd_client, "230 Login successful.\r\n", 29);
    }
  else
    {
      if (server_ftp->user == 0)
	write(server_ftp->my_fd_client, "503 Login with USER first.\r\n", 31);
      else
	write(server_ftp->my_fd_client, "530 Wrong USER or wrong PASS.\r\n", 34);
    }
  return (0);
}

int		quit_cmd(t_server *server_ftp)
{
  server_ftp->my_cmd_exit = 1;
  send_msg(server_ftp->my_fd_client, "221 Log out.\r\n");
  return (0);
}
