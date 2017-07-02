/*
** read_server.c for read_server in /home/raphael.dusautoy/rendus/myirc/client
** 
** Made by Raphael Dusautoy
** Login   <raphael.dusautoy@epitech.net>
** 
** Started on  Fri Jun  2 16:32:04 2017 Raphael Dusautoy
** Last update Sun Jun 11 23:52:15 2017 Raphaël Ghikh
*/

#include			"client.h"

void				read_server(int sfd,
					    t_client *client,
					    t_map *map)
{
  char			buffer[4096];
  int			ret;

  if ((ret = read(sfd, buffer, 4096)) == -1)
    fprintf(stderr, "Read failed\n");
  else
    {
      if (ret == 0)
	exit(EXIT_SUCCESS);
      buffer[ret - 2] = 0;
      if (display_info(buffer, client, map))
	client->toClient = my_putstr(client->toClient);
    }
}
