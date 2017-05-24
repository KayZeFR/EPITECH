/*
** my_aff_comb.c for my_aff_comb.c in /home/ghikh_r/rendu/Piscine_C_J03
** 
** Made by raphael ghikh
** Login   <ghikh_r@epitech.net>
** 
** Started on  Wed Sep 30 14:41:18 2015 raphael ghikh
** Last update Thu Oct  1 13:30:12 2015 raphael ghikh
*/

int	display(char a, char b, char c)
{
  if (a == '7' && b == '8' && c == '9')
    {
      my_putchar(a);
      my_putchar(b);
      my_putchar(c);
    }
  else
    {
      my_putchar(a);
      my_putchar(b);
      my_putchar(c);
      my_putchar(',');
      my_putchar(' ');
    }
}

int	my_aff_comb()
{
  char	a;
  char	b;
  char	c;

  a = '0';
  b = '1';
  c = '1';
  while (c < '9')
    {
      c = c + 1;
      if (c == '9')
	{
	  display(a, b, c);
	  b = b + 1;
	  c = b + 1;
	}
      if (b == '8')
	{
	  display(a, b, c);
	  a = a + 1;
	  b = a + 1;
	  c = a + 2;
	}
      display(a, b, c);
    }
}
