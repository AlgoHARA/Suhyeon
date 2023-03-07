/*------------------------------------------------------------------------
* 문제 번호 | [bj11724] 연결 요소의 개수 (실버2)
* 소요 시간 | 30분
* 평가 | 연결 요소의 정의를 몰라 애먹었지만 bfs 구현은 안 어려웠다.
--------------------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void bfs(
	int start,
	vector<vector<int>> &graph,
	vector<bool> &visited
) {
	queue<int> q;
	int i;

	q.push(start);
	visited[start] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];
			if (!visited[next]) {
				visited[next] = true;
				q.push(next);
			}
		}
	}

	return;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int n; // 정점 개수, 1 ~ 1,000
	int m; // 간선 개수, 0 ~ n*(n-1)/2
	cin >> n;
	cin >> m;

	if (n == 1) {
		cout << '1';
		return 0;
	}

	if (m == 0) {
		cout << n;
		return 0;
	}

	vector<vector<int>> graph(n + 1);
	vector<bool> visited(graph.size(), false);
	int cnt = 0;

	int i, l, r;
	for (i = 0; i < m; i++) {
		cin >> l >> r;
		graph[l].push_back(r);
		graph[r].push_back(l);
	}

	for (i = 1; i <= n; i++) {
		if (!visited[i]) {
			bfs(i, graph, visited);
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}
