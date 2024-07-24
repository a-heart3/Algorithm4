#include <stdio.h>
#include <stdbool.h>

extern int *UF;
extern int N;

bool UF_connected (int p, int q)
{
	/*
	 * Find the root of p and q
	 * compare whether the root of p and q are equal
	 */
	 return (find_root(p) == find_root(q));
}

int find_root (int p)
{
	/* Return the root of p
   * root is the id[i] = i
   */
	while (UF[p] != p) {								// If UF[p] != p, continue to find the root
		p = UF[p];
	}
	
	return p;
}

void UF_union (int p, int q)
{
	/* First find the root of p and q
	 * Then let the tree include p be the subtree of the tree include q
	 */
	
	int root_p = find_root(p);
	int root_q = find_root(q);

	UF[root_p] = UF[root_q];
}

int UF_count() 
{
	/* if UF[i] == i, then it is a component */
	int i = 0;
	int count = 0;
	for (i; i<N; i++) {
		if(UF[i] == i) count++;
	}

	return count;
}
