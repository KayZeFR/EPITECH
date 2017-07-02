/*
** strcat.c for strcat in /home/raphael.dusautoy/rendus/myirc/client
** 
** Made by Raphael Dusautoy
** Login   <raphael.dusautoy@epitech.net>
** 
** Started on  Fri Jun  2 13:43:15 2017 Raphael Dusautoy
** Last update Sun Jun 11 23:25:17 2017 Raphaël Ghikh
*/

#include			"client.h"

char				*xstrcat(char *s, char *d)
{
  char				*r;

  r = malloc(strlen(s) + strlen(d) + 5);
  if (r == NULL)
    return (NULL);
  strcpy(r, s);
  strcat(r, d);
  return (r);
}

void				my_putchar(char c)
{
  write (1, &c, 1);
}

char				*my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i++;
    }
  return (str);
}
