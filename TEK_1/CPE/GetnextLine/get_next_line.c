/*
** get_next_line.c for get_next_line in /home/ghikh_r/ghikh_r/rendu/CPE_2015_getnextline
**
** Made by Ghikh
** Login   <ghikh_r@epitech.net>
**
** Started on  Wed Jan  6 09:04:05 2016 Ghikh
** Last update Sun Jan 17 20:00:46 2016 Ghikh
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"

char	*my_realloc(char *line, int len)
{
  static int	i;
  static char	*bigger_line;

  i = 0;
  if (len == 0 && ((line = malloc(READ_SIZE + 1)) == NULL))
    return (NULL);
  if (len == 0)
    return (line);
  if ((bigger_line = malloc(len + READ_SIZE + 1)) == NULL)
    return (NULL);
  while (i <= len)
    {
      bigger_line[i] = line[i];
      i = i + 1;
    }
  bigger_line[i] = '\0';
  free(line);
  return (bigger_line);
}

char	*readbuff(char *line, int len_line)

{
  static int	laps;

  if (len_line == 0)
    return (NULL);
  if (laps == 0)
    {
      laps = 1;
      return (line);
    }
  else
    return (NULL);
}

char	*get_next_line(const int fd)
{
  static int	i;
  static char	buffer[READ_SIZE];
  static int	len_line;
  static int	reaad;
  static char	*line;

  if (i == 0 && (reaad = read(fd, buffer, READ_SIZE)) <= 0)
    return (readbuff(line, len_line));
  if ((line = my_realloc(line, len_line)) == NULL)
    return (NULL);
  while (i < reaad)
    {
      if (buffer[i] == '\n')
	{
	  i = i + 1;
	  line[len_line] = '\0';
	  len_line = 0;
	  return (line);
	}
      line[len_line++] = buffer[i++];
    }
  i = 0;
  get_next_line(fd);
}
