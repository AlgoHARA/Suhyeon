#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

int n, m, k;
int board[101][101] = { 0 };
bool visited[101][101] = { false };

int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

int dfs(int y, int x) {
	int cnt = 1;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny > n || nx > m) continue;
		if (board[ny][nx] == 0 || visited[ny][nx]) continue;

		visited[ny][nx] = true;
		cnt += dfs(ny, nx);

	}

	return cnt;
}

int main() {
	int i, j;
	int y, x;
	int cnt, max = 0;

	cin >> n >> m >> k;

	for (i = 0; i < k; i++) {
		cin >> y >> x;
		board[y][x] = 1;
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			if (board[i][j] == 1 && !visited[i][j]) {
				visited[i][j] = true;
				cnt = dfs(i, j);
				if (cnt > max) max = cnt;
			}
		}
	}

	cout << max << '\n';

	return 0;
}
