/*
** my_isneg.c for my_isneg.c in /home/ghikh_r/rendu/Piscine_C_J03
** 
** Made by raphael ghikh
** Login   <ghikh_r@epitech.net>
** 
** Started on  Wed Sep 30 11:45:49 2015 raphael ghikh
** Last update Thu Oct  1 18:38:31 2015 raphael ghikh
*/

int	my_isneg(int n)
{
  if (n >= 0)
    {
      my_putchar('P');
    }
  if (n < 0)
    {
      my_putchar('N');
    }
}
