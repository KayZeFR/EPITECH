/*
** commands2.c for irc in /home/kayzefr/EPITECH/TEK/PSU_2016_myirc/sources/server
** 
** Made by Raphaël Ghikh
** Login   <raphael.ghikh@epitech.eu>
** 
** Started on  Sun May 28 15:01:16 2017 Raphaël Ghikh
** Last update Sun Jun 11 16:14:32 2017 Raphaël Ghikh
*/

#include "server.h"

void		names_cmd(void *command, t_user *my_user, t_server *server_irc)
{
  t_user	*tmp;

  (void)command;
  (void)server_irc;
  if (error_names(my_user) == 1)
    return ;
  my_aff_names_cmd(my_user->my_socket, my_user->nm_channel);
  tmp = *my_user->my_list;
  while (tmp != NULL)
    {
      my_aff(my_user->my_socket, tmp->name_user);
      if (tmp->suiv)
	my_aff(my_user->my_socket, " ");
      tmp = tmp->suiv;
    }
  my_aff(my_user->my_socket, "]\r\n");
  my_error(my_user->my_socket, END_NAME);
}

void	msg_cmd(void *command, t_user *my_user, t_server *server_irc)
{
  char	**args;
  int	i;

  i = 3;
  if (!strlen(command) || !++command ||
      !(args = my_str_to_wordtab(command, ' ')))
    {
      my_error(my_user->my_socket, ENOUGH_PA);
      return ;
    }
  if (!args[1])
    {
      my_error(my_user->my_socket, TEXT_VIDE);
      return ;
    }
  i = boucle_msg(i, args, my_user, server_irc);
  if (i == 133)
    my_error(my_user->my_socket, NICK_FIND);
  free_args(args);
}

void	sendfile_cmd(void *command, t_user *my_user, t_server *server_irc)
{
  (void)command;
  (void)my_user;
  (void)server_irc;
  return ;
}

void	acceptfile_cmd(void *command, t_user *my_user, t_server *server_irc)
{
  (void)command;
  (void)my_user;
  (void)server_irc;
  return ;
}

void		quit_cmd(void *command, t_user *my_user, t_server *server_irc)
{
  char		*msg;
  t_user	*my_s_user;

  msg = NULL;
  if (strlen(command) > 1)
    msg = strdup(command + 2);
  if (msg && my_user->nm_channel && my_user->my_list)
    {
      my_s_user = *my_user->my_list;
      boucle_quit(my_s_user, my_user, msg);
    }
  FD_CLR(my_user->my_socket, &server_irc->master);
  delete_connexion(my_user, server_irc);
  if (msg)
    free(msg);
}
