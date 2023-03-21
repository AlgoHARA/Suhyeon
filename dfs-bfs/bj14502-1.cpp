#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int n, m; // 행, 열
int area[8][8] = { -2 };
int copi[8][8] = { -2 };
// 0 빈칸, 1 벽, 2 바이러스

vector<pair<int, int>> virus;
int v_size = 0;
vector<pair<int, int>> blank;
int b_size = 0;

int dy[4] = { 0, 0, 1, -1 }; // 행
int dx[4] = { 1, -1, 0, 0 }; // 열

void copyOriginal() {
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			copi[i][j] = area[i][j];
		}
	}

	return;
}

void printCopi() {
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf("%d ", copi[i][j]);
		}
		printf("\n");
	}

	return;
}

void spread() {
	int i, j;
	queue<pair<int, int>> next;

	// 각 virus에 대해서
	for (i = 0; i < v_size; i++) {

		next.push(make_pair(virus[i].first, virus[i].second));

		while (!next.empty()) {
			int y = next.front().first;
			int x = next.front().second;
			next.pop();

			// [y, x]에 대해서 동서남북 확인
			for (j = 0; j < 4; j++) {
				int ny = y + dy[j];
				int nx = x + dx[j];

				if (ny < 0 || ny >= n || nx < 0 || nx >= m || copi[ny][nx] != 0) continue;

				copi[ny][nx] = 2;
				next.push(make_pair(ny, nx));
			}
		}
		
	}

	return;
}

int countSafe() {
	int i, j;
	int cnt = 0;

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (copi[i][j] == 0) cnt++;
		}
	}

	return cnt;
}

int main() {
	int i, j, k;
	int cnt;
	int max_cnt = -1;
	cin >> n >> m;

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cin >> area[i][j];
			if (area[i][j] == 2)
				virus.push_back(make_pair(i, j));
			else if (area[i][j] == 0)
				blank.push_back(make_pair(i, j));
		}
	}

	v_size = virus.size();
	b_size = blank.size();

	// blank에서 3개 골라서(i, j, k) 거기에 벽을 세워보자
	for (i = 0; i <= b_size - 3; i++) {
		area[blank[i].first][blank[i].second] = 1;
		for (j = i + 1; j <= b_size - 2; j++) {
			area[blank[j].first][blank[j].second] = 1;
			for (k = j + 1; k <= b_size - 1; k++) {
				area[blank[k].first][blank[k].second] = 1;
				copyOriginal();
				
				// copi[][]와 virus에 대해서 dfs 수행해보기
				spread();

				// 바이러스가 퍼진 후 copi[]에서 안전 영역의 개수는?
				cnt = countSafe();
				if (max_cnt < cnt) {
					//printf("current i=%d, j=%d, k=%d\n", i, j, k);
					//printCopi();
					max_cnt = cnt;
				}

				area[blank[k].first][blank[k].second] = 0;
			}
			area[blank[j].first][blank[j].second] = 0;
		}
		area[blank[i].first][blank[i].second] = 0;
	}

	cout << max_cnt << '\n';

	return 0;
}
