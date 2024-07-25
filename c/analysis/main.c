#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int *numbers;
int N;
int sum3 ();

int main(int argc, char *argv[])
{
	assert(argc >= 2);
	FILE *fd1;
	int result = 0;
	char s_numbers[10];
	fd1 = fopen(argv[1], "r");
	fgets(s_numbers, 10, 	fd1);
	N = atoi(s_numbers);
	numbers = (int *)calloc(N, sizeof(int));
	for (int i=0; i<N; i++) {
		fgets(s_numbers, 10, fd1);
		numbers[i] = atoi(s_numbers);
	}

	result = sum3();
	printf("the number is %d\n", result);
	
	return 0;
}	
