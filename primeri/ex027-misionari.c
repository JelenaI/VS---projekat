
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <klee/klee.h>

#define MISSIONARS 0
#define CANIBALS 1
#define CAPACITY 2
#define MAX 40

int solved(int shore_right[])
{
	return shore_right[MISSIONARS] == 3 && shore_right[CANIBALS] == 3;
}


void run(int shore_left[], int shore_right[], char boat[], int steps)
{
	printf("TURN    LEFT|~~~~~~~~~~~~~~~~~~~~| RIGHT\n");
	printf("      %d M   %d C|~~~~~~~~~~~~~~~~~~~~| %d M %d C\n",
			       shore_left[MISSIONARS],
			       shore_left[CANIBALS], shore_right[MISSIONARS],
			       shore_right[CANIBALS]);
			
	int mboat = 0 , cboat =1;
	int turns =0;
	while(turns< steps){
		if (turns % 2 == 0) {   // left to right
			if( boat[mboat] > shore_left[MISSIONARS]  || boat[cboat] > shore_left[CANIBALS]){
					fprintf(stderr,"Invalid number of passengers! \n");
					exit(EXIT_FAILURE);
				}
			
			shore_left[MISSIONARS] -= boat[mboat];
			shore_right[MISSIONARS] += boat[mboat];
			shore_left[CANIBALS] -= boat[cboat];
			shore_right[CANIBALS] += boat[cboat];
			printf("%4d  %d M   %d C|    >- %d M %d C -->  | %d M %d C\n",
						 turns+1,
			       shore_left[MISSIONARS],
			       shore_left[CANIBALS], boat[mboat],
			       boat[cboat], shore_right[MISSIONARS],
			       shore_right[CANIBALS]);
			       } 
		 else {
			if( boat[mboat] > shore_right[MISSIONARS]  || boat[cboat] > shore_right[CANIBALS]){
					fprintf(stderr,"Invalid number of passengers!\n");
					exit(EXIT_FAILURE);
				}
			
			
			shore_left[MISSIONARS] += boat[mboat];
			shore_right[MISSIONARS] -= boat[mboat];
			shore_left[CANIBALS] += boat[cboat];
			shore_right[CANIBALS] -= boat[cboat];

			printf("%4d  %d M   %d C|  <-- %d M %d C -<    | %d M %d C\n",
			       turns+1,
			       shore_left[MISSIONARS],
			       shore_left[CANIBALS], boat[mboat],
			       boat[cboat], shore_right[MISSIONARS],
			       shore_right[CANIBALS]);
				 }
				 
				 
		if((shore_left[CANIBALS] > shore_left[MISSIONARS] && shore_left[MISSIONARS] >0 )
			|| (shore_right[CANIBALS] > shore_right[MISSIONARS]  && shore_right[MISSIONARS] >0)){
				fprintf(stderr,"To much canibals!\n");
				exit(EXIT_FAILURE);
		}

		if(solved(shore_right)){
			printf("Solved!\n\n");
			klee_assert(0);
			}
		turns++;
		mboat+=2;	
		cboat+=2;
	}
}


int main()
{

	int shore_left[2], shore_right[2];
	shore_left[MISSIONARS] = 3;
	shore_left[CANIBALS] = 3;
	shore_right[MISSIONARS] = 0;
	shore_right[CANIBALS] = 0;

	char boat[MAX];		// boat[2i] nad boat[2i+1] are pairs (m,c) of people transported in i-th turn

// Make the input symbolic.
	klee_make_symbolic(boat, sizeof(char)*MAX, "boat");

	int turns = 0;

	while (turns < MAX / 2 ) {
		int mboat = turns * 2, cboat = turns * 2 + 1;
		klee_assume(boat[mboat] >= 0);
		klee_assume(boat[cboat] >= 0);
		klee_assume(boat[mboat] + boat[cboat] <= CAPACITY);
		klee_assume(boat[mboat] + boat[cboat] > 0);
		turns++;
	}
	printf("TURNS: %d\n", turns);
	
	run(shore_left, shore_right, boat, turns);	// main function

	return 0;
}
