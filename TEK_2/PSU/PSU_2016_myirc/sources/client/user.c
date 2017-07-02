/*
** user.c for funct_user in /home/raphael.dusautoy/rendus/myirc/client
** 
** Made by Raphael Dusautoy
** Login   <raphael.dusautoy@epitech.net>
** 
** Started on  Tue Jun  5 17:51:02 2017 Raphael Dusautoy
** Last update Sun Jun 11 23:26:14 2017 Raphaël Ghikh
*/

#include	"client.h"

int		connection_server(char **argv, t_client * client)
{
  if (argv && client)
    return (0);
  return (0);
}

int		msg_user(char **argv, t_client * client)
{
  char		*tmp;
  int		i;

  i = 2;
  if (argv[0] != 0 && argv[1] != NULL)
    {
      tmp = malloc(sizeof(char) * 512);
      strcpy(tmp, "PRIVMSG ");
      strcat(tmp, argv[1]);
      strcat(tmp, " ");
      while (argv[i] != NULL)
	{
	  strcat(tmp, argv[i]);
	  strcat(tmp, " ");
	  i++;
	}
      strcat(tmp, "\r\n");
      client->toServer = tmp;
    }
  else
    client->toClient = my_putstr("Incorect number of arguments");
  return (0);
}

int		change_nickname(char **argv, t_client *client)
{
  char		*tmp;

  if (argv[1] != NULL)
    {
      tmp = malloc(sizeof(char) * 512);
      strcpy(tmp, "NICK ");
      strcat(tmp, argv[1]);
      strcat(tmp, "\r\n");
      client->toServer = tmp;
    }
  else
    client->toClient = my_putstr("Incorect number of argument");
  return (0);
}

int		list_user(char **argv, t_client * client)
{
  char		*tmp;

  if (client->channel != NULL)
    {
      tmp = malloc(sizeof(char) * 512);
      strcpy(tmp, "NAMES ");
      strcat(tmp, client->channel);
      strcat(tmp, "\r\n");
      client->toServer = tmp;
    }
  else
    client->toClient = my_putstr("Incorect number of arguments");
  if (argv[1] != NULL)
    client->toClient = my_putstr("Incorect number of arguments");
  return (0);
}
