#include <stdio.h>
#include <limits.h>

#define LONG long long

LONG gcd(LONG a, LONG b){
	LONG c = a%b;
	while (c) {
		a = b;
		b = c;
		c = a % b;
	}
	return b;
}

void set(LONG N, LONG A, LONG B) {
	LONG i, j, k, sum;
	sum = 0;
	for (i = A; i <= B; i++) {
		if (N%i == 0)continue;
		if (gcd(N, i) > 1) {
			continue;
		}
		sum += i;
	}
	printf("%lld\n", sum% 1000000007);
}

int main() {
	LONG Q, N, A, B;
	scanf_s("%lld", &Q);
	while (Q--){
		scanf_s("%lld%lld%lld", &N, &A, &B);
		set(N, A, B);
	}
	scanf_s("%lld", &N);
	return 0;
}