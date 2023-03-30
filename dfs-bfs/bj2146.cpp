#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
using namespace std;

int n;
int ground[100][100];

int c_num = 2;
int visited[100][100];
int this_num;

vector<pair<int, int>> sea;
vector<pair<int, int>> outline;

int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0, };

void bfs(int sy, int sx) {
	queue<pair<int, int>> q;
	int i;

	q.push(make_pair(sy, sx));
	visited[sy][sx] = 1;
	ground[sy][sx] = c_num;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
			if (ground[ny][nx] == 0 || visited[ny][nx] == 1) continue;

			visited[ny][nx] = 1;
			ground[ny][nx] = c_num;
			q.push(make_pair(ny, nx));
		}
	}

	return;
}

void checkFourDir(int sy, int sx) {
	int i;

	for (i = 0; i < 4; i++) {
		int ny = sy + dy[i];
		int nx = sx + dx[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
		if (ground[ny][nx] == 0 || visited[ny][nx] == 1) continue;

		visited[ny][nx] = 1;
		outline.push_back(make_pair(ny, nx));
	}

	return;
}

void printGround() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%2d ", ground[i][j]);
		}
		printf("\n");
	}
	return;
}

void moveToAnother(int sy, int sx) {
	queue<pair<int, int>> q;
	int i;
	int my = ground[sy][sx];
	int this_min = 10000;

	visited[sy][sx] = 0;
	q.push(make_pair(sy, sx));

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		int cur = visited[y][x];
		q.pop();

		for (i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

			if (ground[ny][nx] == 0) {

				// [ny][nx]를 방문한 적이 없다
				if (visited[ny][nx] == -1) {
					visited[ny][nx] = cur + 1;
					q.push(make_pair(ny, nx));
				}

				// [ny][nx]를 방문한 적이 있다
				else {
					if (visited[ny][nx] > cur + 1) {
						visited[ny][nx] = cur + 1;
					}
				}
			}

			else if (ground[ny][nx] != my) { // 새로운 땅에 도달했다
				this_num = cur;
				return;
			}

		}
	}

}

int main() {
	int i, j;

	cin >> n;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cin >> ground[i][j];
			if (ground[i][j] == 0)
				sea.push_back(make_pair(i, j));
		}
	}

	// 1. 각 대륙끼리 숫자로 표시 (2~?)
	memset(visited, 0, sizeof(visited));
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (ground[i][j] != 0 && !visited[i][j]) {
				bfs(i, j);
				c_num++;
			}
		}
	}
	
	// 2. sea와 인접한, 각 대륙의 테두리(outline)를 구한다
	memset(visited, 0, sizeof(visited));
	for (i = 0; i < sea.size(); i++) {
		checkFourDir(sea[i].first, sea[i].second);
	}

	// 3. 각 outline 좌표에서, 다른 대륙으로 이동해본다
	int real_min = 10000;
	for (i = 0; i < outline.size(); i++) {
		//printf("outline[%d] = [%d][%d]\n", i, outline[i].first, outline[i].second);

		memset(visited, -1, sizeof(visited));
		moveToAnother(outline[i].first, outline[i].second);

		/*
		for (int a = 0; a < n; a++) {
			for (int b = 0; b < n; b++) {
				printf("%2d ", visited[a][b]);
			}
			printf("\n");
		}
		printf("so...this returns %d\n", this_min);
		*/

		if (this_num < real_min) real_min = this_num;
	}

	cout << real_min << '\n';

	return 0;
}
