#include <stdio.h>
#include <stdbool.h>

bool UF_connected (int p, int q)
{
	/* Check whether p and q are in thr same component */ 
	extern int *UF;
	extern int N;
	return (UF[p] == UF[q]);
}

void UF_union (int p, int q)
{
	/* Change all entries with id[p] to id[q] */
	extern int *UF;
	extern int N;
	int val = UF[p];
	int i = 0;
	for (i; i<N; i++) {
		if (UF[i] == val) UF[i] = UF[q];
	}
}

int UF_count() {
	/* Calculate the number of components */
	extern int *UF;
	extern int N;
	int count = 0;														// Record component numbers
	int i = 0;
	int j = 0;
	for (i; i<N; i++) {
		/* Idea:
		 * use i to represent cuurent point
		 * use j to represent point behind i
		 * if UF[i] == UF[i], i,j in the same component
     * Then do not record components number
		 * only when current node is the last node in the component then record
		 */
		bool Hex = false;												//record whether i has a succeed
		for (j=i+1; j<N; j++) {
			if (UF[j] == UF[i]) {									//UF[j] == UF[i], i has a succeed
				Hex = true;													//Hex = true
				break;															// Jump out the loop
			}
		}
		if (Hex == false) count++;							// Only when i do not have a hex,count++
	}
	return count;														
}	
