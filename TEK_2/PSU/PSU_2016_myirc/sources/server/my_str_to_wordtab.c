/*
** my_str_to_wordtab.c for irc in /home/kayzefr/EPITECH/TEK/PSU_2016_myirc/sources/server
** 
** Made by Raphaël Ghikh
** Login   <raphael.ghikh@epitech.eu>
** 
** Started on  Sat May 27 14:28:11 2017 Raphaël Ghikh
** Last update Sun Jun 11 15:55:45 2017 Raphaël Ghikh
*/

#include "server.h"

int	count_words(char *str, char sep)
{
  int	i;
  int	w;

  w = 1;
  i = 0;
  while (str[i])
    {
      if (str[i] == sep)
	w++;
      i++;
    }
  return (w);
}

int	word_char(char *str, char sep, int i)
{
  int	j;

  j = 0;
  while ((str[i] != sep) && str[i])
    {
      i++;
      j++;
    }
  return (j);
}

void	*my_xmalloc(size_t size)
{
  char	*dest;

  dest = malloc(size);
  if (!dest)
    error("malloc");
  return (dest);
}

char	**my_str_to_wordtab(char *str, char sep)
{
  int	a;
  int	i;
  int	b;
  int	count;
  char	**t;

  b = 0;
  i = 0;
  count = 0;
  a = count_words(str, sep);
  if (!(t = my_xmalloc((a + 1) * sizeof(char *))))
    return (NULL);
  while (count < a)
    {
      b = word_char(str, sep, i);
      if (!(t[count] = my_xmalloc((b + 1) * sizeof(char))))
				return (NULL);
      t[count][b] = '\0';
      strncpy(t[count++], &str[i], b);
      i = i + b;
      while (str[i] == sep)
	i++;
    }
  t[count] = NULL;
  return (t);
}
