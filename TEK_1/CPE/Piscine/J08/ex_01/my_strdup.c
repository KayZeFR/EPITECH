/*
** my_strdup.c for my_strdup in /home/ghikh_r/rendu/Piscine_C_J08/ex_01
** 
** Made by raphael ghikh
** Login   <ghikh_r@epitech.net>
** 
** Started on  Wed Oct  7 13:51:07 2015 raphael ghikh
** Last update Thu Oct  8 17:24:28 2015 raphael ghikh
*/

#include <stdlib.h>
#include <my.h>

char	*my_strdup(char *src)
{
  int	a;
  char	*dest;

  a = 0;
  a = my_strlen(src);
  src = malloc(a);
  while (src[a] != '\0')
    {
      dest[a] = src[a] * my_strlen(src) + 1;
      dest[a] = src[a];
      dest[my_strlen(src)] = 0;
    }
  return (dest);
}
