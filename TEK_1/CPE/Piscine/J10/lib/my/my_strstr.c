/*
** my_strstr.c for my_strstr.c in /home/ghikh_r/rendu/Piscine_C_J06/ex_05
** 
** Made by raphael ghikh
** Login   <ghikh_r@epitech.net>
** 
** Started on  Tue Oct  6 10:39:45 2015 raphael ghikh
** Last update Tue Oct  6 20:38:46 2015 raphael ghikh
*/

char	*my_strstr(char *str, char *to_find)
{
  int   i;
  int   j;

  i = 0;
  j = 0;
  while (str[i] != 0)
    {
      while (str[i] == to_find[j])
        {
          if (to_find[j + 1] == 0)
            {
              return (&str[i - j]);
            }
          i = i + 1;
          j = j + 1;
        }
      i = i + 1;
      j = 0;
    }
  return (0);
}
