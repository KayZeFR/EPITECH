/*
** disp_add.c for add in /home/ganem-_j/rendu/Piscine_C_bistromathique
** 
** Made by johan ganem--brunet
** Login   <ganem-_j@epitech.net>
** 
** Started on  Sun Nov  1 16:32:51 2015 johan ganem--brunet
** Last update Sun Nov  1 16:38:20 2015 johan ganem--brunet
*/

int	disp(int length1, int count, int *result, int k)
{
  int	i;

  i = 0;
  if (k > 10 && length1 == 1)
    {
      my_putchar('1');
    }
  while (length1 != -1)
    {
      if (count == 0 && i == 0)
	{
	  my_putchar('\0');
	}
      else if (i != 0)
	{
	  my_put_nbr(result[i]);
	}
      else if (count != 0)
	{
	  my_putchar('1');
	  count = 0;
	}
      i = i + 1;
      length1 = length1 - 1;
    }
}
