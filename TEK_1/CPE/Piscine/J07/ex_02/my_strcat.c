/*
** my_strcat.c for my_strcat.c in /home/ghikh_r/rendu/Piscine_C_J07/ex_02
** 
** Made by raphael ghikh
** Login   <ghikh_r@epitech.net>
** 
** Started on  Tue Oct  6 10:49:04 2015 raphael ghikh
** Last update Wed Oct  7 18:13:42 2015 raphael ghikh
*/

char	*my_strcat(char *dest, char *src)
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
  while (src[b] != 0)
    {
      my_putchar(src[b]);
      b = b + 1;
    }
}
