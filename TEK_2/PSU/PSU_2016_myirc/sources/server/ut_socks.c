/*
** ut_socks.c for irc in /home/kayzefr/EPITECH/TEK/PSU_2016_myirc/sources/server
** 
** Made by Raphaël Ghikh
** Login   <raphael.ghikh@epitech.eu>
** 
** Started on  Sat May 27 21:08:55 2017 Raphaël Ghikh
** Last update Sun Jun 11 16:09:25 2017 Raphaël Ghikh
*/

#include "server.h"

void		*ipvx(struct sockaddr *s)
{
  if (s->sa_family == AF_INET)
    return &(((struct sockaddr_in*)s)->sin_addr);
  return &(((struct sockaddr_in6*)s)->sin6_addr);
}
