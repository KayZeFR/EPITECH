/*
** main.c for main in /home/ganem-_j/rendu/Piscine_C_infinadd
** 
** Made by johan ganem--brunet
** Login   <ganem-_j@epitech.net>
** 
** Started on  Mon Oct 19 15:30:17 2015 johan ganem--brunet
** Last update Mon Oct 19 20:24:58 2015 Raphael Ghikh
*/

void	my_putchar(char c)
{
  write(1, &c, 1);
}

/*

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      i = i + 1;
    }
  return (i);
}

int	my_put_nbr(int nb)
{
  if (nb >= 10)
    {
      my_put_nbr(nb / 10);
    }
  my_putchar(nb % 10 + '0');
}

  int	error(char *argv)
{
  int	idx1;
  int	idx2;
  int	tot1;
  int	tot2;
  char	*str;

  tot1 = my_strlen(argv);
  str = "0123456789";
  idx1 = 0;
  while (argv[idx1] != 0)
    {
      idx2 = 0;
      while (str[idx2] != 0)
	{
	  if (str[idx2] == argv[idx1]) 
	    {
	      tot2 = tot2 + 1;
	    }
	  idx2 = idx2 + 1;
	}
      idx1 = idx1 + 1;
    }
  error2(tot1, tot2, argv);
}
  
int	error2(int tot1, int tot2, char **argv)
{
  if (tot1 == tot2)
    {
      my_putstr("OK");
      my_putchar('\n');
      return (0);
    }
  else if (tot2 == tot1 - 1 && *argv[0] == '-')
    {
      my_putstr("OK");
      my_putchar('\n');
      return (0);
    }
  else
    {
      my_putstr("Caractères non-valides");
      my_putchar('\n');
      return (1);
    }
}
*/

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}

int	main(int argc, char **argv)
{
  char	*result;

  /*int	i;

  i = 1;
  my_putchar(argv[1]);
   if (argc != 3)
    {
      my_putstr("Nombre d'arguments entrés non-correct");
      my_putchar('\n');
      return (1);
    }/*
  /*while (i != argc)
    {
      error(argv[i]);
      i = i + 1;
    }
  */
  *result = inf_add(argv[1], argv[2]);
  my_putstr(result);
  return (0);
}
