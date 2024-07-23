#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int *UF;																				// Define global variable UF
int N;																					// Define global variable UF length
bool UF_connected (int p, int q);								// Declare the connected function
void UF_union (int p, int q);										// Declare the union function
int  UF_count ();												// Count how many components

void initial_UF()
{
	/* Initialize component id array */
	int i = 0;
	for(i; i<N; i++) {
		UF[i] = i;
	}
}

int main(int argc, char *argv[])
{
		FILE *fd;
		assert(argc >= 2);
		fd = fopen(argv[1], "r");										// Use first arguments as open file path
		char line[100];
		fgets(line, 100 ,fd);												// Read number of sites, in c, line store string
		N = atoi(line);															// Use atoi to transfer string to an integer	
		UF = (int *) calloc (N, sizeof(int));				// Create an array dynamically
		initial_UF();																// Initialize N components
		while (fgets(line, 100, fd) != NULL) {
			int p = atoi(strtok(line, " "));				
			int q = atoi(strtok(NULL, " "));					// Read pair to connect
			if (UF_connected(p,q)) continue;					// Ignore if connected
			UF_union(p,q);														// Combine components
			printf("%d %d\n", p, q);									// and print connection
		}
		int result = UF_count();
		printf("%d components\n", result);	
		fclose(fd);
		return 0;
}
