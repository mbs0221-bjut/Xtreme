#include <stdio.h>
#include <limits.h>

int main() {
	int A, B, CA, CB, M, i, T, N, W[500];
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		for (i = 0; i < N; i++) {
			scanf("%d", &W[i]);
		}
		//solve
		A = B = -1;
		M = 0;
		for (i = 0; i < N; i++) {
			printf("Cache:%04d\t%04d\n", A, B);
			if (A == W[i] || B == W[i]) {
				continue;// hit
			}
			if (A == -1) {
				M++;
				A = W[i]; // replace A
			}
			else if (B == -1) {
				M++;
				B = W[i]; // replace B
			}
			else {
				int j;
				for (j = i; j < N && A != W[j]; j++);CA = j;
				for (j = i; j < N && B != W[j]; j++);CB = j;
				if (CA >= CB) {
					M++;A = W[i];// replace A
				}
				else {
					M++;B = W[i];// replace B
				}
			}
		}
		printf("Cache:%4d\t%4d\n", A, B);
		printf("Misses:%4d\n", M);
	}
	scanf("%d", &N);
	return 0;
}