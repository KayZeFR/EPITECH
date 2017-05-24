/*
** my_strcpy.c for strcpy.c in /home/ghikh_r/rendu/Piscine_C_J06
** 
** Made by raphael ghikh
** Login   <ghikh_r@epitech.net>
** 
** Started on  Mon Oct  5 09:41:16 2015 raphael ghikh
** Last update Tue Oct  6 20:35:19 2015 raphael ghikh
*/

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
  {
    dest[i] = src[i];
    i = i + 1;
  }
  return (dest);
}
