/*
** strcmp.c for strcmp.c in /home/ghikh_r/rendu/Piscine_C_J07
** 
** Made by raphael ghikh
** Login   <ghikh_r@epitech.net>
** 
** Started on  Tue Oct  6 16:46:09 2015 raphael ghikh
** Last update Tue Oct  6 17:29:42 2015 raphael ghikh
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i])
    {
      if (s1 < s2)
	{
	  return (-1);
	}
      if (s1 > s2)
	{
	  return (1);
	}
      i = i + 1;
    }
  if (s1 < s2)
    {
      return (-1);
    }
  if (s1 > s2)
    {
      return (1);
    }
  return (0);
}
