/*
** write_c.c for write_client in /home/raphael.dusautoy/rendus/myirc/client
** 
** Made by Raphael Dusautoy
** Login   <raphael.dusautoy@epitech.net>
** 
** Started on  Sun Jun  4 12:24:48 2017 Raphael Dusautoy
** Last update Sun Jun 11 22:08:34 2017 Raphael Dusautoy
*/

#include			"client.h"

void				write_client(t_client *client)
{
  if (client->toClient != NULL)
    {
      write(1, client->toClient, strlen(client->toClient));
      free(client->toClient);
      client->toClient = NULL;
    }
}
