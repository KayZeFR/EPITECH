/*
** my_get_next_line.c for getnextline in /home/vezia_l/rendu/PSU_2015_myftp/src
** 
** Made by louis vezia
** Login   <vezia_l@epitech.net>
** 
** Started on  Sun May 15 13:27:35 2016 louis vezia
** Last update Fri May 19 01:26:03 2017 Raphaël Ghikh
*/

#include "my_ftp.h"

char		*alloc_str(int len)
{
  char		*str;
  int		i;

  i = 0;
  if (len == 0)
    return (NULL);
  if (!(str = malloc(len + 1)))
    return (NULL);
  while (i < len)
    {
      str[i] = '\0';
      i++;
    }
  str[i] = '\0';
  return (str);
}

int		read_file(int fd, char *buffer, int *i_buff)
{
  int		size_read;

  *i_buff = 0;
  if ((size_read = read(fd, buffer, 1024)) == -1)
    return (-1);
  return (size_read);
}

char		*my_get_next_line(int fd)
{
  static char	buffer[1024];
  static int	size_read = -1;
  static int	i_buff = 0;
  char		*str;
  int		i;

  i = 0;
  str = alloc_str(sizeof(*str) * (1024 + 1));
  if (size_read == -1 || i_buff >= size_read)
    size_read = read_file(fd, buffer, &i_buff);
  while (i < 1024 && buffer[i_buff] != '\n' && size_read > 0)
    {
      str[i++] = buffer[i_buff++];
      if (i_buff >= size_read)
	size_read = read_file(fd, buffer, &i_buff);
    }
  if (buffer[i_buff] == '\n')
    i_buff++;
  if (size_read <= 0 && i == 0)
    {
      free(str);
      return (NULL);
    }
  str[i] = '\0';
  return (str);
}
