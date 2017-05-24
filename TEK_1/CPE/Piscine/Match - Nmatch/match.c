/*
** match1.c for match.c in /home/ghikh_r/rendu/Match_TEST
** 
** Made by raphael ghikh
** Login   <ghikh_r@epitech.net>
** 
** Started on  Fri Oct  9 22:51:23 2015 raphael ghikh
** Last update Sun Oct 11 15:29:09 2015 raphael ghikh
*/

int	match(char *s1, char *s2)
{
  if (*s1 != '\0' && *s2 == '*')
    {
      return (match(s1 + 1, s2) || match(s1, s2 + 1));
    }
  if (*s1 == '\0' && *s2 == '*')
    {
      return (match(s1, s2 + 1));
    }
  if (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
    {
      return (match(s1 + 1, s2 + 1));
    }
  if (*s1 == *s2 && *s1 == '\0' && *s2 == '\0')
    {
      return (1);
    }
  return (0);
}
