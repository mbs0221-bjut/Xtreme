#include <iostream>

#define N 300000

using namespace std;

char pwd[N];

//
void check(int i, int j, int k) {
	int a, b, c;
	a = i, b = j, c = k;
	for (; a <= b; ) {
		if (pwd[a] != pwd[c]) {
			cout << "N" << endl;
			return;
		}
		a++, c++;
	}
	cout << "Y" << endl;
}

// replace substring from i to j 
void replace(int i, int j, int k) {
	int a, b, c;
	a = i, b = j, c = k;
	for (; a <= b; ) {
		pwd[a] = pwd[c];
		a++, c++;
	}
}

void replace(int i, int j) {
	int a, b;
	for (a = i, b = j; a <= b; a++) {
		if (pwd[a] == 'z')pwd[a] = 'a'; else pwd[a] = pwd[a] + 1;
	}
}

int main() {
	int cmd, n, d, i, j, k, ret;
	std::ios_base::sync_with_stdio(false);
	cin >> pwd;
	cin >> n;
	for (d = 0; d < n; d++) {
		cin >> cmd;
		switch (cmd) {
		case 1:
			cin >> i >> j >> k;
			check(i - 1, j - 1, k - 1);
			break;
		case 2:
			cin >> i >> j >> k;
			replace(i - 1, j - 1, k - 1);
			break;
		case 3:
			cin >> i >> j >> k;
			replace(i - 1, j - 1);
			break;
		default:
			break;
		}
	}
	getchar();
	return 0;
}