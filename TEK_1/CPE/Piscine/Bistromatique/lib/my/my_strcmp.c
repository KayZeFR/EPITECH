/*
** strcmp.c for strcmp.c in /home/ghikh_r/rendu/Piscine_C_J07
** 
** Made by raphael ghikh
** Login   <ghikh_r@epitech.net>
** 
** Started on  Tue Oct  6 16:46:09 2015 raphael ghikh
** Last update Mon Oct 12 13:49:55 2015 raphael ghikh
*/

int	my_strcmp(char *s1, char *s2)
{
  while (*s1 && *s2)
    {
      if (*s1 !=*s2)
	return (*s1 - *s2);
      s1 = s1 + 1;
      s2 = s2 + 1;
    }
  if (*s1 != *s2)
    return (*s1 - *s2);
  else
    return (0);
}
