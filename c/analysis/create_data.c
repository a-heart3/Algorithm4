#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main (int argc, char *argv[])
{
	FILE *fd1;
	int N;
	int j;
	int number;
	int *repeat;
	char s_number[10];
	fd1 = fopen("./test.txt", "w");										// use write type to open a file
	printf("Please input the size of array:");
	scanf("%d", &N);																	// input the number of N
	sprintf(s_number, "%d", N);
	fputs(s_number, fd1);															// write to fd1
	fputc('\n', fd1);																	// append \n
	repeat = (int *)calloc(N, sizeof(int));						// repeat use to judge whether generate
	for(int i = 0; i<N; i++) {
		repeat[i] = 0;
	}
	printf("Initial is OK\n");
	srand ((unsigned) time(NULL));										// seed of rand number
	j = N;
	while(true){
		number = rand() % N;
		if (repeat[number]==1) continue;								// IF has generated, then jump to next loop
		repeat[number] = 1;															// repeat[number]=1, represent has generated number
		j--;																						// need to generate j-- numbers
		number -=  N / 2;
		sprintf(s_number, "%d\n", number);							// trans number to string
		fputs(s_number,fd1);														// write to file
		if(j==0) break;
	}
			
	fclose(fd1);

	return 0;
}
