/*
** data_transfer.c for datatransfer in /home/vezia_l/rendu/PSU_2015_myftp/src
**
** Made by louis vezia
** Login   <vezia_l@epitech.net>
**
** Started on  Sun May 15 15:35:10 2016 louis vezia
** Last update	Sun May 15 15:50:12 2016 Louis Vezia
*/

#include "my_ftp.h"

int		retr_cmd(t_server *server_ftp)
{
  server_ftp->nb_client = 0;
  return (0);
}

int		stor_cmd(t_server *server_ftp)
{
  server_ftp->nb_client = 0;
  return (0);
}

int		list_cmd(t_server *server_ftp)
{
  server_ftp->nb_client = 0;
  return (0);
}
