/*
** my_strlen.c for my_strlen.c in /home/ghikh_r/rendu/Piscine_C_J04
** 
** Made by raphael ghikh
** Login   <ghikh_r@epitech.net>
** 
** Started on  Fri Oct  2 08:56:51 2015 raphael ghikh
** Last update Fri Oct  2 10:33:53 2015 raphael ghikh
*/

int	my_strlen(char *str)
{
  char	i;

  i = 0;
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}
