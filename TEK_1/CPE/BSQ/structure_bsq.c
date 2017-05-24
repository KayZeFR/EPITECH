/*
** structure_bsq.c for test in /home/ghikh_r/ghikh_r/rendu/C_Prog_Elem/CPE_2015_BSQ/test_bsq.c
**
** Made by Ghikh
** Login   <ghikh_r@epitech.net>
**
** Started on  Wed Dec 16 11:14:20 2015 Ghikh
** Last update Sun Dec 20 11:20:20 2015 Ghikh
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "structure.h"

void            my_putchar(char c)
{
  write(1, &c, 1);
}

int             main(int ac, char **av)
{
  char          c;
  int           fd;
  bsq_t         test;

  test.point = 0;
  test.rond = 0;
  test.line = 1;
  test.col = 0;
  test.ab = 0;
  test.ord = 0;
  fd =  open(av[1], O_RDWR);
  while ((read(fd, &c, 1) > 0))
    {
      my_putchar(c);
      if (c == '.')
	test.point = test.point + 1;
      if (c == 'o')
        test.rond = test.rond + 1;
      if (c == '\n' || c == '\0')
        {
          test.col = 0;
          test.line = test.line + 1;
	}
      if (c == '\n')
	test.col = test.col + 1;
      test.tab[test.ab][test.ord] = c;
      test.ab = test.ab + 1;
    }
  my_putchar('\n');
  close(fd);
  return (0);
}
