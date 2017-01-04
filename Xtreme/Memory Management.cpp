#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int FIFO(int *addrs, int p, int s, int n) {
	int front, hits, misses;
	int *pages = new int[p];
	memset(pages, p, sizeof(int)*p);
	front = misses = 0;
	for (int i = 0; i < n; i++) {
		pages[i] = -1;
	}
	for (int i = 0; i < n; i++) {
		int page = floor(addrs[i] / s);
		hits = 0;
		for (int i = 0; i < p; i++) {
			if (pages[i] == page) {
				// hits
				hits = 1;
			}
		}
		// replace front
		if (hits == 0) {
			// replace
			pages[front] = page;
			front = (front + 1) % p;
			misses++;
		}
	}
	return misses > p ? misses - p : 0;
}

int LRU(int *addrs, int p, int s, int n) {
	int hits, misses, max;
	int *pages = new int[p];
	int *time = new int[p];
	for (int i = 0; i < p; i++) {
		pages[i] = -1;
		time[i] = p - i - 1;
	}
	misses = 0;
	for (int i = 0; i < n; i++) {
		int page = floor(addrs[i] / s);
		// find
		//printf("LRU:");
		hits = 0;
		for (int j = 0; j < p; j++) {
			//printf("[%3d,%3d] ", pages[j], time[j]);
			if (pages[j] == page) {
				// hits
				hits = 1;
				time[j] = 0;
			} else {
				time[j]++;
			}
		}
		//printf("\n");
		// replace
		if (hits == 0) {
			// get max
			max = 0;
			for (int j = 0; j < p; j++) {
				if (time[j] > time[max]) {
					max = j;
				}
			}
			// replace min
			pages[max] = page;
			time[max] = 0;
			// timer
			for (int j = 0; j < p; j++) {
				if (j != max)time[j]++;
			}
			misses++;
		}
	}
	return misses > p ? misses - p : 0;
}

int main() {
	int i, t, p, s, n, fifo, lru;
	int page[128], *addrs;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &p, &s, &n);
		addrs = new int[n];
		for (i = 0; i < n; i++) {
			scanf("%d", &addrs[i]);
		}
		fifo = FIFO(addrs, p, s, n);
		lru = LRU(addrs, p, s, n);
		if (lru < fifo)
			printf("yes %d %d\n", fifo, lru);
		else
			printf("no %d %d\n", fifo, lru);
	}
	scanf("%d", &i);
	return 0;
}