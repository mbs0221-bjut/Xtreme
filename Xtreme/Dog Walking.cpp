#include <iostream>
#include <algorithm>

#define PRINT()  /*for (i = 0; i < N; i++) {printf("%d ", dogs[i]);}printf("\n");*/

#define NUM_N 100000

int comp(const void *a, const void *b){
	return *(int*)a - *(int*)b;
}

int main() {
	int i, MIN, T, N, K;
	int dogs[NUM_N];
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &N, &K);
		i = 0;
		while (i < N) {
			scanf("%d", &dogs[i]);
			i++;
		}
		PRINT();
		qsort(dogs, N, sizeof(int), comp);
		PRINT();
		for (i = 0; i < N - 1; i++) {
			dogs[i] = dogs[i + 1] - dogs[i];
		}
		PRINT();
		qsort(dogs, N - 1, sizeof(int), comp);
		PRINT();
		i = (N - 1) - K;
		MIN = 0;
		while (i > -1) {
			MIN += dogs[i];
			i--;
		}
		printf("%d\n", MIN);
	}
	scanf("%d", &MIN);
	return 0;
}