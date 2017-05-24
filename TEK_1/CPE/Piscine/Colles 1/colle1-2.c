/*
** colle1-2.c for colle1-2.c in /home/ghikh_r/rendu/Piscine_C_colles-Semaine_01
** 
** Made by raphael ghikh
** Login   <ghikh_r@epitech.net>
** 
** Started on  Sat Oct  3 14:52:16 2015 raphael ghikh
** Last update Sat Oct  3 18:32:02 2015 raphael ghikh
*/

int	my_putchar(char c)
{
  write(1, &c, 1);
}

int	colle(int x, int y)
{
  int	column;
  int	line;

  column = 0;
  line = 0;
  while (line != y)
    {
      column = 0;
      while (column != x)
	{
	  if (x == 1 || y == 1)
	    {
	      my_putchar('*');
	      column = column + 1;
	    }
	  else
	    {
	      sign(column, line, x, y);
	      column = column + 1;
	    }
	}
      my_putchar('\n');
      line = line + 1;
    }
}

int	sign(int column, int line, int x, int y)
{
  if ((column == 0 && line == 0) || (column == x - 1 && line == y - 1))
    {
      my_putchar('/');
    }
  else if ((column == 0 && line == y - 1) || (column == x - 1 && line == 0))
    {
      my_putchar('\\');
    }
  else if (column == 0 || column == x - 1 || line == 0 || line == y - 1)
    {
      my_putchar('*');
    }
  else
    {
      my_putchar(' ');
    }
}

int	main()
{
  colle(100, 100);
  return (0);
}
