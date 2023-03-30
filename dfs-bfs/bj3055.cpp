#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
using namespace std;

int r, c;
char forest[50][50];
int visited[50][50];
int mv_time[50][50];

int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

queue<pair<int, int>> water; // (퍼지는) 물 위치
queue<pair<int, int>> s_mv; // 고슴도치가 퍼질 수 있는 위치

int min_t = -1;

void water_spread(int sy, int sx) {
	int i, j;
	visited[sy][sx] = 1;

	for (i = 0; i < 4; i++) {
		int ny = sy + dy[i];
		int nx = sx + dx[i];

		if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
		if (forest[ny][nx] != '.') continue;
		if (visited[ny][nx] == 1) continue;

		visited[ny][nx] = 1;
		forest[ny][nx] = '*';
		water.push(make_pair(ny, nx));
	}

	return;
}

void s_spread(int sy, int sx) {
	int i, j;

	for (i = 0; i < 4; i++) {
		int ny = sy + dy[i];
		int nx = sx + dx[i];

		if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
		
		if (forest[ny][nx] == 'D') {
			min_t = mv_time[sy][sx] + 1;
			//printf("in s_spread(%d, %d), you've arrived to D and time is %d\n", sy, sx, min_t);
			return;
		}
		else if (forest[ny][nx] != '.') continue;

		if (mv_time[ny][nx] != -1) { // 고슴도치가 [ny][nx] 방문한 적 있음
			if (mv_time[ny][nx] > mv_time[sy][sx] + 1 )
				mv_time[ny][nx] = mv_time[sy][sx] + 1;
		}
		else { // 고슴도치가 [ny][nx] 방문한 적 없음
			mv_time[ny][nx] = mv_time[sy][sx] + 1;
			s_mv.push(make_pair(ny, nx));
			//printf("in s_spread(%d, %d), [%d][%d] was added to s_mv\n", sy, sx, ny, nx);
		}
	}

	return;
}

int main() {
	int i, j;

	cin >> r >> c;
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			cin >> forest[i][j];

			switch (forest[i][j]) {
			case 'S': // 고슴도치
				forest[i][j] = '.';
				s_mv.push(make_pair(i, j));
				break;
			case '*': // 물
				water.push(make_pair(i, j));
				break;
			}
		}
	}

	memset(mv_time, -1, sizeof(mv_time));
	mv_time[s_mv.front().first][s_mv.front().second] = 0;

	while (1) {
		// 1. 물이 퍼진다 -> forest[][], water q가 바뀌겠지
		memset(visited, 0, sizeof(visited));
		int water_cnt = water.size();
		for (i = 0; i < water_cnt; i++) {
			water_spread(water.front().first, water.front().second);
			water.pop();
		}

		// 2. 고슴도치가 이동해본다 -> mv_time[][], d_mv q가 바뀌겠지
		int d_cnt = s_mv.size();
		for (i = 0; i < d_cnt; i++) {
			s_spread(s_mv.front().first, s_mv.front().second);
			s_mv.pop();
		}

		if (min_t != -1) break;
		if (s_mv.size() == 0) {
			cout << "KAKTUS" << '\n';
			return 0;
		}
	}

	cout << min_t << '\n';
	return 0;
}
