#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int n, r, c;
int ans = 0;

void search(int y, int x, int size) {

	if (y == r && x == c) {
		cout << ans << '\n';
		return;
	}
	
	// [r, c]가 현재 사분면에 존재한다면
	if (y <= r && r < y + size && x <= c && c < x + size) {
		// 1사분면 탐색
		search(y, x, size / 2);
		// 2사분면 탐색
		search(y, x + size / 2, size / 2);
		// 3사분면 탐색
		search(y + size / 2, x, size / 2);
		// 4사분면 탐색
		search(y + size / 2, x + size / 2, size / 2);
	}
	else {
		ans += size * size;
	}
}

int main() {
	cin >> n >> r >> c;
	search(0, 0, pow(2, n));
	return 0;
}
