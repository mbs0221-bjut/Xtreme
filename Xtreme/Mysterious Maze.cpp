#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define	M 1000
#define N 1000

using namespace std;

class Maze {
private:
	int maze[M][N];
	int x, y;
	int state;
public:
	Maze() {
		x = M;
		y = N;
		state = 0;
	}
	void resize(int a, int b) {
		x = a;
		y = b;
		state = 0;
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				maze[i][j] = 1;
			}
		}
	}
	void reset() {
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				if (maze[i][j] == 2) maze[i][j] = 0;
			}
		}
	}
	void putBlock(int a, int b) {
		maze[a][b] = 0;
	}
	int at(int a, int b) {
		return maze[a][b];
	}
	void print() {
		printf("maz\n");
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				printf("%d\t", maze[i][j]);
			}
			printf("\n");
		}
	}
	int search(int i, int j) {
		if (state == 1)return 1;
		if (i < 0 || j < 0 || i > x - 1 || j > y-1) {
			return 0;
		}
		if (i == x - 1)	state = 1;
		if (maze[i][j] == 0) {
			maze[i][j] = 2;// visited
			if (state == 0 && j > 0 && maze[i][j - 1] == 0) search(i, j - 1);// left
			if (state == 0 && j < y - 1 && maze[i][j + 1] == 0) search(i, j + 1);// right
			if (state == 0 && i > 0 && maze[i - 1][j] == 0) search(i - 1, j);// up
			if (state == 0 && j < y - 1 && maze[i + 1][j] == 0) search(i + 1, j);// down
			if (state == 1)maze[i][j] = 0;// unvisisted
		}
		return state;
	}
};

Maze maz;

int main() {
	int x, i, j, c, find;
	scanf("%d", &x);
	maz.resize(x, x);
	c = 0;
	find = 0;
	while (true) {
		scanf("%d", &i);
		if (i == -1)break;
		scanf("%d", &j);
		maz.putBlock(i - 1, j - 1);
		if (find != 1) {
			c++;
			for (int i = 0; i < x; i++) {
				if (maz.at(0, i) == 1)continue;
				find = maz.search(0, i);
				maz.reset();
				if (find == 1)break;
			}
		}
	}
	maz.print();
	if (find == 1)printf("%d\n", c);
	else printf("-1\n");
	char str[12];
	scanf("%s", str);
	return 0;
}