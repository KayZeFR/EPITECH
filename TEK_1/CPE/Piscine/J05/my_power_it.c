/*
** my_power_it.c for my_power_it in /home/ghikh_r/rendu/Piscine_C_J05
** 
** Made by raphael ghikh
** Login   <ghikh_r@epitech.net>
** 
** Started on  Mon Oct  5 17:39:25 2015 raphael ghikh
** Last update Mon Oct  5 18:01:15 2015 raphael ghikh
*/

int	my_power_it(int nb, int power)
{
  int	total;

  total = nb;
  if (power != 0)
    {
      while (power != 1)
	{
	  total = total * nb;
	  power = power - 1;
	}
      return (total);
    }
  else if (power == 0)
    {
      return (1);
    }
  else
    {
      while (power != -1)
	{
	  total = total * (- nb);
	  power = power + 1;
	}
      return (total);
    }
}
