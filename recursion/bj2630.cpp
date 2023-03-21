#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int n;
int board[128][128] = { 0 };

int nblue = 0;
int nwhite = 0;

bool checkIfSame(int y1, int x1, int y2, int x2) {
	int i, j;
	int blue;

	if (board[y1][x1] == 1) blue = 1;
	else blue = 0;

	for (i = y1; i <= y2; i++) {
		for (j = x1; j <= x2; j++) {
			if (board[i][j] != blue) return false;
		}
	}

	if (blue == 1) nblue++;
	else nwhite++;

	return true;
}

// 지금 (y1,x1)~(y2,x2)를 자를 것인가, 안 자를 것인가?
void divideByTwo(int y1, int x1, int y2, int x2) {

	if (!checkIfSame(y1, x1, y2, x2)) { // 그럼 잘라야 해

		int my = y1 / 2 + y2 / 2;
		int mx = x1 / 2 + x2 / 2;

		divideByTwo(y1, x1, my, mx); // 1
		divideByTwo(y1, mx + 1, my, x2); // 2
		divideByTwo(my + 1, x1, y2, mx); // 3
		divideByTwo(my + 1, mx + 1, y2, x2); // 4
	}
	else return;
}

int main() {
	int i, j;
	cin >> n;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	divideByTwo(0, 0, n - 1, n - 1);

	cout << nwhite << '\n' << nblue << '\n';
	return 0;
}
