#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int dy[4] = { 0, 0, 1, -1 }; // (행) 동서남북
int dx[4] = { 1, -1, 0, 0 }; // (열) 동서남북

int m, n; // [n][m]
int k; // 배추가 심어져 있는 위치

int let[51][51] = { 0 };
bool visited[51][51] = { false };

void bfs(int row, int col) {
	queue<pair<int, int>> q;

	q.push(make_pair(row, col));
	visited[row][col] = true;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if (ny < 0 || ny >= n || nx < 0 || nx >= m || let[ny][nx] == 0 || visited[ny][nx]) continue;

			visited[ny][nx] = true;
			q.push(make_pair(ny, nx));
		}
	}

	return;
}

int main() {
	int t;
	int a, b, c;
	int cnt;

	cin >> t;

	for (a = 0; a < t; a++) {
		cin >> m >> n >> k; // [n][m]
		cnt = 0;
		memset(let, 0, sizeof(let));
		memset(visited, false, sizeof(visited));

		for (b = 0; b < k; b++) {
			int x, y;
			cin >> x >> y;
			let[y][x] = 1;
		}

		for (b = 0; b < n; b++) {
			for (c = 0; c < m; c++) {
				if (!visited[b][c] && let[b][c] == 1) {
					bfs(b, c);
					cnt++;
				}
			}
		}

		cout << cnt << '\n';
	}

	return 0;
}
