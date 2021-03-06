/*
** return_codes.c for return_codes in /home/raphael.dusautoy/rendus/myirc/client
** 
** Made by Raphael Dusautoy
** Login   <raphael.dusautoy@epitech.net>
** 
** Started on  Sat Jun  3 11:35:41 2017 Raphael Dusautoy
** Last update Sun Jun 11 23:29:07 2017 Raphaël Ghikh
*/

#include			"client.h"

int				nickname_changed(char **arg,
						 t_client *client)
{
  char				command[1024];

  if (arg[1] != NULL)
    {
      if (arg[1][0] == ':')
	arg[1]++;
      sprintf(command, "Nickname changed into %s", arg[1]);
      client->toClient = xstrcat(client->toClient,
				 my_putstr(command));
      if (client->nickname != NULL)
	free(client->nickname);
      client->nickname = strdup(arg[1]);
      return (0);
    }
  return (1);
}

int				server_connected(char **arg,
						 t_client *client)
{
  client->toClient  = xstrcat(client->toClient,
			      my_putstr("Connexion success"));
  if (client && arg)
    client->nickname = NULL;
  client->channel = NULL;
  return (0);
}

t_map				*init_return_code()
{
  t_map				*map;

  map = NULL;
  map = add_element2(map, "NICK", nickname_changed);
  map = add_element2(map, "001", server_connected);
  map = add_element2(map, "JOIN", channel_changed);
  map = add_element2(map, "PART", channel_clean);
  return (map);
}
