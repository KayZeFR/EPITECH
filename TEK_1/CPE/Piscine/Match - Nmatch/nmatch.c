/*
** nmatch.c for nmatch.c in /home/ghikh_r/rendu/Match_TEST
** 
** Made by raphael ghikh
** Login   <ghikh_r@epitech.net>
** 
** Started on  Fri Oct  9 22:57:30 2015 raphael ghikh
** Last update Sun Oct 11 18:00:27 2015 raphael ghikh
*/

int	nmatch(char *s1, char *s2)
{
  if (*s1 != '\0' && *s2 == '*')
    {
      return (nmatch(s1 + 1, s2) + nmatch(s1, s2 + 1));
    }
  if (*s1 == '\0' && *s2 == '*')
    {
      return (nmatch(s1, s2 + 1));
    }
  if (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
    {
      return (nmatch(s1 + 1, s2 + 1));
    }
  if (*s1 == *s2 && *s1 == '\0' && *s2 == '\0')
    {
      return (1);
    }
  return (0)
}
