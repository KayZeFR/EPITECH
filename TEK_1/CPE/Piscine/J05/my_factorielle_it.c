/*
** my_factorielle_it.c for my_factorielle_it.c in /home/ghikh_r/rendu/Piscine_C_J05
** 
** Made by raphael ghikh
** Login   <ghikh_r@epitech.net>
** 
** Started on  Fri Oct  2 19:46:31 2015 raphael ghikh
** Last update Mon Oct  5 17:56:49 2015 raphael ghikh
*/

int	my_factorielle_it(int nb)
{
  int	n;
  int	i;

  n = 1;
  i = nb;
  if (nb > 0 && nb <= 12)
    {
      while (n != nb)
	{
	  i = i * (nb - 1);
	  nb = nb - 1;
	}
	  return (i);
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
