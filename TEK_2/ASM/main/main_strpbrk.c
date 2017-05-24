/*
 * =====================================================================================
 *
 *       Filename:  strpbrk.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2016年11月28日 21时11分59秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  strpbrk
 *  Description:  
 * =====================================================================================
 */
char *
strpbrk (char * src,char * dest)
{
  char * srcCh=src;
  char * destCh=dest;
  if(src==NULL||dest==NULL)
    return NULL;
  while(*srcCh!='\0')
    {
      while(*destCh!=*srcCh&&*destCh!='\0')
	{
	  destCh++;
	}
      if(*destCh==*srcCh)
	return destCh;
      srcCh++;
      destCh=dest;
    }
  return NULL;
}/* -----  end of function strpbrk  ----- */
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int
main ( int argc, char *argv[] )
{
  char src[4]="rec";
  src[3]='0';
  printf("a=%c\n",src[3]);
  char dest[5]="dest";
  char * str=strpbrk(src,dest);
  printf("str=%s\n",str);
  return EXIT_SUCCESS;
} /* ----------  end of function main  ---------- */
