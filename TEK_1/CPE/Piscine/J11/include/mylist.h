/*
** mylist.h for mylist in /home/ghikh_r/rendu/Piscine_C_J11
** 
** Made by raphael ghikh
** Login   <ghikh_r@epitech.net>
** 
** Started on  Tue Oct 13 13:55:46 2015 raphael ghikh
** Last update Tue Oct 13 14:43:08 2015 raphael ghikh
*/

#ifndef MYLIST_H_
# define MYLIST_H_

struct	t_list
{
  void		*data;
  struct t_list *next;
}

typedef struct s_list
{
  void		*data;
  struct s_list *next;
} t_list;

#endif /* !MYLIST_H_ */
