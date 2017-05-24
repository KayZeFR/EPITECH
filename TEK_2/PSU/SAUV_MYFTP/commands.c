/*
** commands.c for commands in /home/vezia_l/rendu/PSU_2015_myftp/src
**
** Made by louis vezia
** Login   <vezia_l@epitech.net>
**
** Started on  Thu May 12 17:27:43 2016 louis vezia
** Last update	Sun May 15 23:32:07 2016 Louis Vezia
*/

#include "my_ftp.h"

void		init_tab(char *tab[14])
{
  tab[0] = "USER";
  tab[1] = "PASS";
  tab[2] = "CWD";
  tab[3] = "CDUP";
  tab[4] = "QUIT";
  tab[5] = "DELE";
  tab[6] = "PWD";
  tab[7] = "PASV";
  tab[8] = "PORT";
  tab[9] = "HELP";
  tab[10] = "NOOP";
  tab[11] = "RETR";
  tab[12] = "STOR";
  tab[13] = "LIST";
}

int			check_msg(t_server *server_ftp, int (*ptr[14])(t_server *), char *cmd[14])
{
  int		i;

  i = 0;
  while (i < 14)
    {
      if (server_ftp->my_board && strncmp(server_ftp->my_board[0], cmd[i], strlen(cmd[i])) == 0)
	return (ptr[i](server_ftp));
      i++;
    }
  if (server_ftp->login == 0 && strlen(server_ftp->my_board[0]) > 0)
    return (send_msg(server_ftp->my_fd_client, "530 Permission denied.\r\n"));
  else if (strlen(server_ftp->my_board[0]) > 0)
    return (send_msg(server_ftp->my_fd_client, "500 Unknown command.\r\n"));
  return (0);
}

int			fct_cmd(t_server *server_ftp)
{
  int		(*ptr[14])(t_server *);
  char	*cmd[14];

  init_tab(cmd);
  ptr[0] = &user_cmd;
  ptr[1] = &passw_cmd;
  ptr[2] = &cwd_cmd;
  ptr[3] = &cdup_cmd;
  ptr[4] = &quit_cmd;
  ptr[5] = &dele_cmd;
  ptr[6] = &pwd_cmd;
  ptr[7] = &pasv_cmd;
  ptr[8] = &port_cmd;
  ptr[9] = &help_cmd;
  ptr[10] = &noop_cmd;
  ptr[11] = &retr_cmd;
  ptr[12] = &stor_cmd;
  ptr[13] = &list_cmd;
  return (check_msg(server_ftp, ptr, cmd));
}
