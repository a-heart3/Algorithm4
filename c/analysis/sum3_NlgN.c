#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

extern int *numbers;
extern int N;

static void print()
{
	int i = 0;
	for (i; i<N; i++) {
		printf("%d ", numbers[i]);
	}
	printf("\n");
}

static void quick_sort(int low, int high)
{
	if (low>= high) return;
	int l = low;
	int h = high;
	int val = numbers[low];
	printf("%d\n", val);
	while (true) {
		if (h == l) break;
		while (h != l && numbers[h] >= val) h--;
		numbers[l] = numbers[h];	 
		while (h != l && numbers[l] < val) l++;
		numbers[h] = numbers[l];
		print();
	}
	numbers[l] = val;
	quick_sort(low, l-1);
	quick_sort(l+1, high);
}

static bool binary_search(int low, int high, int target)
{
	if(low > high) return false;
	int mid = (low + high) / 2;
	if(numbers[mid] == target) return true;
	else if(numbers[mid] < target) return binary_search(low, mid-1, target);
	else return binary_search(mid+1, high, target);
}

int sum3()
{
	int i = 0;
	int j;
	int target;
	int count = 0;
	quick_sort(0, N-1);
	for (i; i<N; i++) {
		for (j = i + 1; j<N; j++) {
			target = -(numbers[i] + numbers[j]);
			if (binary_search(j+1, N-1, target)) {
				printf("%d %d %d\n", numbers[i], numbers[j], target);
				count++;	
			}
		}
	}
	
	return count;
}
