/*
** my_strncat.c for strncat.c in /home/ghikh_r/rendu/Piscine_C_J07/ex_03
** 
** Made by raphael ghikh
** Login   <ghikh_r@epitech.net>
** 
** Started on  Wed Oct  7 14:54:57 2015 raphael ghikh
** Last update Mon Oct 12 10:29:43 2015 raphael ghikh
*/

char	*my_strncat(char *dest, char *src, int nb)
{
  int	a;
  int	i;

  i = 0;
  a = my_strlen(dest);
  while (src[i] && nb != 0)
    {
      dest[a] = src[i];
      a = a + 1;
      i = i + 1;
      nb = nb - 1;
    }
  dest[a + 1] = 0;
  return (dest);
}
