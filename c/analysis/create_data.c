#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char *argv[])
{
	FILE *fd1;
	int N;
	int number;
	char s_number[10];
	fd1 = fopen("./test.txt", "w");										//use write type to open a file
	printf("Please input the size of array:");
	scanf("%d", &N);																	// input the number of N
	sprintf(s_number, "%d", N);
	fputs(s_number, fd1);															// write to fd1
	fputc('\n', fd1);																	// append \n
	srand ((unsigned) time(NULL));										// seed of rand number
	for (int i = 0; i<N; i++) {
		number = rand();
		number = number % 4001 - 2000;									// rand number range is -2000~2000
		sprintf(s_number, "%d", number);								// trans number to string
		fputs(s_number, fd1);
		fputc('\n', fd1);																// write to file
	}
	fclose(fd1);

	return 0;
}
