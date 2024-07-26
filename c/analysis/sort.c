#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

char **s;
FILE *fd;
FILE *fd2;
int idx[3];
int *idx1;

int get_lines()
/* get the numbers of lines */
{
	char c;
	int lines = 0;
	while((c=fgetc(fd)) != EOF) {
		if (c == '\n') lines++;
	}
	return lines;
}

void initial_array(int lines)
/* Initialize the array */
{
	int i = 0;
	s = (char **) calloc (lines, sizeof(char *));
	for(i; i<lines; i++) {
		s[i] = (char *)calloc(50, sizeof(char));
	}
	idx1 = (int *)calloc(lines-2, sizeof(int));
}

	

int find_min(int num[], int start, int end) 
/* find the min number from array */
{
	int i = start;
	int min = i;
	for(int; i < end; i++) {
		if(num[i] < num[min]) min = i;
	}
	return min;
}

void sort_lines(){
/* use to sort the integer in one line */
	int min = 0;
	int temp = 0;
	for (int i = 0; i<2; i++) {
		min = find_min(idx, i, 3);
		temp = idx[i];
		idx[i] = idx[min];
		idx[min] = temp;
	}	
}	

void print_num(int nums[], int length)
/* use to print numbers */
{
	for(int i = 0; i<length; i++) {
		printf("%d ", nums[i]);
	}
	printf("\n");
}

void print_string(int length) {
/* use to print all strings of file by line */
	for(int i = 0; i < length; i++) {
		printf("%s", s[i]);
	}
}

void sort_se (int lines) {
/* sort the lines by first integer */
	int i = 0;
	int min = 0;
	int temp = 0;
	char temp_s[50];
	for (i; i<lines; i++) {
		min = find_min(idx1, i, lines);							// find the min first integer ppsition
		/* exchange the integer array */
		temp = idx1[i];
		idx1[i] = idx1[min];
		idx1[min] = temp;
		/* exchange the string array */
		strcpy(temp_s, s[i]);
		strcpy(s[i], s[min]);
		strcpy(s[min], temp_s);
	}
}


int main(int argc, char *argv[])
{
	/* print lines
	 * read every line
	 * sort by number3
	 * sort by number2
	 * sort by number1
	 * write to file
	 */
	assert(argc > 1);
	fd = fopen(argv[1], "r");
	fd2 = fopen("sort_result", "w");
	int line_num = get_lines();
	printf("%d\n", line_num);
	initial_array(line_num);
	printf("initial is OK\n\n");
	char lines[50];
	rewind(fd);
	for (int i = 0; i < line_num; i++) {
		/* read lines into **S */
		fgets(lines, 50, fd);
		printf("This is lines: %s", lines);
		strcpy(s[i], lines);	
		printf("This is s[i]: %s", s[i]);
	}
	printf("\n\n\n");
	for (int i = 0; i < line_num-2; i++) {
		/* split the integer in the same line
		 * sort the integer
		 * store the inter array into string s[i]
	   */
		strcpy(lines,s[i]);
		idx[0] = atoi(strtok(lines, " "));	
		idx[1] = atoi(strtok(NULL, " "));
		idx[2] = atoi(strtok(NULL, " "));
		printf("This is index1, index2, index3: %d %d %d\n", idx[0], idx[1], idx[2]);
		printf("This is the string: %s", s[i]);
		sort_lines();
		printf("after sort, this is index1, index2, index3: %d %d %d\n", idx[0], idx[1], idx[2]);
		sprintf(s[i], "%d %d %d\n", idx[0], idx[1], idx[2]);
		printf("after sort, this is the string:%s\n",s[i]);
	}
	printf("\n\n\n");
	for (int i = 0; i < line_num-2; i++) {
		/* split the first number in the line */
		strcpy(lines, s[i]);
		idx1[i] = atoi(strtok(lines, " "));
	}

	sort_se(line_num-2);
	printf("This is sort result:\n");
	print_string(line_num);
	
	for (int i = 0; i < line_num; i++) {
		/* write into file */
		fputs(s[i], fd2);
	}	
	fclose(fd); 
 return 0;
}
