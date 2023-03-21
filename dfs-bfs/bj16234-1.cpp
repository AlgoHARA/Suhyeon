#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int n; // 1~50, n*n크기의 땅
int l, r; // 1~100, 인구차가 l~r명이면 인구 이동 발생

int ground[50][50] = { -1 };
bool visited[50][50];
int day = 0;

vector<pair<int, int>> ally; // 연합을 이루는 칸들
int asum = 0; // 연합의 인구수 합

int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

// debug
void printGround() {
	int i, j;

	printf("*** printing ***\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%04d ", ground[i][j]);
		}
		printf("\n");
	}
	printf("*** printing finished ***\n");

	return;
}

void bfs(int y, int x) {
	queue<pair<int, int>> q;
	int i;

	ally.clear();
	ally.push_back(make_pair(y, x));
	asum = ground[y][x];

	q.push(make_pair(y, x));
	visited[y][x] = true;

	while (!q.empty()) {
		int cury = q.front().first;
		int curx = q.front().second;
		q.pop();

		for (i = 0; i < 4; i++) {
			int ny = cury + dy[i];
			int nx = curx + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx]) continue;

			int dif = ground[cury][curx] - ground[ny][nx];
			if (dif < 0) dif *= -1;
			if (l <= dif && dif <= r) { // 그럼 국경선이 열리고 연합이 생긴다
				q.push(make_pair(ny, nx));
				visited[ny][nx] = true;

				ally.push_back(make_pair(ny, nx));
				asum += ground[ny][nx];
			}
		}
	}

	return;
}

void balancePop() {
	int i;
	int newPop = asum / ally.size();

	for (i = 0; i < ally.size(); i++) {
		ground[ally[i].first][ally[i].second] = newPop;
	}

	return;
}

int main() {
	int i, j;
	bool noAlly; // 연합이 생긴 적이 없나요?

	cin >> n >> l >> r;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cin >> ground[i][j];
		}
	}

	while (1) {
		memset(visited, false, sizeof(visited));
		noAlly = true;

		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				// 국경선이 열릴 일이 있는지 확인한다
				if (!visited[i][j]) {
					// [i][j]에서 bfs 수행
					bfs(i, j);

					if (ally.size() > 1) { // 방금 연합이 생겼었다
						noAlly = false;
						balancePop();
					}
				}
			}
		}

		if (noAlly) break;
		else {
			//printGround();
			day++;
		}
	}

	cout << day << '\n';

	return 0;
}
