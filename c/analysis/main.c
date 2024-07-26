#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

int *numbers;
int N;
int sum3 ();

int main(int argc, char *argv[])
{
	assert(argc >= 2);																								//judge whether has an argument
	FILE *fd1;
	int result = 0;
	char s_numbers[10];																								// store data read from file
	time_t start, end;

	fd1 = fopen(argv[1], "r");																			  // open referenced file
	fgets(s_numbers, 10, 	fd1);																				// get total numbers
	N = atoi(s_numbers);
	numbers = (int *)calloc(N, sizeof(int));													// Create dynamic array
	for (int i=0; i<N; i++) {
		fgets(s_numbers, 10, fd1);
		numbers[i] = atoi(s_numbers);																		// Trans data read from file to integer
	}

	start = time(NULL);																								// sum3() begin time
	result = sum3();
	end = time(NULL);																								  // sum3() end time
	printf("Run time = %fs\n", difftime(end, start));
	printf("the number is %d\n", result);
	
	return 0;
}	
