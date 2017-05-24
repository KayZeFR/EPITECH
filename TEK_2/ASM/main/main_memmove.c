#include <stdio.h>
#include <string.h>

int main(){
  char a[]="hare rama hare rama";

  char b[]="hare rama hare rama";

  memmove(a+5,a,20);
  puts(a);
}
