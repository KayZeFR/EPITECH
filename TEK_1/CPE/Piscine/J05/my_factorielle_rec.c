/*
** my_factorielle_rec.c for my_factorielle_rec.c in /home/ghikh_r/rendu/Piscine_C_J05
** 
** Made by raphael ghikh
** Login   <ghikh_r@epitech.net>
** 
** Started on  Sun Oct  4 19:01:55 2015 raphael ghikh
** Last update Mon Oct  5 22:58:50 2015 raphael ghikh
*/

int	fact(n, nb, total)
{
  if ( n == nb)
    {
      return (total);
    }
  total = total * n;
  n = n + 1;
  fact(n, nb, total);
}

int	my_factorielle_rec(int nb)
{
  int	n;
  int	total;

  total = nb;
  n = 1;
  if (nb > 0 && nb <= 12)
    {
      fact(n, nb, total);
    }
  else if (nb == 0)
    {
      return (1);
    }
  else
    {
      return (0);
    }
}
