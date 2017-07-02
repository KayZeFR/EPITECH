/*
** server.h for irc in /home/kayzefr/EPITECH/TEK/PSU_2016_myirc
** 
** Made by Raphaël Ghikh
** Login   <raphael.ghikh@epitech.eu>
** 
** Started on  Sat May 27 10:10:50 2017 Raphaël Ghikh
** Last update Sun Jun 11 16:49:59 2017 Raphaël Ghikh
*/

#ifndef _SERVER_H_
# define _SERVER_H_

# include <sys/types.h>
# include <sys/socket.h>
# include <sys/types.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <stdlib.h>
# include <stdarg.h>
# include <errno.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdint.h>
# include <signal.h>
# include <curses.h>
# include <termios.h>

# define USER_NO	"441 USER : User is not in channel\r\n"
# define NICK_NO	"431 NICK : Give me a Nickname\r\n"
# define NICK_ERROR	"432 NICK : Error on nickname\r\n"
# define NICK_USE	"433 NICK : Nickname is already use, please change\r\n"
# define ENOUGH_US	"461 USER : Not enough parameters\r\n"
# define ENOUGH_JO	"461 JOIN : Not enough parameters\r\n"
# define ENOUGH_PA	"461 PART : Not enough parameters\r\n"
# define CHANNEL_US	"321 List Start : Channel : Users Name\r\n"
# define CHANNEL_FI	"403 JOIN : Not such channel\r\n"
# define PART_FIND	"403 PART : Not such channel\r\n"
# define END_LIST	"323 LIST : End of /LIST\r\n"
# define END_NAME	"366 NAMES : End of /NAMES list\r\n"
# define NAMES_EXI	"442 NAMES : You're not on that channel\r\n"
# define PART_EXI	"442 PART : You're not on that channel\r\n"
# define TEXT_VIDE	"412 TEXT : Write a message to send\r\n"
# define NOT_DEF	"421 COMMAND : Unknown command\r\n"
# define NICK_FIND	"401 NICK : Not such nickname\r\n"
# define USER_CO	"462 USER : It's not possible to register twice\r\n"
# define TOO_MUCH	"400 ERROR : Too much users connected, please wait\r\n"

typedef struct s_user		t_user;
typedef struct s_channel	t_channel;
typedef struct s_server		t_server;
typedef struct s_mysocket	t_mysocket;
typedef struct s_message	t_message;
typedef struct s_ring_buffer	t_ring_buffer;

typedef struct			s_ring_buffer
{
  char				rb[4096];
  char				*rrb;
  char				*wrb;
  int				available;
}				t_ring_buffer;

typedef struct			s_mysocket
{
  int				fd;
  int				busy;
  t_user			*go_user;
}				t_mysocket;

typedef struct			s_user
{
  char				user;
  char				*nm_channel;
  int				my_socket;
  char				*address_ip;
  char				*name_user;
  char				*real;
  t_user			*tmp;
  t_user			*backup;
  t_ring_buffer			*my_buffer;
  t_user			*suiv;
  t_user			**my_list;

  socklen_t			len;
  char				ip[INET6_ADDRSTRLEN];
  struct sockaddr_storage	r;
}				t_user;

typedef struct			s_channel
{
  char				*channel_name;
  t_user			*go_user;
  t_user			*the_user;
  t_channel			*suiv;
  t_channel			*tmp;
  t_channel			*backup;
}				t_channel;

typedef struct			s_server
{
  struct addrinfo		*switch_addr;
  struct addrinfo		*second_addr;
  struct addrinfo		first_addr;
  int				i;
  int				count;
  char				copy[256];
  char				host[256];
  char				service[256];
  char				name[256];
  char				*my_port_use;
  char				*my_cmd[11];
  int				my_socket;
  t_channel			*my_chans;
  t_channel			*go_chan;
  t_user			*go_user;
  t_user			*one_user;
  t_user			*my_user[133];
  fd_set			catch;
  fd_set			master;
  void				(*cmd_handler[11])(void *, t_user *, t_server *);
  int8_t			g_run;
  int				a;
  int				rbc;
}				t_server;

