/*-----------------------------------------------------------------------------------
* 문제 번호 | [bj2606] 바이러스 (실버3)
* 소요 시간 | 20분
* 체감 난이도 | not that difficult but still not a piece of cake
*
* 접근 방식 |
*	1. 그림부터 그래프로 주어졌고, 경로를 찾는 거니까 dfs/bfs 풀어야 겠다고 생각했다.
*		전에 dfs/bfs 중 생각없이 골랐다가 망했어서 신중히 골라봤다.
*		1에서부터 계속 깊이 파도 될 것 같고,
*		1에서 젤 가까운 컴들, 그다음 가까운 컴들,... 식으로 넓혀나가도 괜찮을 것 같았다.
*		재귀 함수를 구현하기 싫어서 bfs로 구현하기로. (물론 dfs를 스택으로 구현할 수도 있지만)
*	2. 0~n까지의 인덱스를 갖는 n+1 크기의 배열을 만드는데, 각 원소는 vector<int>여야 한다.
*		graph[1]인 vector에는, 1과 연결된 컴들의 숫자가 하나씩 push_back()된다.
*	3. bfs를 구현한다.
*		이전에 연결된 컴에서 뻗어나는 식이므로, 방문하는 컴들의 숫자를 세면 된다.
------------------------------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n; // 컴퓨터의 수 (100 이하)
int m; // 컴퓨터 쌍의 수
vector<int>* graph;
bool* visited;
int cnt = 0;

void bfs(int start) {
	queue<int> q;
	int cur, next;

	q.push(start);
	visited[start] = true;

	while (!q.empty()) {
		cur = q.front();
		q.pop();

		for (vector<int>::iterator i = graph[cur].begin(); i != graph[cur].end(); i++) {
			next = *i;
			if (visited[next] == false) {
				visited[next] = true;
				q.push(next);
				cnt++;
			}
		}
	}

	return;
}

int main() {
	ios::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);

	int i;
	int from, to;

	cin >> n;
	graph = new vector<int>[n + 1];
	visited = new bool[n + 1];
	for (i = 0; i < n + 1; i++) {
		visited[i] = false;
	}

	cin >> m;
	for (i = 0; i < m; i++) {
		cin >> from;
		cin >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	bfs(1);

	cout << cnt;

	delete[] graph;
	delete[] visited;
	return 0;
}
