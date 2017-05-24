/*
** game_player_one.c for Allum1 in /home/ghikh_r/rendu/CPE_2015_Allum1
** 
** Made by raphael ghikh
** Login   <ghikh_r@epitech.net>
** 
** Started on  Tue Feb  9 15:50:49 2016 raphael ghikh
** Last update Fri Feb 26 16:17:09 2016 Raphael Ghikh
*/

#include <stdlib.h>
#include "allum.h"

void	error(int *line, int choice_allum, int choice_line)
{
  if (choice_allum > line[choice_line])
    {
      my_putstr("Error: not enough matches on this line\n");
      line_choice(line);
    }
  else if (choice_allum == 0)
    {    
      my_putstr("Error: you have to remove at least one match\n");
      line_choice(line);
    } 
  else if (choice_allum < 0)
    {
      my_putstr("Error: invalid input (positive number expected)\n");
      line_choice(line);
    }
}

int	allum_choice(int *line, int choice_line)
{
  int	choice_allum;
  char	*tmp;

  tmp = malloc(sizeof(char*));
  while (42)
    {
      my_putstr("Matches: ");
      tmp = get_next_line(0);
      if (tmp == NULL)
	return (-1);
      choice_allum = my_getnbr(tmp);
      if (choice_allum > 0 && choice_allum <= line[choice_line])
	{
	  line[choice_line] = line[choice_line] - choice_allum;
	  my_putstr("Player removed ");
	  my_putnbr(choice_allum);
	  my_putstr(" match(es) from line ");
	  my_putnbr(choice_line + 1);
	  my_putchar('\n');
	  print_match(line);
	  if (count_allum(line) == 0)
	    my_putstr("You lost, too bad..\n");
	  return (EXIT_SUCCESS);
	}
      else
	error(line, choice_allum, choice_line);
    }
  free(tmp);
}

int	line_choice(int *line)
{
  int	choice_line;
  char	*tmp;

  choice_line = 0;
  tmp = malloc(sizeof(char*));
  while (42)
    {
      my_putstr("Line: ");
      tmp = get_next_line(0);
      if (tmp == NULL)
	return (-1);
      choice_line = my_getnbr(tmp);
      if (choice_line > 0 && choice_line < 5 && line[choice_line - 1] != 0)
	return (choice_line - 1);
      else if (choice_line > 5 || choice_line == 0)
	my_putstr("Error: this line is out of range\n");
      else if (choice_line < 0)
	my_putstr("Error: invalid input (positive number expected)\n");
    }
  free(tmp);
  return (0);
}

int	player_one(int *line)
{
  int	choice_line;
  int	choice_allum;

  my_putstr("Your turn:\n");
  choice_line = line_choice(line);
  if (choice_line == - 1)
    return (1);
  choice_allum = allum_choice(line, choice_line);
  if (choice_allum == - 1)
    return (1);
  return (0);
}
