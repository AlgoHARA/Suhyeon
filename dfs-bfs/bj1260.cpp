#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
using namespace std;

/*-----------------------------------------------------------------------------------
* 문제 번호 | [bj1260] DFS와 BFS (실버2)
* 소요 시간 | 1시간
* 체감 난이도 | SO SO
------------------------------------------------------------------------------------*/

// 스택으로 구현
void dfs(int start, vector<vector<int>> list) {
	vector<int> visited(list.size(), 0);
	stack<int> s;

	printf("%d ", start);
	s.push(start);
	visited[start] = 1;

	while (!s.empty()) {
		int cur = s.top();
		s.pop();

		for (int i = 0; i < list[cur].size(); i++) {
			int next = list[cur][i];

			if (visited[next] == 0) {
				visited[next] = 1;
				printf("%d ", next);
				s.push(cur);
				s.push(next);
				break;
			}
		}
	}
}

void bfs(int start, vector<vector<int>> list) {
	vector<bool> visited(list.size(), false);
	queue<int> q;

	printf("%d ", start);
	q.push(start);
	visited[start] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < list[cur].size(); i++) {
			int next = list[cur][i];
			if (!visited[next]) {
				visited[next] = true;
				printf("%d ", next);
				q.push(next);
			}
		}
	}
}


int main() {
	int n, m, v; // input
	int i;
	int tmp1, tmp2;

	cin >> n;
	cin >> m;
	cin >> v;

	vector<vector<int>> list(n + 1);

	// 인접 리스트 생성
	for (i = 0; i < m; i++) {
		cin >> tmp1;
		cin >> tmp2;
		list[tmp1].push_back(tmp2);
		list[tmp2].push_back(tmp1);
	}

	for (i = 1; i <= n; i++) {
		sort(list[i].begin(), list[i].end());

		/* debug
		printf("[%d] : ", i);
		for (auto a = list[i].begin(); a != list[i].end(); a++) {
			printf("%d ", *a);
		}
		printf("\n");
		*/
	}

	dfs(v, list);
	printf("\n");
	bfs(v, list);

	return 0;
}
