#include <stdio.h>
#include <assert.h>

extern int *numbers;
extern int N;

int sum3()
{
	int count = 0;
	int i = 0;
	int j, k;
	/* test all the conditions */
	for(i; i<N; i++) {
		for (j=i+1; j<N; j++) {
			for (k=j+1; k<N; k++) {
				if(numbers[i] + numbers[j] + numbers[k] == 0) {
					printf("%d %d %d\n", numbers[i], numbers[j], numbers[k]);
					count++;
				}
			}
		}
	}
	return count;
}
	
