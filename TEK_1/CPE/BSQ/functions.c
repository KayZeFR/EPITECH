/*
** functions.c for bsq in /home/ghikh_r/ghikh_r/rendu/C_Prog_Elem/CPE_2015_BSQ
**
** Made by Ghikh
** Login   <ghikh_r@epitech.net>
**
** Started on  Tue Dec 15 11:58:35 2015 Ghikh
** Last update Tue Dec 15 12:00:15 2015 Ghikh
*/

int	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      i = i + 1;
      my_putchar(str[i]);
    }
}
