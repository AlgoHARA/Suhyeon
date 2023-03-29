#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
using namespace std;

int n, m; // 행, 열
int factory[100][100];
int sr, sc, sd; // 로봇의 초기 위치/방향
int tr, tc, td; // 로봇이 도착할 위치/방향
// d가 동0, 서1, 남2, 북3

int cnt = 0; // 명령 횟수

int dy[4] = { 0, 1, 0, -1 }; // 동 남 서 북
int dx[4] = { 1, 0, -1, 0 }; // 동 남 서 북

vector<vector<int>> q;
int q_idx;
vector<int> temp(4);
int visited[100][100][4]; // 동 남 서 북

set<int> ableCmd;

bool isIndexAble(int y, int x) {
	if (y < 0 || y >= n || x < 0 || x >= m) return false;
	else return true;
}

// dy/dx - 동-남-서-북 (오른쪽 방향)
// (왼쪽방향) 동-북-서-남
// from 방향에서 to 방향으로 바꾸려면 몇 번 회전해야 하는지
int turnDir(int from, int to) {
	if (from == to) return 0;

	int l = (from == 0) ? 3 : from - 1;
	if (to == l) return 1;

	int r = (from == 3) ? 0 : from + 1;
	if (to == r) return 1;

	else return 2;
}

// [y][x]에서 d 방향으로 1, 2, 3번 이동한 경우를 q에 추가한다
void addCase(int y, int x, int d, int cmd) {
	int i, j, ny, nx;

	for (i = 1; i <= 3; i++) {
		ny = y + dy[d] * i;
		nx = x + dx[d] * i;

		if (!isIndexAble(ny, nx)) continue;
		if (factory[ny][nx] == 1) return;
		if (visited[ny][nx][d] != -1) { // 방문을 했는데 그 위치에서 방향이 달랐을 수 있으니까 3차원 배열을 쓰는 것
			// 거길 방문했었지만, cmd cnt가 지금이 더 작을 수 있다??
			if (visited[ny][nx][d] < cmd + 1) continue;
			else {
				for (int cur = q_idx; cur < q.size(); cur++) {
					if (q[cur][0] == ny && q[cur][1] == nx && q[cur][2] == d) {
						q[cur][3] = cmd + 1;
						break;
					}
				}
				continue;
			}
		}

		visited[ny][nx][d] = cmd + 1;
		temp[0] = ny; temp[1] = nx; temp[2] = d; temp[3] = cmd + 1;
		q.push_back(temp);
	}
}

void bfs(int sy, int sx, int sdir) {
	int i;
	int ny, nx, nd, ncommand;
	int cnt = 0;

	temp[0] = sy; temp[1] = sx; temp[2] = sdir; temp[3] = 0;
	q.push_back(temp);
	q_idx = 0;
	visited[sy][sx][sdir] = 0;

	while (q_idx < q.size()) {
		int y = q[q_idx][0];
		int x = q[q_idx][1];
		int d = q[q_idx][2];
		int cmd = q[q_idx][3];
		//printf("[%d] y=%d x=%d d=%d cmd=%d\n", cnt, y, x, d, cmd);
		q_idx++;

		if (y == tr && x == tc) { // 원하는 위치엔 도착함
			// 원하는 방향을 안 바라보고 있으면 방향 조정이 필요하다
			ableCmd.insert(cmd + turnDir(d, td));
			continue;
		}

		// 1. 현재(d) 방향으로 1, 2, 3 이동
		addCase(y, x, d, cmd);
		// 2. left 90도 방향으로 1, 2, 3 이동 (동-북-서-남) (dy/dx는 동-남-서-북 순서)
		if (d == 0) nd = 3;
		else nd = d - 1;
		addCase(y, x, nd, cmd + 1);
		// 3. 180도 방향으로 1, 2, 3 이동
		if (d == 0 || d == 1) nd = d + 2;
		else nd = d - 2;
		addCase(y, x, nd, cmd + 2);
		// 4. right 90도 방향으로 1, 2, 3 이동 (동-남-서-북) (마침 dy/dx도 동-남-서-북 순서)
		if (d == 3) nd = 0;
		else nd = d + 1;
		addCase(y, x, nd, cmd + 1);
	}

}

// 동 남 서 북
int correctD(int cur) {
	switch (cur) {
	case 1: // 동
		return 0;
	case 2: // 서
		return 2;
	case 3: // 남
		return 1;
	case 4: // 북
		return 3;
	}
}


int main() {
	int i, j;

	cin >> n >> m;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cin >> factory[i][j];
		}
	}

	cin >> sr >> sc >> sd;
	cin >> tr >> tc >> td;
	sr--; sc--; sd = correctD(sd);
	tr--; tc--; td = correctD(td);

	memset(visited, -1, sizeof(visited));
	bfs(sr, sc, sd);

	int min_cnt = *ableCmd.begin();
	for (auto ab : ableCmd) {
		if (min_cnt > ab) min_cnt = ab;
	}
	
	cout << min_cnt << '\n';

	return 0;
}
