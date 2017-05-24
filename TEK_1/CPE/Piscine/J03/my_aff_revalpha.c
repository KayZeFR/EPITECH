/*
** my_aff_revalpha.c for my_aff_revalpha.c in /home/ghikh_r/rendu/Piscine_C_J03
** 
** Made by raphael ghikh
** Login   <ghikh_r@epitech.net>
** 
** Started on  Wed Sep 30 10:44:40 2015 raphael ghikh
** Last update Thu Oct  1 13:36:04 2015 raphael ghikh
*/

int	my_aff_revalpha()
{
  char	c;
  
  c = 122;
  while (c != 96)
    {
      my_putchar(c);
      c = c - 1;
    }
}
