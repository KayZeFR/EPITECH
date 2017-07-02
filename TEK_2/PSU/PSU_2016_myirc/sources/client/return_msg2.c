/*
** return_msg2.c for return_codes_bis in /home/raphael.dusautoy/rendus/myirc/client
** 
** Made by Raphael Dusautoy
** Login   <raphael.dusautoy@epitech.net>
** 
** Started on  Sat Jun  3 16:58:53 2017 Raphael Dusautoy
** Last update Sun Jun 11 23:29:42 2017 Raphaël Ghikh
*/

#include			"client.h"

static char			*getChannel(char *arg)
{
  int				i;
  char				*tmp;

  tmp = malloc(512);
  i = 0;
  while (arg[i] != 0 && arg[i] != '\n' && arg[i] != '\r')
    {
      tmp[i] = arg[i];
      i++;
    }
  tmp[i] = 0;
  return (tmp);
}

int				channel_changed(char **arg,
						t_client *client)
{
  char				command[1024];

  if (arg[1] != NULL)
    {
      if (arg[1][0] == ':')
	arg[1]++;
    if (client->channel != NULL)
	free(client->channel);
      client->channel = getChannel(arg[1]);
      sprintf(command, "You join %s", client->channel);
      client->toClient = xstrcat(client->toClient,
				 my_putstr(command));
      return (0);
    }
  return (1);
}

int				channel_clean(char **arg,
						t_client *client)
{
  char				command[1024];

  if (arg[1] != NULL)
    {
      if (arg[1][0] == ':')
	arg[1]++;
      sprintf(command, "You quit the channel : %s", arg[1]);
      client->toClient = xstrcat(client->toClient,
				 my_putstr(command));
      if (client->channel != NULL)
	free(client->channel);
      client->channel = NULL;
      return (0);
    }
  return (1);
}
