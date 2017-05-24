/*
** my_put_nbr.c for my_put_nbr in /home/ghikh_r/rendu/fonctions_utiles
** 
** Made by raphael ghikh
** Login   <ghikh_r@epitech.net>
** 
** Started on  Sun Oct  4 19:21:51 2015 raphael ghikh
** Last update Tue Oct  6 10:31:29 2015 raphael ghikh
*/

int	my_put_nbr(int nb)
{
  int	i;

  i = 0;
  if (nb < 0)
    {
      my_putchar('-');
      if (nb == - 2147483648)
	{
	  i = 1;
	  i = i + 1;
	}
      nb = nb * -1;
    }
  if (nb >= 10)
    {
      my_put_nbr(nb / 10);
    }
  if (i == 1)
    {
      i = 0;
      my_putchar(nb % 10 + '1');
    }
  else
    {
      my_putchar(nb % 10 + '0');
    }
}