t_channel			*boucle(t_channel *, t_channel *);
void				delete_serv_partone(t_server *);
char				**my_str_to_wordtab(char *, char);
void				private_msg(char **, t_user *, t_server *);
void				aff_msg(char *, t_user *);
void				aff_welcome(t_user *);
int				connexion(int, t_user *, t_server *, char *);
int				gest_args(int);
void				channel_created(t_user *, t_server *, char *);
void				channel_repart(t_user *, t_server *, char *);
void				too_much_client(t_user *, t_server *);
void				new_connexion(t_mysocket *, t_server *);
void				delete_connexion(t_user *, t_server *);
void				run_args(char *, t_user *, t_server *);
int				pwd_gest(char *, char *);
void				see_in(t_user *, t_server *);
void				check_connexion(t_user *, t_server *);
void				check_serv(t_server *);
void				delete_serv(t_server *);
void				cmd_utils(t_server *);
void				set_handler(t_server *);
t_server			*init_server(char *);
void				init_channel(t_channel *, t_channel **);
void				supp_channel(t_channel *);
t_channel			*new_channel(t_channel *, t_channel *);
int				init_2_connexion(struct addrinfo *, int *);
int				init_1_connexion(char *, t_server *);
void				init_user(t_user *, t_user **);
void				supp_user(t_user *);
t_user				*new_user(t_user *, t_user*);
void				gest_tran(t_user *, t_user **);
void				nick_cmd(void *, t_user *, t_server *);
void				send_greetings(t_user *);
void				user_cmd(void *, t_user *, t_server *);
void				list_cmd(void *, t_user *, t_server *);
void				join_cmd(void *, t_user *, t_server *);
void				part_cmd(void *, t_user *, t_server *);
void				names_cmd(void *, t_user *, t_server *);
void				msg_cmd(void *, t_user *, t_server *);
void				sendfile_cmd(void *, t_user *, t_server *);
void				acceptfile_cmd(void *, t_user *, t_server *);
void				quit_cmd(void *, t_user *, t_server *);
void				def_cmd(void *, t_user *, t_server *);
int				my_getaddrinfo(const char *, const char *,
					       const struct addrinfo *, struct addrinfo **);
int				my_setsockopt(int, int, int, const void *, socklen_t);
int				my_socket(int, int, int);
int				my_bind(int, const struct sockaddr *, socklen_t);
int				my_listen(int, int);
int				my_accept(int, struct sockaddr *, socklen_t *);
void				my_freeaddrinfo(struct addrinfo *);
void				my_send(int, char *);
void				my_exit(char *);
void				my_error(int, char *);
void				my_aff(int, char *);
void				my_aff_list_cmd(int, char *);
void				my_aff_names_cmd(int, char *);
void				my_aff_msg_cmd(int, char *, char *);
void				my_aff_quit_cmd(int, char *, char *);
void				free_args(char **);
int				boucle_msg(int, char **, t_user *, t_server *);
void				boucle_nick(void *, t_server *, t_user *);
void				boucle_channel(t_channel *, char *, t_user *, t_server *);
void				boucle_channel_repart(t_user *, t_user *, t_server *);
void				boucle_quit(t_user *, t_user *, char *);
void				boucle_del_co(t_channel *, t_user *, t_user *, t_server *);
void				boucle_sup_channel(t_channel *);
void				boucle_free_channel(t_channel *);
void				boucle_checker(char *, t_user *, int);
void				boucle_del_serv(t_server *);
void				gest_see_in(char *, t_user *, t_server *);
int				error_names(t_user *);
int				error_nick(void *, t_user *);
int				error_too_nick(void *, t_user *);
int				error_join(void *, t_user *);
int				error_channel(t_user *, t_user *);
int				error_part(t_user *, void *);
int				error_delete(t_user *, t_user *, t_server *);
void				error(const char *);
void				*ipvx(struct sockaddr *);
char				buffer_in(t_ring_buffer *, int);
int				rb_available(t_ring_buffer *);

#endif /* !_SERVER_H_ */
