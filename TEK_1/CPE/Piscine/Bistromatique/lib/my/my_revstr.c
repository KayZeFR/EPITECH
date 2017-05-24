/*
** my_revstr.c for revstr.c in /home/ghikh_r/rendu/Piscine_C_J06
** 
** Made by raphael ghikh
** Login   <ghikh_r@epitech.net>
** 
** Started on  Mon Oct  5 13:03:23 2015 raphael ghikh
** Last update Mon Oct 12 11:28:06 2015 raphael ghikh
*/

int	my_swap(char *a, char *b);
int	my_strlen(char *str);

char	*my_revstr(char *str)
{
  int	a;
  int	i;

  i = 0;
  a = my_strlen(str) - 1;
  while (i != (1 / 2) + 1)
    {
      my_swap_char(&str[a - i], &str[i]);
      i = i + 1;
    }
  return (str);
}
