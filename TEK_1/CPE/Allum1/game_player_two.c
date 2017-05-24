/*
** game_player_two.c for allum1 in /home/ghikh_r/rendu/CPE_2015_Allum1
** 
** Made by raphael ghikh
** Login   <ghikh_r@epitech.net>
** 
** Started on  Tue Feb  9 16:26:45 2016 raphael ghikh
** Last update Fri Feb 26 16:06:04 2016 Raphael Ghikh
*/

#include <stdlib.h>
#include <time.h>
#include "allum.h"

int	allum_choice_ordi(int *line, int choice_line_ordi)
{
  int	choice_allum_ordi;

  choice_allum_ordi = 0;
  while (42)
    {  
      choice_allum_ordi = (rand() % 2);
      if (choice_allum_ordi > 0 && choice_allum_ordi <= line[choice_line_ordi])
	{
	  line[choice_line_ordi] = line[choice_line_ordi] - choice_allum_ordi;
	  my_putstr("AI removed ");
	  my_putnbr(choice_allum_ordi);
	  my_putstr(" match(es) from line ");
	  my_putnbr(choice_line_ordi + 1);
	  my_putchar('\n');
	  print_match(line);
	  if (count_allum(line) == 0)
	    my_putstr("I lost.. snif.. but I'll get you next time!!\n");
	  return (EXIT_SUCCESS);
	}
    }
}

int	line_choice_ordi(int *line)
{
  int	choice_line_ordi;

  choice_line_ordi = 0;
  while (42)
    {
      if (line[0] == 0 && line[1] == 0 && line[2] == 0 && line[3] > 0)
	choice_line_ordi = 4;
      else
	choice_line_ordi = (rand() % 4);
      if (choice_line_ordi > 0 && choice_line_ordi < 5 && line[choice_line_ordi - 1] != 0)
	return (choice_line_ordi - 1);
    }
}

void	player_two(int *line)
{
  int	choice_line_ordi;

  my_putchar('\n');
  my_putstr("AI's turn...\n");
  choice_line_ordi = line_choice_ordi(line);
  allum_choice_ordi(line, choice_line_ordi);
}
