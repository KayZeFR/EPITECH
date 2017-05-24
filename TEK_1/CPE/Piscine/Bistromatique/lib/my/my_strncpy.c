/*
** my_strncpy.c for strncpy.c in /home/ghikh_r/rendu/Piscine_C_J06
** 
** Made by raphael ghikh
** Login   <ghikh_r@epitech.net>
** 
** Started on  Mon Oct  5 11:25:53 2015 raphael ghikh
** Last update Mon Oct 12 10:21:08 2015 raphael ghikh
*/

int	my_strlen(char *str);

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;
  int	c;
  int	regist;

  i = 0;
  regist = n;
  while (src[i] != 0 && n != 0)
    {
      c = src[i];
      dest[i] = c;
      i = i + 1;
      n = n - 1;
    }
  if (my_strlen(src) < regist)
    dest[i] = '\0';
  return (dest);
}
