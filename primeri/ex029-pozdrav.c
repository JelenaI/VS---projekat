#include <stdio.h>
#include <klee/klee.h>

int main(int argc, char **argv)
{
  char s[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ!?";
  int i,k;
  char *p , *n;
  char result[100];
	
  klee_make_symbolic(&i, sizeof(int), "i");
  klee_make_symbolic(&k, sizeof(int), "k");
  
  p=s;
  n = result;
  while(*p!='\0'){
		*n++ = *(p+k) ;
		*n++ = *(p-k) ;
		
		p +=i;
		}
  
    return *p;
}

