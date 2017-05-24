/*
** my_atoi.c for lib in /home/ghikh_r/rendu/Bootstrap_Pushwap/test
** 
** Made by Raphael Ghikh
** Login   <ghikh_r@epitech.net>
** 
** Started on  Thu Nov 19 16:34:19 2015 Raphael Ghikh
** Last update Thu Nov 19 16:37:52 2015 Raphael Ghikh
*/

int	my_atoi(const char *str)
{
  int	i;
  int	j;
  int	idx;

  idx = 0;
  i = 0;
  j = 0;
  if (str[0] == '-')
    {
      idx = 1;
      i = 1;
    }
  while (str[i] != 0)
    {
      if (str[i] >= '0' && str[i] <= '9')
	{
	  j = j * 10;
	  j = j + str[i] - '0';
	}
      i = i + 1;
    }
  if (idx == 1)
    j = -j;
  return (j);
}
