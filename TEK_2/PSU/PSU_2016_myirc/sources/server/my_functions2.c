/*
** my_functions2.c for irc in /home/kayzefr/EPITECH/TEK/PSU_2016_myirc/sources/server
** 
** Made by Raphaël Ghikh
** Login   <raphael.ghikh@epitech.eu>
** 
** Started on  Mon May 29 10:33:44 2017 Raphaël Ghikh
** Last update Sun Jun 11 15:54:08 2017 Raphaël Ghikh
*/

#include "server.h"

void		my_aff(int my_sock, char *str)
{
  write(my_sock, str, strlen(str));
}

void		my_error(int my_sock, char *str)
{
  write(my_sock, str, strlen(str));
}

