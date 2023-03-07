/*-----------------------------------------------------------------------------------
* 문제 번호 | [bj11725] 트리의 부모 찾기 (실버2)
* 소요 시간 | 1시간
* 체감 난이도 | NOT HARD BUT NOT EASY
------------------------------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

map<int, vector<int>> tree;
int* ans;
bool* visited;

void bfs(int start) {
	queue<int> q;

	q.push(start);
	visited[start] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (auto i = tree[cur].begin(); i != tree[cur].end(); i++) {
			int next = *i;
			if (!visited[next]) {
				visited[next] = true;
				q.push(next);
				ans[next] = cur; // next의 부모인 cur을 ans[next]에 넣어준다
			}
		}
	}

	return;
}

int main() {
	int n, i;
	int l, r;

	cin >> n;

	visited = new bool[n + 1];
	ans = new int[n + 1];

	for (i = 1; i <= n - 1; i++) {
		cin >> l;
		cin >> r;

		tree[l].push_back(r);
		tree[r].push_back(l);

		// 초기화
		visited[i] = false;
		ans[i] = 0;
	}

	visited[i] = false;
	ans[i] = 0;

	// bfs
	bfs(1);

	for (i = 2; i < n + 1; i++) {
		cout << ans[i] << "\n";
	}

	delete[] visited;
	delete[] ans;
	return 0;
}
