/*
** init_buffer.c for irc in /home/kayzefr/EPITECH/TEK/PSU_2016_myirc/sources/server
** 
** Made by Raphaël Ghikh
** Login   <raphael.ghikh@epitech.eu>
** 
** Started on  Mon May 29 14:54:17 2017 Raphaël Ghikh
** Last update Sun Jun 11 16:46:30 2017 Raphaël Ghikh
*/

#include "server.h"

int			rb_available(t_ring_buffer *ring)
{
  if (ring->wrb >= ring->rrb)
    return (4096 - (int)(ring->wrb - ring->rrb));
  else
    return (int)(ring->rrb - ring->wrb);
}
