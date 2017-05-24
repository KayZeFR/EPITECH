/*
** my_strcat.c for my_strcat.c in /home/ghikh_r/rendu
** 
** Made by raphael ghikh
** Login   <ghikh_r@epitech.net>
** 
** Started on  Sat Oct 10 15:50:35 2015 raphael ghikh
** Last update Mon Oct 12 13:49:19 2015 raphael ghikh
*/

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;

  if (dest == '\0' || src == '\0')
    {
      return ('\0');
    }
  while (dest[i])
    {
      i = i + 1;
    }
  while (src[j])
    {
      dest[i] = src[j];
      i = i + 1;
      j = j + 1;
    }
  dest[i] = 0;
  return (dest);
}
