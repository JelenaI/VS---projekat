#include <stdio.h>
#include <math.h>
#include <klee/klee.h>
#include <stdio.h>
#include <stdlib.h>

// program racuna |x-3|-|2x -1| -6 

int solve(int x){
	
	if( x> 3)
		if(2*x-1 > 0)
			return  -x -8;
 		else
 		  return 3*x -10;
	else
		if( 2*x -1>0)
			return  -3*x -2;
		else 
			return x-4;	
			
	return x;				
}

int main(int argc, char** argv){
	int x;

	//printf("Enter parameter: ");
	//scanf("%d", &x);
	klee_make_symbolic(&x,sizeof(int),"x");

	
	if(solve(x) == 0)
		klee_assert(0);
}
