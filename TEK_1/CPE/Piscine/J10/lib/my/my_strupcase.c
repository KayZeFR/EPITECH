/*
** my_strupcase.c for my_strupcase in /home/ghikh_r/rendu/Fonctions_C
** 
** Made by raphael ghikh
** Login   <ghikh_r@epitech.net>
** 
** Started on  Mon Oct 12 10:00:12 2015 raphael ghikh
** Last update Mon Oct 12 10:04:22 2015 raphael ghikh
*/

char	*my_strupcase(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 'a' && str[i] <= 'z')
	str[i] = str[i] - 32;
      i = i + 1;
    }
  return (str);
}
