/*
** my_strlowcase.c for strlowcase in /home/ghikh_r/rendu/Fonctions_C
** 
** Made by raphael ghikh
** Login   <ghikh_r@epitech.net>
** 
** Started on  Mon Oct 12 10:56:42 2015 raphael ghikh
** Last update Mon Oct 12 10:59:17 2015 raphael ghikh
*/

char	*my_strlowcase(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      if (str[i] >= 'A' && str[i] <= 'Z')
	str[i] = str[i] + 32;
      i = i + 1;
    }
  return (str);
}
