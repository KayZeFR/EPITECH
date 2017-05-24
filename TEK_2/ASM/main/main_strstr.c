#include <stdio.h>
#include <string.h>

int main()
{
  char str1[] = "Apprendre C/C++ c'est facile.";
  char str2[] = "Tout";

  /* Recherche la copie exacte de str2 dans str1 */
  if(strstr(str1, str2) == NULL)
    printf("%s introuvable.n",str2);
  else
    printf("%s trouvé dans la chaîne: %sn",str2, str1);

  return 0;
}
