#include <stdio.h>
#include <string.h>

int main ()
{
  char chaine3[] = "Bonjour";
  char chaine4[] = "ooooooo";
  
  int ret;

  ret = strcmp(chaine3, chaine4);
  printf("%d", ret);
  if (ret < 0)
    {
      printf("str1 inférieur à str2");
    }
  else if (ret > 0)
    {
        printf("str1 supérieur à str2");
    }
  else
    {
      printf("str1 égal à str2");
    }
    return(0);
}
