/*
** my_aff_msg.c for irc in /home/kayzefr/EPITECH/TEK/PSU_2016_myirc/sources/server
** 
** Made by Raphaël Ghikh
** Login   <raphael.ghikh@epitech.eu>
** 
** Started on  Mon May 29 08:14:56 2017 Raphaël Ghikh
** Last update Sun Jun 11 15:52:17 2017 Raphaël Ghikh
*/

#include "server.h"

void		my_aff_names_cmd(int my_socket, char *nm_channel)
{
  my_aff(my_socket, "353 ");
  my_aff(my_socket, nm_channel);
  my_aff(my_socket, ": [@");
}

void		my_aff_list_cmd(int my_socket, char *nm_channel)
{
  my_aff(my_socket, "322 ");
  my_aff(my_socket, nm_channel);
  my_aff(my_socket, "\r\n");
}

void		my_aff_msg_cmd(int my_socket, char *nm_user, char *text)
{
  my_aff(my_socket, nm_user);
  my_aff(my_socket, ": ");
  my_aff(my_socket, text);
  my_aff(my_socket, "\r\n");
}

void		my_aff_quit_cmd(int my_socket, char *nm_user, char *message)
{
  my_aff(my_socket, nm_user);
  my_aff(my_socket, " has quit (\"");
  my_aff(my_socket, message);
  my_aff(my_socket, "\")\r\n");
}
