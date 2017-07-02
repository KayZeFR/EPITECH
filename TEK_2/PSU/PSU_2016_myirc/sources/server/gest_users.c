/*
** gest_users.c for irc in /home/kayzefr/EPITECH/TEK/PSU_2016_myirc/sources/server
** 
** Made by Raphaël Ghikh
** Login   <raphael.ghikh@epitech.eu>
** 
** Started on  Thu Jun 01 10:06:52 2017 Raphaël Ghikh
** Last update Sun Jun 11 16:13:48 2017 Raphaël Ghikh
*/

#include "server.h"

void	private_msg(char **args, t_user *my_user, t_server *server_irc)
{
  int	i;

  i = 3;
  i = boucle_msg(i, args, my_user, server_irc);
  if (i == 133)
    my_error(my_user->my_socket, NICK_FIND);
  free_args(args);
}

int	boucle_msg(int i, char **args, t_user *my_user,
		   t_server *server_irc)
{
  int	x;

  while (i < 133)
    {
      if (server_irc->my_user[i] && server_irc->my_user[i]->name_user
	  && !strcmp(server_irc->my_user[i]->name_user, args[0]))
	{
	  my_aff(server_irc->my_user[i]->my_socket, my_user->name_user);
	  my_aff(server_irc->my_user[i]->my_socket, ": ");
	  x = 1;
	  while (args[x] != '\0')
	    {
	      my_aff(server_irc->my_user[i]->my_socket, args[x]);
	      if (args[x + 1])
		my_aff(server_irc->my_user[i]->my_socket, " ");
	      x++;
	    }
	  my_aff(server_irc->my_user[i]->my_socket, "\r\n");
	  break ;
	}
      i++;
    }
  return (i);
}

void	free_args(char **args)
{
  int		i;

  i = 0;
  while (args[i] != '\0')
    {
      free(args[i]);
      i++;
    }
  free(args);
}

void		aff_msg(char *params, t_user *my_user)
{
  t_user	*my_s_user;

  if (((char *)params)[0] == '/')
    my_error(my_user->my_socket, NOT_DEF);
  else
    {
      my_s_user = *my_user->my_list;
      while (my_s_user != '\0')
	{
	  if (my_s_user == my_user)
	    continue ;
	  my_aff_msg_cmd(my_s_user->my_socket, my_s_user->name_user,
		     ((char *)params));
	  my_s_user = my_s_user->suiv;
	}
    }
}
