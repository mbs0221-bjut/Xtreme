#include <stdio.h>
#include <string.h>
#include <math.h>

char matrix[5][5];

void VerticalFlip(int x, int y, int r) {
	for (int i = 0; i < r / 2; i++) {
		for (int j = 0; j < r / 2; j++) {
			char c = matrix[x + i][x + j];
			matrix[x + i][y + j] = matrix[x + r - i - 1][y + r - j - 1];
			matrix[x + r - i - 1][y + r - j - 1] = c;
		}
	}
}

void HorizontalFlip(int x, int y, int r) {

}

void Negate(int x, int y, int r) {

}

void search() {
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		for (int i = 0; i < 25; i++) {
			scanf("%c", matrix[i / 5][i % 5]);
		}
	}
}