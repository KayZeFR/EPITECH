/*
** my_str_to_word_tab.c for strtowordtab in /home/vezia_l/rendu/PSU_2015_myftp/src
** 
** Made by louis vezia
** Login   <vezia_l@epitech.net>
** 
** Started on  Sun May 15 13:27:57 2016 louis vezia
** Last update Fri May 19 01:26:16 2017 Raphaël Ghikh
*/

#include "my_ftp.h"

int		find_word(char *str)
{
  int		nb;
  int		i;
  int		first_word;

  first_word = 0;
  i = 0;
  nb = 0;
  while (str[i])
    {
      if ((str[i] != ' ' || str[i] != '\t') && first_word == 0)
	{
	  first_word = 1;
	  nb = 1;
	}
      if ((str[i] == ' ' || str[i] == '\t') && first_word == 1)
	nb = nb + 1;
      i++;
    }
  return (nb);
}

char		*fill_tab(char *str, int i)
{
  char		*tmp;
  int		i_tmp;

  i_tmp = 0;
  if ((tmp = malloc(sizeof(char) * strlen(str) + 1)) == NULL)
    return (NULL);
  while (str[i] && str[i] != ' ' && str[i] != '\t')
    tmp[i_tmp++] = str[i++];
  tmp[i_tmp] = '\0';
  return (tmp);
}

char		**my_str_to_word_tab(char *str)
{
  char		**tab;
  int		nbr_word;
  int		loop_tab;
  int		i;

  i = 1;
  loop_tab = 1;
  nbr_word = find_word(str);
  if ((tab = malloc(sizeof(tab) * (nbr_word + 1))) == NULL)
    return (NULL);
  tab[0] = fill_tab(str, 0);
  while (str[i] && loop_tab < nbr_word)
    {
      if (str[i] != ' ' && str[i] != '\t' &&
	  (str[i - 1] == ' ' || str[i - 1] == '\t'))
	{
	  tab[loop_tab] = fill_tab(str, i);
	  loop_tab++;
	}
      i++;
    }
  tab[loop_tab] = NULL;
  return (tab);
}
