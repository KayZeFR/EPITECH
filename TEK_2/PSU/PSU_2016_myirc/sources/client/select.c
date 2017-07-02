/*
** select.c for my_select in /home/raphael.dusautoy/rendus/SystemeUnix/myirc/src_select
** 
** Made by Raphael Dusautoy
** Login   <raphael.dusautoy@epitech.net>
** 
** Started on  Sun Jun 04 11:34:09 2017 Raphael Dusautoy
** Last update Sun Jun 11 22:34:47 2017 Raphael Dusautoy
*/

#include	<sys/select.h>
#include	<stdio.h>

int		my_select(int fd_max, fd_set *fd_read, fd_set *fd_write)
{
  struct timeval	tv;
  tv.tv_sec = 20;
  tv.tv_usec = 0;
  if (select(fd_max + 1, fd_read, fd_write, NULL, &tv) == -1)
    {
      fprintf(stderr, "[Error] Select failed");
      return (1);
    }
  return (0);
}
