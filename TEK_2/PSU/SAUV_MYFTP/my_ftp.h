/*
** server.h for server in /home/vezia_l/rendu/PSU_2015_myftp
**
** Made by louis vezia
** Login   <vezia_l@epitech.net>
**
** Started on  Tue May 10 14:51:45 2016 louis vezia
** Last update	Sun May 15 22:18:56 2016 Louis Vezia
*/

#ifndef _MY_FTP_H_
# define _MY_FTP_H_

# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netdb.h>
# include <stdlib.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <sys/stat.h>

# define NB_MAX_CLIENT	42

typedef struct		s_server
{
  struct protoent	*my_protoent; //pe
  int			my_file_descriptor; //fd
  int			port;
  socklen_t		sock_size; //s_in_size
  struct sockaddr_in	sock_client; //s_in_client
  int			my_fd_client; //client_fd
  char			*address_ip; //*client_ip;
  int			user;
  int			password;
  int			login;
  int			my_cmd_exit; //exit_c;
  char			*my_buffer;
  char			**my_board;
  int			nb_client;
  int			my_client_fd; //fd_client;
  char			my_path[1024]; //pwd
  char			my_root[1024]; //rootdir
}			t_server;

int			init_socket(t_server *);
int			run_ftp(t_server *);
int			run_client(t_server *);
int			fct_cmd(t_server*);
char			*my_get_next_line(int);
char			**my_str_to_word_tab(char *);
int			send_msg(int, char *);

int			my_socket(int, int, int);
int			my_bind(int, const struct sockaddr *, socklen_t);
int			my_listen(int, int);
int			my_accept(int, struct sockaddr *, socklen_t *);
int			my_connect(int, struct sockaddr *, socklen_t);
void			my_exit(char *);
void			my_error(int, char *);
void			gest_error(int);
int			gest_error_dir(char *);

int			user_cmd(t_server *);
int			passw_cmd(t_server *);
int			quit_cmd(t_server *);
int			dele_cmd(t_server *);
int			pwd_cmd(t_server *);
int			help_cmd(t_server *);
int			noop_cmd(t_server *);
int			cwd_cmd(t_server *);
int			cdup_cmd(t_server *);
int			pasv_cmd(t_server *);
int			port_cmd(t_server *);
int			retr_cmd(t_server *);
int			stor_cmd(t_server *);
int			list_cmd(t_server *);


#endif /* !MY_FTP_H_ */
