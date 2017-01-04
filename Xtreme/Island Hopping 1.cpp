#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <iostream>

#define MAX 400

struct list {
	int index;
	char name[16];
	list *next;
};

class map {
	list *data[256];
	static int count;
public:
	map() {
		for (int i = 0; i < 256; i++) {
			data[i] = NULL;
		}
	}
	void clear() {
		list *t, *p;
		count = 0;
		for (int i = 0; i < 256; i++) {
			p = data[i];
			while (p) {
				t = p;
				p = p->next;
				delete t;
			}
			data[i] = NULL;
		}
	}
	int insert(char *name) {
		int i, n;
		int hash = 0;
		n = strlen(name);
		for (i = 0; i < n; i++) {
			hash += name[i];
		}
		hash %= 256;
		list *p = data[hash];
		if (p) {
			while (p->next) {
				if (!strcmp(p->name, name)) {
					return p->index;
				}
				p = p->next;
			}
			if (!strcmp(p->name, name)) {
				return p->index;
			}
			p->next = new list;
			p->next->next = NULL;
			p->next->index = count++;
			strcpy(p->next->name, name);
		}
		else {
			data[hash] = new list;
			data[hash]->next = NULL;
			data[hash]->index = count++;
			strcpy(data[hash]->name, name);
		}
		return count - 1;
	}
	list *operator [](char *name) {
		int  i, n;
		n = strlen(name);
		int hash = 0;
		for (i = 0; i < n; i++) {
			hash += name[i];
		}
		hash %= 256;
		list *p = data[hash];
		if (p) {
			while (p) {
				if (!strcmp(p->name, name)) {
					return p;
				}
				p = p->next;
			}
		}
		return NULL;
	}
};

int map::count = 0;

int C[50][50], I[50];
map islands;

void search(int n, int u, int v) {
	// greedy
	int s = u;
	int fuel = I[s], costs = 0;
	int max, index, can = 0;
	while (true) {
		// can't access
		if (C[s][v] > 100 && C[s][v] != MAX) {
			can = 0;
			break;
		}
		// can access
		if (fuel >= C[s][v]) {
			can = 1;
			costs += C[s][v];
			break;
		}
		// add fuel
		max = 0;
		index = 0;
		can = 0;
		for (int i = 0; i < n; i++) {
			// can go and can get fuel
			if (i != s && C[s][i] <= fuel && I[i] - C[s][i] > max) {
				max = I[i] - C[s][i];
				index = i;
				can = 1;
			}
		}
		if (can == 0)break;
		fuel = fuel + max;
		costs += C[s][index];
		if (fuel > 100) { fuel = 100;}
		s = index;
	}
	if (can == 1)
		printf("%d\n", costs);
	else
		printf("Impossible\n");
}

int main() {
	char name[16], start[16], end[16];
	int t, n, m, fuel, cost, index;
	scanf("%d", &t);
	while (t--) {
		// init
		islands.clear();
		// fuels
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				C[i][j] = MAX;
			}
			scanf("%s%d", name, &fuel);
			index = islands.insert(name);
			I[index] = fuel;
		}
		// costs
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			scanf("%s%s%d", start, end, &cost);
			int u = islands.insert(start);
			int v = islands.insert(end);
			C[u][v] = C[v][u] = cost;
		}
		// search
		int u = islands.insert("start");
		int v = islands.insert("end");
		search(n, u, v);
	}
	scanf("%d", &n);
	return 0;
}