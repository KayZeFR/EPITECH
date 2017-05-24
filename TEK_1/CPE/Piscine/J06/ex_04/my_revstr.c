/*
** my_revstr.c for revstr.c in /home/ghikh_r/rendu/Piscine_C_J06
** 
** Made by raphael ghikh
** Login   <ghikh_r@epitech.net>
** 
** Started on  Mon Oct  5 13:03:23 2015 raphael ghikh
** Last update Tue Oct  6 20:37:31 2015 raphael ghikh
*/

char	*my_revstr(char *str)
{
  int	i;
  int	n;
  char	str2[] = "\0";

  i = 0;
  n = 0;
  while (str[i] != 0)
    {
      str2[i] = str[i];
      i = i + 1;
    }
  i = i - 1;
  while (str[n] != 0)
    {
      str[n] = str2[i];
      n = n + 1;
      i = i - 1;
    }
  return (*str);
}
