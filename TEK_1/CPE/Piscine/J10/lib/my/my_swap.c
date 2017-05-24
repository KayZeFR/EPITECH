/*
** my_swap.c for my_swap.c in /home/ghikh_r/rendu/Piscine_C_J04
** 
** Made by raphael ghikh
** Login   <ghikh_r@epitech.net>
** 
** Started on  Thu Oct  1 18:51:09 2015 raphael ghikh
** Last update Fri Oct  2 10:31:18 2015 raphael ghikh
*/

void	my_swap(int *a, int *b)
{
  int	c;

  c = *a;
  *a = *b;
  *b = c;
}
