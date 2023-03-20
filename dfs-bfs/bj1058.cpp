#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int n; // 1~50
bool graph[50][50] = { false };
bool visited[50] = { false };

int bfs(int start) {
	int i;
	queue<int> q;
	int cnt = 0;

	for (i = 0; i < n; i++) {
		if (graph[start][i]) { // start와 i가 연결돼있다면
			visited[i] = true;
			cnt++;
			q.push(i);
		}
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (i = 0; i < n; i++) {
			if (graph[cur][i] && !visited[i]) {
				visited[i] = true;
				cnt++;
			}
		}
	}
	
	return cnt;
}

int main() {
	int i, j;
	char c;
	int cnt, max = -1;
	cin >> n;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cin >> c;
			if (c == 'N') graph[i][j] = false;
			else if (c == 'Y') graph[i][j] = true;
		}
	}

	for (i = 0; i < n; i++) {
		memset(visited, false, sizeof(visited));
		visited[i] = true;

		cnt = bfs(i);
		//printf("%d is connected with %d friends\n", i, cnt);

		if (cnt > max) max = cnt;
	}

	printf("%d\n", max);
	return 0;
}
