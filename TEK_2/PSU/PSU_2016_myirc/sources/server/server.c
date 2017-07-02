/*
** server.c for irc in /home/kayzefr/EPITECH/TEK/PSU_2016_myirc/sources/server
** 
** Made by Raphaël Ghikh
** Login   <raphael.ghikh@epitech.eu>
** 
** Started on  Sat May 27 11:17:47 2017 Raphaël Ghikh
** Last update Sun Jun 11 15:41:10 2017 Raphaël Ghikh
*/

#include "server.h"

void			delete_serv(t_server *server_irc)
{
  if (server_irc != '\0')
    {
      if (server_irc->my_port_use != '\0')
	free(server_irc->my_port_use);
      if (server_irc->my_socket != '\0')
	close(server_irc->my_socket);
      if (server_irc->my_chans != '\0')
	{
	  server_irc->go_chan->tmp = server_irc->my_chans;
	  while (server_irc->go_chan->tmp)
	    {
	      server_irc->go_chan->backup = server_irc->go_chan->tmp->suiv;
	      supp_channel(server_irc->go_chan->tmp);
	      server_irc->go_chan->tmp = server_irc->go_chan->backup;
	    }
	}
      boucle_del_serv(server_irc);
      free(server_irc);
    }
}

void			cmd_utils(t_server *server_irc)
{
  server_irc->cmd_handler[0] = &nick_cmd;
  server_irc->cmd_handler[1] = &user_cmd;
  server_irc->cmd_handler[2] = &list_cmd;
  server_irc->cmd_handler[3] = &join_cmd;
  server_irc->cmd_handler[4] = &part_cmd;
  server_irc->cmd_handler[5] = &names_cmd;
  server_irc->cmd_handler[6] = &msg_cmd;
  server_irc->cmd_handler[7] = &sendfile_cmd;
  server_irc->cmd_handler[8] = &acceptfile_cmd;
  server_irc->cmd_handler[9] = &quit_cmd;
  server_irc->cmd_handler[10] = NULL;
}

void			set_handler(t_server *server_irc)
{
  server_irc->my_cmd[0] = "NICK";
  server_irc->my_cmd[1] = "USER";
  server_irc->my_cmd[2] = "LIST";
  server_irc->my_cmd[3] = "JOIN";
  server_irc->my_cmd[4] = "PART";
  server_irc->my_cmd[5] = "NAMES";
  server_irc->my_cmd[6] = "PRIVMSG";
  server_irc->my_cmd[7] = "SENDFILE";
  server_irc->my_cmd[8] = "ACCEPTFILE";
  server_irc->my_cmd[9] = "QUIT";
  server_irc->my_cmd[10] = NULL;
  cmd_utils(server_irc);
}
