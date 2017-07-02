/*
** gest_errors_cmd.c for irc in /home/kayzefr/EPITECH/TEK/PSU_2016_myirc/sources/server
** 
** Made by Raphaël Ghikh
** Login   <raphael.ghikh@epitech.eu>
** 
** Started on  Wed May 31 14:09:01 2017 Raphaël Ghikh
** Last update Sun Jun 11 16:00:12 2017 Raphaël Ghikh
*/

#include "server.h"

int		error_names(t_user *my_user)
{
  if (!my_user->name_user)
    return (1);
  if (!my_user->nm_channel)
    {
      my_error(my_user->my_socket, NAMES_EXI);
      return (1);
    }
  return (0);
}

int		error_nick(void *command, t_user *my_user)
{
  if (!strlen(command))
    {
      my_error(my_user->my_socket, NICK_NO);
      return (1);
    }
  return (0);
}

int		error_too_nick(void *command, t_user *my_user)
{
  if (strlen(command) > 9)
    {
      my_error(my_user->my_socket, NICK_ERROR);
      return (1);
    }
  return (0);
}

int		error_join(void *params, t_user *my_user)
{
  if (!my_user->name_user)
    return (1);
  if (!strlen(params))
    {
      my_error(my_user->my_socket, ENOUGH_JO);
      return (1);
    }
  params++;
  if (((char *)params)[0] != '&' && ((char *)params)[0] != '#')
    {
      my_error(my_user->my_socket, CHANNEL_FI);
      return (1);
    }
  return (0);
}

int		error_channel(t_user *my_s_user, t_user *my_user)
{
  if (!my_s_user)
    {
      my_error(my_user->my_socket, PART_EXI);
      return (1);
    }
  return (0);
}
