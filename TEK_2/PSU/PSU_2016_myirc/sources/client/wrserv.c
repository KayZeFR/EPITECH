/*
** write_server.c for wrserv in /home/raphael.dusautoy/rendus/SystemeUnix/myirc/src_client
** 
** Made by Raphael Dusautoy
** Login   <raphael.dusautoy@epitech.net>
** 
** Started on  Sun Jun 11 22:43:12 2017 Raphael Dusautoy
** Last update Sun Jun 11 23:05:00 2017 Raphael Dusautoy
*/

#include			"client.h"

void				write_server(int sfd,
					     t_client *client)
{
  int				ret;

  if (client->toServer != NULL)
    {
      ret = write(sfd, client->toServer, strlen(client->toServer));
      if (ret == -1)
	fprintf(stderr, "Failed to write");
      free(client->toServer);
      client->toServer = NULL;
    }
}
