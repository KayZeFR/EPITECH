/*
** infinadd.h for infinaddh in /home/ganem-_j/rendu/Piscine_C_infinadd
** 
** Made by johan ganem--brunet
** Login   <ganem-_j@epitech.net>
** 
** Started on  Mon Oct 19 15:07:32 2015 johan ganem--brunet
** Last update Mon Oct 19 19:16:51 2015 johan ganem--brunet
*/

#ifndef INFINADD_H_
# define INFINADD_H_

typedef struct s_number
{
  char		*str;
  unsigned int	lenght;
  unsigned int	idx;
}		t_number;

typedef struct s_operation
{
  t_number	n1;
  t_number	n2;
  t_number	result;
  t_number	tmp;
}		t_operation;

char	*inf_add(char *n1, char *n2);

#endif /* !INFINADD_H_ */
