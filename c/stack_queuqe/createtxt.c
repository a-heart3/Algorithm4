#include <stdio.h>

int main (int argc, char *argv[])
{
	char line[1000];
	int c;
	int i = 0;
	FILE *fd;
	fd = fopen("test.txt", "w");
	while ((c = getchar()) != EOF) {
		line[i++] = c;
		if(c == '\n') {
			line[i] = '\0';
			printf("%s\n", line);
			fputs(line, fd);
			i = 0;
			continue;
		}	
	}

	fclose(fd);
}
