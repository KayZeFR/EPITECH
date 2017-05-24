/*
** my_getnbr.c for my_getnbr in /home/ghikh_r/rendu/Fonctions_C
** 
** Made by raphael ghikh
** Login   <ghikh_r@epitech.net>
** 
** Started on  Mon Oct 12 11:31:30 2015 raphael ghikh
** Last update Mon Oct 12 11:31:43 2015 raphael ghikh
*/


int     op_sign(char *str, int index)
{
  int   few;

  few = 0;
  index = index - 1;
  while (str[index] == '-' || str[index] == '+')
    {
      if (str[index] == '-')
        {
          few = few + 1;
        }
      index = index - 1;
    }
  few = few % 2;
  return (few);
}

long long       generate_int(char *str, int index, int sign)
{
  long  long    objectif;

  objectif = 0;
  while (str[index] >= 48 && str[index] <= 56)
    {
      objectif = (objectif * 10) + (str[index] - 48);
      index = index + 1;
    }
  if (sign == 1)
    {
      objectif = objectif * -1;
    }
  return (objectif);
}

int     my_getnbr(char *str)
{
  int	index;
  long long	objectif;
  long long     sign;

  objectif = 0;
  index = 0;
  sign = 0;
  while (str[index] != '\0')
    {
      if (str[index] >= 48 && str[index] <= 56)
        {
          if (index > 0)
            sign = op_sign(str, index);
          else
            sign = 0;
          objectif = generate_int(str, index, sign);
          return (objectif);
        }
      index = index + 1;
    }
  return (0);
}
