/*
** cutBuff.c for cutbuff in /home/raphael.dusautoy/rendus/myirc/client
** 
** Made by Raphael Dusautoy
** Login   <raphael.dusautoy@epitech.net>
** 
** Started on  Sat Jun  3 18:49:30 2017 Raphael Dusautoy
** Last update Fri Jun  9 07:50:10 2017 Raphael Dusautoy
*/

#include			"client.h"

void				cutbuff(char *buff, unsigned int size)
{
  if (strlen(buff) > size)
    buff[size - 1] = 0;
}
