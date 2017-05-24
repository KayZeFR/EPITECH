/*
** my_put_nbr.c for my_put_nbr in /home/ghikh_r/rendu/fonctions_utiles
** 
** Made by raphael ghikh
** Login   <ghikh_r@epitech.net>
** 
** Started on  Sun Oct  4 19:21:51 2015 raphael ghikh
** Last update Sat Nov 21 20:52:18 2015 Raphael Ghikh
*/

int	my_put_nbr(char nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
    }
  if (nb >= 10)
    my_put_nbr(nb / 10);
  my_putchar(nb % 10 + '0');
}
