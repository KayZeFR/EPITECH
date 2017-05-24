/*
** my_strcapitalize.c for strcapitalize in /home/ghikh_r/rendu/Fonctions_C
** 
** Made by raphael ghikh
** Login   <ghikh_r@epitech.net>
** 
** Started on  Mon Oct 12 11:08:20 2015 raphael ghikh
** Last update Mon Oct 12 11:15:44 2015 raphael ghikh
*/

char	*my_strlowcase(char *str);

char	*my_strcapitalize(char *str)
{
  int	i;

  i = 0;
  str = my_strlowcase(str);
  while (str[i] != 0)
    {
      if (i == 0)
	if (str[i] >= 'a' && str[i] <= 'z')
	  str[i] = str[i] - 32;
      if (str[i] == ' ' || str[i] == '+' || str[i] == '-')
	{
	  if (str[i + 1] >= 'a' && str[i + 1] <= 'z')
	    str[i + 1] = str[i + 1] - 32;
	}
      i = i + 1;
    }
  return (str);
}
