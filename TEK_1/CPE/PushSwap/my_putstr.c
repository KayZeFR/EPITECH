/*
** my_putstr.c for my_putstr in /home/ghikh_r/rendu/Fonctions_C
** 
** Made by raphael ghikh
** Login   <ghikh_r@epitech.net>
** 
** Started on  Mon Oct 12 11:32:29 2015 raphael ghikh
** Last update Sun Nov 22 12:26:59 2015 Raphael Ghikh
*/


void    my_putstr(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}
