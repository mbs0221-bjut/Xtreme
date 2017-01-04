


#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

struct soldier {
	int i;
	float d, x, y;
};

struct shelter{
	int i;
	float d, x, y;
};

int used[500];
float map[500][500];
soldier so[500];
shelter sh[500];

int main() {
	int n;
	float max, sum;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		used[i] = -1;
		so[i].i = -1;
		scanf("%f %f", &so[i].x, &so[i].y);
	}
	for (int i = 0; i < n; i++) {
		sh[i].i = i;
		scanf("%f %f", &sh[i].x, &sh[i].y);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = sqrt((so[i].x - sh[i].x)*(so[i].x - sh[i].x) + (so[i].y - sh[i].y)*(so[i].y - sh[i].y));
		}
	}
	for (int i = 0; i < n; i++) {
		int min = 0;
		for (int j = 0; j < n; j++) {
			printf("%04f\t", map[i][j]);
			if (used[j] > -1)continue;
			if (map[i][j] < map[i][min]) {
				min = j;
			}
		}
		printf("\n");
		used[min] = i;// min is used by i soldier
		so[i].i = min;
		so[i].d = map[i][min];
	}
	max = sum = 0;
	for (int i = 0; i < n; i++) {
		if (so[i].d > max) {
			max = so[i].d;
		}
		sum += so[i].d;
	}
	printf("%04f\n%04f\n", max, sum);
	scanf("%d", &n);
}