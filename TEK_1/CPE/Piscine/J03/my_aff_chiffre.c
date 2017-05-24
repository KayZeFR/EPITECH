/*
** my_aff_chiffre.c for my_aff_chiffre.c in /home/ghikh_r/rendu/Piscine_C_J03
** 
** Made by raphael ghikh
** Login   <ghikh_r@epitech.net>
** 
** Started on  Wed Sep 30 11:34:58 2015 raphael ghikh
** Last update Thu Oct  1 18:11:10 2015 raphael ghikh
*/

int	my_aff_chiffre()
{
  char	c;

  c = 48;
  while (c != 58)
    {
      my_putchar(c);
      c = c + 1;
    }
}
