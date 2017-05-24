#include <stdio.h>
#include <string.h>

int main()
{
    char str1[]="Humble Bundle is awesome.";
    char str2[26];
    char str3[10];

    void* r1 = memcpy(str2, str1, 5);
    printf("str2 is %s, r1 is %p\n", str2, r1);
    void* r2 = memcpy(str2, str1, 26);
    printf("str2 is %s, r2 is %p\n", str2, r2);
    return 0;
}