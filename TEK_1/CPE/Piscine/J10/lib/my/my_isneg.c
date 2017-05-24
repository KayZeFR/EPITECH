/*
** my_isneg.c for my_isneg in /home/ghikh_r/rendu/Fonctions_C
** 
** Made by raphael ghikh
** Login   <ghikh_r@epitech.net>
** 
** Started on  Mon Oct 12 11:37:59 2015 raphael ghikh
** Last update Mon Oct 12 11:39:14 2015 raphael ghikh
*/

void	my_putchar(char c);

int	my_isneg(int n)
{
  if (n < 0)
    my_putchar('N');
  if(n >= 0)
    my_putchar('P');
  return (0);
}
