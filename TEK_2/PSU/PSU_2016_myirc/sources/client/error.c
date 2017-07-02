/*
** error.c for error in /home/raphael.dusautoy/rendus/myirc/client
** 
** Made by Raphael Dusautoy
** Login   <raphael.dusautoy@epitech.net>
** 
** Started on  Sun Jun  4 11:09:48 2017 Raphael Dusautoy
** Last update Fri Jun  9 07:51:00 2017 Raphael Dusautoy
*/

#include				"client.h"

void					my_error(char *x, int opt)
{
  printf("Error Client : %s", x);
  if (opt)
    printf(" : %s", strerror(errno));
  printf("\n");
  exit(1);
}
