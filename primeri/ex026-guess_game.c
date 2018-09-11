#include <klee/klee.h>
#include <assert.h>

unsigned calculate_score(unsigned age){
	
	age += 94;

  if(age <100)
		goto l1;
	else  
		goto l2;

	l1:		return age/10 + age%10;
	l2:   return age/100 + age%100;	
}


int main(){
	unsigned age; 
	klee_make_symbolic(&age,sizeof(unsigned),"age");
	klee_assume(age>0 && age <200);


	if( calculate_score(age) == 14)
		klee_assert(0);
}
