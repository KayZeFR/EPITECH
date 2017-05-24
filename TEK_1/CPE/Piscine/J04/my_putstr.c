/*
** my_putstr.c for my_putstr.c in /home/ghikh_r/rendu/Piscine_C_J04
** 
** Made by raphael ghikh
** Login   <ghikh_r@epitech.net>
** 
** Started on  Thu Oct  1 21:53:05 2015 raphael ghikh
** Last update Fri Oct  2 10:34:36 2015 raphael ghikh
*/

int	my_putstr(char *str)
{
  char	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}
