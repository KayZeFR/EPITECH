/*
** send_msg.c for send_msg in /home/vezia_l/rendu/PSU_2015_myftp/src
**
** Made by louis vezia
** Login   <vezia_l@epitech.net>
**
** Started on  Sun May 15 13:38:54 2016 louis vezia
** Last update	Sun May 15 15:43:28 2016 Louis Vezia
*/

#include "my_ftp.h"

int			send_msg(int fd, char *str)
{
  if (write(fd, str, strlen(str)) == -1)
    {
      perror("Error Write() in send_msg");
      return (1);
    }
  return (0);
}
