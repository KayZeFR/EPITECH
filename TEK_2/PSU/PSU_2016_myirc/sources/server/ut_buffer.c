/*
** ut_buffer.c for irc in /home/kayzefr/EPITECH/TEK/PSU_2016_myirc/sources/server
** 
** Made by Raphaël Ghikh
** Login   <raphael.ghikh@epitech.eu>
** 
** Started on  Fri Jun 02 10:06:35 2017 Raphaël Ghikh
** Last update Sun Jun 11 16:46:15 2017 Raphaël Ghikh
*/

#include "server.h"

char			buffer_in(t_ring_buffer *ring, int idx)
{
  if (idx >= 0)
    return ((ring->rb[(((size_t)ring->rrb + idx)
		      - (size_t)ring->rb) % 4096]));
  else
    return ((ring->rb[(((size_t)ring->wrb + idx)
		       - (size_t)ring->rb) % 4096]));
}

