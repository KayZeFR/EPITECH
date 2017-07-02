/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/raphael.dusautoy/rendus/SystemeUnix/myirc/src_client
** 
** Made by Raphael Dusautoy
** Login   <raphael.dusautoy@epitech.net>
** 
** Started on  Tue Jun 06 13:14:56 2017 Raphael Dusautoy
** Last update Sun Jun 11 23:02:14 2017 Raphael Dusautoy
*/

#include	<stdlib.h>

static int	count_words(char *str, char c)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (str[i] != 0)
    {
      if (str[i] == c)
        j++;
      i++;
    }
  return (i + 1);
}

static int	my_strnlen(char *str, char c)
{
  int		i;

  i = 0;
  while (str[i] && str[i] != c)
    i++;
  return (i);
}

char		**my_str_to_wordtab(char *str, char c)
{
  int		k;
  int		j;
  int		i;
  char		**tab;

  i = 0;
  j = 0;
  tab = malloc(sizeof(char*) * (count_words(str, c) + 1));
  while (str[i])
    {
      k = 0;
      tab[j] = malloc(sizeof(char) * (my_strnlen(str, c) + 50));
      while (str[i] != c && str[i] != '\0')
	tab[j][k++] = str[i++];
      tab[j++][k] = '\0';
      if (str[i] != '\0')
	i++;
    }
  tab[j] = NULL;
  return (tab);
}
