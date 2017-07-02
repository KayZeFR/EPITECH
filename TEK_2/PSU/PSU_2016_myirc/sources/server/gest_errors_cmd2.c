/*
** gest_errors_cmd2.c for irc in /home/kayzefr/EPITECH/TEK/PSU_2016_myirc/sources/server
** 
** Made by Raphaël Ghikh
** Login   <raphael.ghikh@epitech.eu>
** 
** Started on  Wed May 31 14:59:19 2017 Raphaël Ghikh
** Last update Sun Jun 11 16:00:38 2017 Raphaël Ghikh
*/

#include "server.h"

int		error_part(t_user *my_user, void *command)
{
  if (!my_user->name_user)
    return (1);
  if (!strlen(command))
    {
      my_error(my_user->my_socket, ENOUGH_PA);
      return (1);
    }
  return (0);
}

int		error_delete(t_user *my_s_user, t_user *my_user, t_server *server_irc)
{
  if (my_s_user == my_user)
    {
      server_irc->my_user[my_user->my_socket] = NULL;
      server_irc->one_user = new_user(my_user, server_irc->one_user);
      return (1);
    }
  return (0);
}
