#include <stdio.h>
#include <limits.h>

int M[3][4] = {
	{ 6, 1, 0, INT_MAX }, // C
	{ 12, 0, 2, INT_MAX}, // H
	{ 6, 2, 1, INT_MAX}   // O
};

int main() {
	int C, H, O, find;
	scanf_s("%d%d%d", &M[0][4], &M[1][4], &M[2][4]);
	if (find)
		printf("%d %d %d\n", C, H, O);
	else
		printf("Error\n");
	getchar();
	return 0;
}