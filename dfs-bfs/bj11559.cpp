#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

char field[12][6];
int visited[12][6];

int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

vector<pair<int, int>> pop; // bfs로 찾은 이번에 터뜨릴 뿌요

int cnt = 0;
bool happen = true;

void printField() {
	int i, j;

	printf("start printing...\n");
	for (i = 0; i < 12; i++) {
		for (j = 0; j < 6; j++) {
			printf("%c", field[i][j]);
		}
		printf("\n");
	}
	printf("finish printing...\n");
	return;
}

void bfs(int sy, int sx) {
	int i;
	queue<pair<int, int>> q;
	char color = field[sy][sx];
	pop.clear();

	q.push(make_pair(sy, sx));
	pop.push_back(make_pair(sy, sx));
	visited[sy][sx] = 1;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= 12 || nx < 0 || nx >= 6) continue;
			if (field[ny][nx] != color || visited[ny][nx] == 1) continue;

			visited[ny][nx] = 1;
			q.push(make_pair(ny, nx));
			pop.push_back(make_pair(ny, nx));
		}
	}

	if (pop.size() >= 4) {
		for (i = 0; i < pop.size(); i++) {
			field[pop[i].first][pop[i].second] = '.';
		}
		happen = true;
	}
	
	return;
}

int main() {
	int i, j, a, b;

	for (i = 0; i < 12; i++) {
		for (j = 0; j < 6; j++) {
			cin >> field[i][j];
		}
	}

	while (1) {
		happen = false;
		memset(visited, 0, sizeof(visited));

		// 터질 뿌요가 있는지 확인, 있으면 '.'으로
		for (i = 0; i < 12; i++) {
			for (j = 0; j < 6; j++) {
				if (field[i][j] != '.' && visited[i][j] == 0) {
					//printf("%d, %d\n", i, j);
					bfs(i, j);
				}
			}
		}
		//printf("popping finished!\n");
		//printField();

		// if 뿌요가 터진 적이 없다
		if (!happen) break;

		// 내려갈 수 있으면 한 칸씩 내려준다
		for (i = 10; i >= 0; i--) {
			for (j = 0; j < 6; j++) { // field[i][j]를 어디까지 내릴 수 있나.
				if (field[i][j] != '.') {
					int down = 1;
					while (i + down <= 11 && field[i + down][j] == '.') down++;
					if (down == 1); // (밑에 칸이 다 차있어서) 내릴 수 없다
					else { // down-1 만큼 j열을 다 내려줘야 한다
						for (a = i; a >= 0; a--) {
							field[a + down - 1][j] = field[a][j];
						}
						field[0][0] = '.';
					}
				}

			}
		}
		//printf("moving down finished!\n");
		//printField();

		cnt++;
	}

	cout << cnt << '\n';

	return 0;
}
