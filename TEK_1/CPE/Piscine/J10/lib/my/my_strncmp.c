/*
** my_strncmp.c for my_strncmp in /home/ghikh_r/rendu/Fonctions_C
** 
** Made by raphael ghikh
** Login   <ghikh_r@epitech.net>
** 
** Started on  Mon Oct 12 10:21:38 2015 raphael ghikh
** Last update Mon Oct 12 10:24:14 2015 raphael ghikh
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  while (*s1 != 0 && *s2 != 0 && n != 0)
    {
      if (*s1 != *s2)
	return (*s1 - *s2);
      s1 = s1 + 1;
      s2 = s2 + 1;
      n = n - 1;
    }
  return (0);
}
