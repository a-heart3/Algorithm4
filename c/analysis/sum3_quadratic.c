#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

extern int *numbers;
extern int N;
/*
static void print()
{
	int i = 0;
	for (i; i<N; i++) {
		printf("%d ", numbers[i]);
	}
	printf("\n");
}
*/

int partition(int low, int high) {
	/* find the pivot position */
	int pivot = numbers[low];
	while(low < high) {
		while (low<high && numbers[high]>=pivot) high--;
		numbers[low] = numbers[high];
		while (low<high && numbers[low]<=pivot) low++;
		numbers[high] = numbers[low];
	}
	numbers[low] = pivot;
	return low;
}
		
static void quick_sort(int low, int high)
	/* quick_sort */
{
	if(low >= high) return;
	else {
		int pivotpos = partition(low, high);
		quick_sort(low, pivotpos-1);
		quick_sort(pivotpos+1, high);
	}
}

static int find_match(int target, int start, int end) {
	/* Find how many conditions macth numbers[i] + number[j] == -target */
	int i = start;
	int j = end;
	int count = 0;
	int k = -target;
	while(i < j) {
		if (numbers[i] + numbers[j] < k) i++;														 // If sum < k, need plus, so i++
		else if(numbers[i] + numbers[j] > k) j--;												 // If sum > k, need reduce, so j--
		else {
		/* If sum = k
		 * i++, j-- in the same time
	   * count++
		 */
			printf("%d %d %d\n", target, numbers[i], numbers[j]); 
			i++;
			j--;
			count++;
		}
	}
	return count;
}
			



int sum3()
{
	/* First, sort the input
	 * the confirm i
	 * then judge -i in thearray
	 */
	int i = 0;
  int  count = 0;
	quick_sort(0, N-1);																									// First sort
	for (i; i<N-2; i++) {	
		count += find_match(numbers[i], i+1, N-1);
	}
	
	printf("%d\n", count);
	return count;
}
