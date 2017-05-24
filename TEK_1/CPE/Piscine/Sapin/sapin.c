/*
** triangle.c for triangle.c in /home/ghikh_r/rendu
** 
** Made by raphael ghikh
** Login   <ghikh_r@epitech.net>
** 
** Started on  Sun Oct  4 19:51:45 2015 raphael ghikh
** Last update Sun Oct  4 23:23:25 2015 raphael ghikh
*/

int	print_stage(int jump, int stars)
{
  int	countjump;
  int	countstars;

  countjump = 0;
  countstars = 0;
  while (jump != countjump)
    {
      while (countstars != stars)
	{
	  my_putchar('*');
	  countstars = countstars + 1;
	}
      my_putchar('\n');
      stars = stars + 2;
      countjump = countjump + 1;
      countstars = 0;
    }
  return (stars - 2);
}

void	sapin(int taille)
{
  int	stars;
  int	jump;
  int	i;

  i = 1;
  stars = 1;
  while (i <= taille)
    {
      jump = 4 + i - 1;
      if (i % 2 == 0)
	{
	  stars = stars - i;
	}
      else
	{
	  stars = stars - (i - 1);
	}
      stars = print_stage(jump, stars);
      i++;
    }
  lastsapin(taille);
  my_putchar('\n');
}

int	lastsapin(int taille)
{
  int	lines;
  int	columns;

  lines = 0;
  while (lines != taille)
    {
      columns = 0;
      while (columns != taille)
	{
	  columns = columns + 1;
	  my_putchar('|');
	}
      my_putchar('\n');
      lines = lines + 1;
    }
}
