/*
** my_strncat.c for strncat.c in /home/ghikh_r/rendu/Piscine_C_J07/ex_03
** 
** Made by raphael ghikh
** Login   <ghikh_r@epitech.net>
** 
** Started on  Wed Oct  7 14:54:57 2015 raphael ghikh
** Last update Wed Oct  7 17:02:16 2015 raphael ghikh
*/

char	*my_strncat(char *dest, char *src, int nb)
{
  int	a;
  int	b;

  a = 0;
  b = 0;
  while (dest[a] != 0)
    {
      my_putchar(dest[a]);
      a = a + 1;
    }
  while (src[b] =! 0)
    {
      my_putchar(src[b]);
      b = b + 1;
    }
  if (!src[n - 1])
    {
      dest[a] = '\0';
    }
}
