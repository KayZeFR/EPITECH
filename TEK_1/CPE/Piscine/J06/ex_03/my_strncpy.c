/*
** my_strncpy.c for strncpy.c in /home/ghikh_r/rendu/Piscine_C_J06
** 
** Made by raphael ghikh
** Login   <ghikh_r@epitech.net>
** 
** Started on  Mon Oct  5 11:25:53 2015 raphael ghikh
** Last update Tue Oct  6 20:51:20 2015 raphael ghikh
*/

char	*my_strncpy(char *dest, char *src, int n)
{
  int	a;

  a = 0;
  while (src[a] && a < n)
    {
      dest[a] = src[a];
      a = a + 1;
    }
  if (!src[n - 1])
    {
      dest[a] = '\0';
    }
  return (dest);
}
