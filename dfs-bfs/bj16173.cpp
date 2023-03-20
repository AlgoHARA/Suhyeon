#include <iostream>
#include <cstdio>
#include <string>
#include <queue>
using namespace std;

int graph[3][3];

int main() {
	int n, i, j;
	cin >> n;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}

	queue<pair<int, int>> q;
	bool visited[3][3] = { false };

	int y, x, ny, nx;
	q.push(make_pair(0, 0));
	visited[0][0] = true;

	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();

		// 1) 오른쪽으로 이동해본다
		ny = y;
		nx = x + graph[y][x];
		if (nx < n && !visited[ny][nx]) {
			q.push(make_pair(ny, nx));
			visited[ny][nx] = true;
		}

		// 2) 아래로 이동해본다
		ny = y + graph[y][x];
		nx = x;
		if (ny < n && !visited[ny][nx]) {
			q.push(make_pair(ny, nx));
			visited[ny][nx] = true;
		}
	}

	if (visited[n - 1][n - 1]) printf("HaruHaru\n");
	else printf("Hing\n");
	return 0;
}
