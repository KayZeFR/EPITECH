/*
** commands.c for irc in /home/kayzefr/EPITECH/TEK/PSU_2016_myirc/sources/server
** 
** Made by Raphaël Ghikh
** Login   <raphael.ghikh@epitech.eu>
** 
** Started on  Sun May 28 12:04:13 2017 Raphaël Ghikh
** Last update Sun Jun 11 16:26:31 2017 Raphaël Ghikh
*/

#include "server.h"

void	nick_cmd(void *command, t_user *my_user, t_server *server_irc)
{
  (void)server_irc;

  if (error_nick(command, my_user) == 1)
    return ;
  command++;
  server_irc->i = 3;
  boucle_nick(command, server_irc, my_user);
  if (error_too_nick(command, my_user) == 1)
    return ;
  if (my_user->name_user)
    free(my_user->name_user);
  my_user->name_user = strdup(command);
}

void	user_cmd(void *command, t_user *my_user, t_server *server_irc)
{
  memset(server_irc->copy, 0, 256);
  if (!my_user->name_user)
    return ;
  if ((sscanf(command, "%s %s %s %s", server_irc->copy, server_irc->host,
	      server_irc->service, server_irc->name)) != 4)
    {
      my_error(my_user->my_socket, ENOUGH_US);
      return ;
    }
  server_irc->count = 3;
  while (server_irc->count < 133)
    {
      if (connexion(server_irc->count, my_user, server_irc, server_irc->copy))
	return ;
      server_irc->count++;
    }
  printf("New connection : %s now connected\r\n", my_user->name_user);
  dprintf(my_user->my_socket,
	  "001: Welcome %s in our Server IRC!\r\n",
	  my_user->name_user);
}

void		list_cmd(void *command, t_user *my_user, t_server *server_irc)
{
  t_channel	*tmp;
  char		*niddle;

  if (!my_user->name_user)
    return ;
  niddle = NULL;
  if (strlen(command) > 1)
    {
      command++;
      niddle = strdup(command);
    }
  my_aff(my_user->my_socket, CHANNEL_US);
  tmp = server_irc->my_chans;
  while (tmp != NULL)
    {
      if ((niddle && strstr(tmp->channel_name, niddle)) || !niddle)
	my_aff_list_cmd(my_user->my_socket, my_user->nm_channel);
      tmp = tmp->suiv;
    }
  if (niddle)
    free(niddle);
  my_aff(my_user->my_socket, END_LIST);
}

void		join_cmd(void *params, t_user *my_user, t_server *server_irc)
{
  t_channel     *tmp;
  t_channel     *my_channel;

  if (error_join(params, my_user) == 1)
    return ;
  tmp = server_irc->my_chans;
  boucle_channel(tmp, params, my_user, server_irc);
  if (!(my_channel = malloc(sizeof(t_channel))))
    my_exit("Error on malloc()");
  my_channel->channel_name = strdup(params);
  my_channel->the_user = NULL;
  gest_tran(my_user, &my_channel->the_user);
  if (my_user->nm_channel)
    free(my_user->nm_channel);
  my_user->nm_channel = strdup(my_channel->channel_name);
  init_channel(my_channel, &server_irc->my_chans);
  names_cmd(params, my_user, server_irc);
}

void		part_cmd(void *command, t_user *my_user, t_server *server_irc)
{
  t_channel     *tmp;
  t_user        *my_s_user;

  error_part(my_user, command);
  command++;
  if (((char *)command)[0] != '&' && ((char *)command)[0] != '#')
    {
      my_error(my_user->my_socket, PART_FIND);
      return ;
    }

  tmp = server_irc->my_chans;
  while (tmp != '\0')
    {
      if (!strcmp(tmp->channel_name, command))
	{
	  my_s_user = tmp->the_user;
	  boucle_channel_repart(my_s_user, my_user, server_irc);
	  if (error_channel(my_s_user, my_user) == 1)
	    return ;
	}
      tmp = tmp->suiv;
    }
}
