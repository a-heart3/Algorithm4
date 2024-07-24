#include <stdio.h>
#include <stdbool.h>

extern int *UF;
extern int N;
extern int *size;

int find_root (int p)
{
	while (UF[p] != p) {
		p = UF[p];
	}

	return p;
}

bool UF_connected (int p, int q)
{
	return (find_root(p) == find_root(q));
}


void UF_union (int p, int q)
{
	int root_p = find_root(p);
	int root_q = find_root(q);
	
	/* use size to record the size of tree
	 * make small tree as the large tree 's subtree
	 */
	if (size[root_p] >= size[root_q]) {
		UF[root_q] = UF[root_p];
		size[root_p] += size[root_q];
	}
	else {
		UF[root_p] = UF[root_q];
		size[root_q] += size[root_p];
	}
}

int UF_count()
{
	int i = 0;
	int count = 0;
	for(i; i<N; i++) {
		if (UF[i] == i) count++;
	}

	return count;
}
		

