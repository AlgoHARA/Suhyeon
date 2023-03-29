#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int n, m; // 행, 열
int castle[50][50];
int visited[50][50];

int ifWall[4] = { 4, 1, 8, 2 }; // 동 서 남 북에 벽이 있으면 그 값들을 합한 값
vector<bool> w_visited(4, false); // 동 서 남 북 에 벽이 있으면 true/false, dfs_wall에서 마치 visited 같다
map<int, vector<bool>> wallCalc;

map<int, int> room; // [1] 1번 방에 속하는 칸의 개수

vector<int> temp(4); // a, b, c, d
vector<vector<int>> wall; // [a][b]와 [c][d] 사이에 벽이 있다 = 그 벽을 허물면 두 방을 합칠 수 있다

int roomNo = 0;

int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

// ifWall[]의 값들을 조합해본다
void dfs_wall(int start) {
	int i, j;
	int sum;

	for (i = start; i < 4; i++) {
		if (w_visited[i]) continue;
		w_visited[i] = true;

		int sum = 0;
		for (j = 0; j < 4; j++)
			if (w_visited[j]) sum += ifWall[j];
		wallCalc[sum] = w_visited;

		dfs_wall(i + 1);
		w_visited[i] = false;
	}

	return;
}

void dfs(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
			continue;
		}
		if (wallCalc[castle[y][x]][i]) { // 벽에 막혀 있어서 [y][x]에서 i쪽으로 [ny][nx]로 이동 불가
			temp[0] = y; temp[1] = x;
			temp[2] = ny; temp[3] = nx;
			wall.push_back(temp);
			continue;
		}
		if (visited[ny][nx] != -1) {
			continue;
		}

		visited[ny][nx] = roomNo;
		room[roomNo]++;

		dfs(ny, nx);
	}

	return;
}

int find_max_in_map_room() {
	int max_size = -1;
	for (int i = 0; i < room.size(); i++) {
		if (room[i] > max_size) max_size = room[i];
	}

	return max_size;
}

int main() {
	int i, j;

	cin >> m >> n;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cin >> castle[i][j];
		}
	}

	// 4, 1, 8, 2 조합으로 나올 수 있는 가짓수를 구해서 wallCalc를 만든다
	wallCalc[0] = w_visited;
	dfs_wall(0);

	memset(visited, -1, sizeof(visited));

	// (0, 0)에서부터 dfs 시작
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (visited[i][j] == -1) {
				visited[i][j] = roomNo;
				room[roomNo] = 1;
				dfs(i, j);
				roomNo++;
			}
		}
	}

	// 1. 이 성에 있는 방의 개수
	cout << roomNo << '\n';

	// 2. 가장 넓은 방의 넓이
	cout << find_max_in_map_room() << '\n';

	// 3. 하나의 벽을 제거해서 얻을 수 있는 가장 넓은 방의 크기
	set<set<int>> able; // <a, b> a번 방과 b번 방을 합칠 수 있다
	set<int> temp_combi;
	for (i = 0; i < wall.size(); i++) {
		int a = visited[wall[i][0]][wall[i][1]];
		int b = visited[wall[i][2]][wall[i][3]];
		//printf("wall: %d %d %d %d\n", wall[i][0], wall[i][1], wall[i][2], wall[i][3]);
		if (a == b) continue;
		temp_combi.clear();
		temp_combi.insert(a);
		temp_combi.insert(b);
		able.insert(temp_combi);
	}
	int cur_max = -1;
	int cur = 0;
	for (auto it : able) {
		auto it_it = it.begin();
		int one = *it_it;
		int one_o = room[one];
		it_it++;
		int two = *it_it;
		int two_o = room[two];

		int sum_t = one_o + two_o;
		room[one] = sum_t;
		room[two] = sum_t;
		//printf("%d and %d to be %d\n", one, two, sum_t);

		cur = find_max_in_map_room();
		//printf("I found cur %d\n", cur);
		if (cur_max < cur) cur_max = cur;

		room[one] = one_o;
		room[two] = two_o;
	}
	cout << cur_max << '\n';

	return 0;
}
