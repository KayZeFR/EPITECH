#include <stdio.h>
#include <string.h>
/*
void main(int ac, char **av)
{
  char	*val;
  val = rindex(av[1], 2);
  printf("%p", val); 
  }*/

void main(){
  char *s = "0123456789012345678901234567890";
  char *p;
  p = rindex(s, '5');
  printf("%s\n", p);
}
