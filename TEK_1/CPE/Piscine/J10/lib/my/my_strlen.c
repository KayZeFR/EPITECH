/*
** my_strlen.c for my_strlen in /home/ghikh_r/rendu/Fonctions_C
** 
** Made by raphael ghikh
** Login   <ghikh_r@epitech.net>
** 
** Started on  Mon Oct 12 11:33:43 2015 raphael ghikh
** Last update Mon Oct 12 11:33:45 2015 raphael ghikh
*/


int     my_strlen(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}
