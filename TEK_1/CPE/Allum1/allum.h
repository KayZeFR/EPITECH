/*
** allum.h for allum1 in /home/ghikh_r/CPE_2015_Allum1
** 
** Made by Raphael Ghikh
** Login   <ghikh_r@epitech.net>
** 
** Started on  Wed Feb 24 18:28:58 2016 Raphael Ghikh
** Last update Fri Feb 26 15:00:13 2016 Raphael Ghikh
*/

#ifndef ALLUM_H_
# define ALLUM_H_

void	my_putchar(char c);
void	my_putstr(char *str);
int	my_getnbr(char *str);
void	my_putnbr(int nb);
char	*get_next_line(const int fd);
int	count_allum(int *line);
void	print_plateau(int nbr_match, int space_before);
void	print_match(int *line);
void	error(int *line, int choice_allum, int choice_line);
int	allum_choice(int *line, int choice_line);
int	line_choice(int *line);
int	player_one(int *line);
int	allum_choice_ordi(int *line, int choice_line_ordi);
int	line_choice_ordi(int *line);
void	player_two(int *line);

#endif /* !ALLUM_H_ */
