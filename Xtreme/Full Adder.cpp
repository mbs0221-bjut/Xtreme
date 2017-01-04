#include <stdio.h>
#include <string.h>
#include <math.h>

#define N 10000

void reverse(char *str) {
	int start, end;
	start = 0, end = strlen(str) - 1;
	while (start < end) {
		char c = str[end];
		str[end] = str[start];
		str[start] = c;
		start++, end--;
	}
}

int radix;
char sym[256], map[256];
char A[N], B[N], C[N], S[N];

void myitoa(char *a, int s, int e) {
	for (int j = s; j < e; j++) {
		a[j] = map[a[j]];
	}
}

void myatoi(char *a, int s, int e) {
	for (int j = s; j < e; j++) {
		a[j] = sym[a[j]];
	}
}

int main() {
	char c;
	int i, nx, ny, n;
	scanf("%d%s", &radix, sym);
	for (char j = 0; j < radix; j++) {
		map[sym[j]] = j;
	}
	memset(A, '\0', sizeof(A));
	memset(B, '\0', sizeof(B));
	memset(C, '\0', sizeof(C));
	scanf("%s", A);
	scanf("%c%s", &c, B);
	scanf("%s", S);
	printf("%d %s\n", radix, sym);
	n = strlen(S);
	ny = strlen(A);
	while (n > ny) { printf(" "); n--; }
	printf("%s\n", A);

	n = strlen(S);
	nx = strlen(B);

	printf("%s\n", B);
	printf("%s\n", S);
	reverse(A);
	reverse(B);
	nx = strlen(A) - 1;
	ny = strlen(B) - 1;
	while (A[nx] == ' ') { A[nx] = '\0'; nx--; }
	while (B[ny] == ' ' || B[ny] == '+') { B[ny] = '\0'; ny--; }
	nx = strlen(A);
	ny = strlen(B);
	if (nx > ny) {
		n = nx;
		memset(B + ny, sym[0], (nx - ny));
	}
	else {
		n = ny;
		memset(A + nx, sym[0], (ny - nx));
	}
	myatoi(A, 0, nx);
	myatoi(B, 0, ny);
	for (i = 0; i < n; i++) {
		char c = A[i] + B[i];
		C[i + 1] = c / radix;// carry
		C[i] += c%radix;// res
	}
	myitoa(C, 0, n);
	nx = strlen(C) - 1;
	while (C[nx] == sym[0]) {
		C[nx] = '\0';
		nx--;
	}
	reverse(C);
	nx = strlen(C) - 1;
	while (nx++ < n) {
		printf(" ");
	}
	printf("%s\n", C);
	scanf("%d", &n);
	return 0;
}