
#include <stdio.h>
#include <klee/klee.h>

int power(int x, int n){
	int i;
	for(i=2; i<=n ; i++)
		x*=x;
	
	return x;
}

int main()
{
    int number, originalNumber, remainder, result = 0, n = 0 ;

    //printf("Enter an integer: ");
    //scanf("%d", &number);
		klee_make_symbolic(&number,sizeof(number),"number");
    klee_assume(number > 0); 
     
     originalNumber = number;
    
    while (originalNumber != 0)
    {
        originalNumber /= 10;
        ++n;
    }

    originalNumber = number;

    while (originalNumber != 0)
    {
        remainder = originalNumber%10;
        result += power(remainder, n);
        originalNumber /= 10;
    }

    if(result == number)
        printf("%d is an Armstrong number.\n", number);
    else
        printf("%d is not an Armstrong number.\n", number);

    return 0;
}
