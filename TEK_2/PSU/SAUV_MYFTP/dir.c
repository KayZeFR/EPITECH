/*
** dir.c for dir in /home/vezia_l/rendu/PSU_2015_myftp/src
**
** Made by louis vezia
** Login   <vezia_l@epitech.net>
**
** Started on  Sun May 15 15:31:51 2016 louis vezia
** Last update	Sun May 15 21:52:03 2016 Louis Vezia
*/

#include "my_ftp.h"

int		dele_cmd(t_server *server_ftp)
{
  if (server_ftp->login == 0)
    send_msg(server_ftp->my_fd_client, "530 Please log in first.\r\n");
  else if (!server_ftp->my_board[1])
    send_msg(server_ftp->my_fd_client, "550 Permission denied.\r\n");
  else
    {
      if (remove(server_ftp->my_board[1]) == -1)
	send_msg(server_ftp->my_fd_client, "550 Permission denied.\r\n");
      else
	send_msg(server_ftp->my_fd_client, "250 File deleted.\r\n");
    }
  return (0);
}

int		pwd_cmd(t_server *server_ftp)
{
  char cwd[1024];
  
  if (server_ftp->login == 0)
    send_msg(server_ftp->my_fd_client, "530 Please log in first.\r\n");
  else if (getcwd(cwd, sizeof(cwd)) != NULL && !server_ftp->my_board[1])
    {
      send_msg(server_ftp->my_fd_client, "257 ");
      send_msg(server_ftp->my_fd_client, cwd);
      send_msg(server_ftp->my_fd_client, "\r\n");
    }
  return (0);
}

int		help_cmd(t_server *server_ftp)
{
  if (!server_ftp->my_board || server_ftp->login == 0)
    send_msg(server_ftp->my_fd_client, "530 Permission denied.\r\n");
  else
    {
      send_msg(server_ftp->my_fd_client, "214 You can use the following commands :\r\n");
      send_msg(server_ftp->my_fd_client, "USER <SP> <username> <CRLF>\r\n");
      send_msg(server_ftp->my_fd_client, "PASS <SP> <password> <CRLF>\r\n");
      send_msg(server_ftp->my_fd_client, "CWD  <SP> <pathname> <CRLF>\r\n");
      send_msg(server_ftp->my_fd_client, "CDUP <CRLF>\r\n");
      send_msg(server_ftp->my_fd_client, "QUIT <CRLF>\r\n");
      send_msg(server_ftp->my_fd_client, "DELE <SP> <pathname> <CRLF>\r\n");
      send_msg(server_ftp->my_fd_client, "PWD  <CRLF>\r\n");
      send_msg(server_ftp->my_fd_client, "PASV <CRLF>\r\n");
      send_msg(server_ftp->my_fd_client, "PORT <SP> <host-port> <CRLF>\r\n");
      send_msg(server_ftp->my_fd_client, "HELP [<SP> <string>] <CRLF>\r\n");
      send_msg(server_ftp->my_fd_client, "NOOP <CRLF>\r\n");
      send_msg(server_ftp->my_fd_client, "RETR <SP> <pathname> <CRLF>\r\n");
      send_msg(server_ftp->my_fd_client, "STOR <SP> <pathname> <CRLF>\r\n");
      send_msg(server_ftp->my_fd_client, "LIST [<SP> <pathname>] <CRLF>\r\n");
      send_msg(server_ftp->my_fd_client, "214 Help OK.\r\n");
    }
  return (0);
}

int		noop_cmd(t_server *server_ftp)
{
  if (!server_ftp->my_board || server_ftp->login == 0)
    send_msg(server_ftp->my_fd_client, "530 Permission denied.\r\n");
  else
    send_msg(server_ftp->my_fd_client, "200\r\n");
  return (0);
}
