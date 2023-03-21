#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int n, m; // 행, 열
int box[1000][1000] = { -2 };

queue<pair<int, int>> ripe;
int cnt = 0; // ripe의 원소의 수, 익어 있는 토마토의 개수
int total;
int none = 0;
int day = 0;

int dy[4] = { 0, 0, 1, -1 }; // 행
int dx[4] = { 1, -1, 0, 0 }; // 열

// ripe 각각의 원소들에 대해서 cnt번 한 칸씩 넓힌다
int expand() {
	int i, j;
	int next = 0; // 새롭게 넓혀진 토마토의 개수

	for (i = 0; i < cnt; i++) {
		int y = ripe.front().first;
		int x = ripe.front().second;
		ripe.pop();

		for (j = 0; j < 4; j++) {
			int ny = y + dy[j];
			int nx = x + dx[j];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

			if (box[ny][nx] == 0) { // 그럼 [ny][nx]를 방문해야 한다 (익혀야 한다)
				box[ny][nx] = 1;
				ripe.push(make_pair(ny, nx));
				next++;
			}
		}
	}

	cnt = next;
	return next;
}

int main() {
	int i, j;
	int tmp;

	cin >> m >> n;

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cin >> box[i][j];

			if (box[i][j] == 1) {
				ripe.push(make_pair(i, j));
				cnt++;
			}
			else if (box[i][j] == -1) {
				none++;
			}
		}
	}

	if (n * m - none == cnt) {
		cout << "0\n";
		return 0;
	}

	total = cnt;
	while (1) {
		total += expand();
		day++;

		if (ripe.empty()) {
			cout << "-1\n";
			return 0;
		}
		if (total == n * m - none) {
			cout << day << '\n';
			return 0;
		}
	}
}
