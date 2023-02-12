#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/*-----------------------------------------------------------------------------------
* 문제 번호 | [bj11060] 점프 점프 (실버2)
* 소요 시간 | GG
* 체감 난이도 | F-WORD I'M AN IDIOT
* 
* 헤맨 이유 |
*	1. '최소값'을 찾으려면, 전부(점프 가능한 모든 경우의 수)를 다 검사해야 한다는 걸 생각지 못했다.
*		점프했을 때의 조합을 찾기 위해 DFS or BFS를 써야겠다고는 생각했다.
*		경로를 구하려고 깊게 팠을 때, maze[]의 마지막 index(n-1)이 나오면 게임끝이라고 섣불리 생각했다.
*		그래서 bfs로 모든 가짓수를 체크해보지 않아도 된다고 생각했다.
*		DFS vs. BFS 잘 알고 쓰자..
*	2. 재귀 함수는 인풋이 커지면 시간/메모리 초과가 날 수 있다는 걸 까먹었다.
*		DFS를 재귀 함수로 표현했는데, 문제의 인풋을 제대로 못 봤다.
* 
* 새로 알게된 점 |
*	1. DFS
*		- 모든 노드를 방문하고자 할 때
*		- 더 간단하다
*		- 유용할 때: 검색 대상 그래프가 크거나, 경로의 특징을 저장해야 할 때
*		- 스택 or 재귀함수로 구현한다
*	2. BFS
*		- 가까운 노드부터 탐색하고자 할 때
*		- 더 빠르다 (검색 속도)
*		- 유용할 때: 검색 대상 그래프가 안 크거나, 최단거리를 구해야 할 때
*		- 큐로 구현한다
* 
* 접근했어야 하는 순서 |
*	1. 최소값을 구해야 하니 어차피 전부 검사해봐야 되고. 무조건 오른쪽으로만 가는 군.
*		가능한 경로들을 찾아야 하니.. 최단 경로 찾기니까. bfs를 써야겠네?
*	2. 근데 bfs는 몇 번 점프했는지(depth)를 저장할 수가 없지.
*		그러니까 현재 위치한 index를 저장할 때, 그때까지의 점프 횟수도 같이 저장해야겠군.
*		bfs는 큐 써야 되니까 큐에 pair로 저장해야겠다.
*	3. 큐, visited[] 배열 만들어서, bfs 구현 뚝딱뚝딱
*		for문 안에서의, cur에서 이동할 next(index)가 n-1보다 큰지 같은지 확인해서
*		크면 그 next보다 큰 index는 의미 없으니, 그 cur에 대한 for문은 그만 돌면 되겠고
*		같으면 경로를 찾은 거니까 지금까지 점프 횟수를 저장하면 되겠네?
*		(답으로 가능한) 점프 횟수들 저장할 자료구조도 필요하겠네, vector 써야지
*	4. bfs로 모든 가능성에 대해 검사했으면 vector 안의 최솟값 출력해야지
------------------------------------------------------------------------------------*/

int n; // [input]
int maze[1000]; // [input]

bool visit[1000];
vector<int> cnt;

void bfs(int start) {
	queue<pair<int, int>> q; // <현재 index, 현재까지 점프 횟수>
	int i;
	int cur; // [index] 현재 고려 중인 index
	int cur_cnt; // [index] 현재까지 점프 횟수
	int next; // maze[]의 index

	q.push(make_pair(0, 0));
	visit[start] = true;

	while (!q.empty()) {
		cur = q.front().first;
		cur_cnt = q.front().second;
		q.pop();

		for (i = 1; i <= maze[cur]; i++) {
			next = cur + i;

			if (next >= n - 1) {
				if (next == n - 1) {
					cnt.push_back(cur_cnt + 1);
					continue;
				}
				else break;
			}

			if (!visit[next]) { // 아직 방문 안 했으면
				q.push(make_pair(next, cur_cnt + 1));
				visit[next] = true;
			}
		}
	}

}

int main() {
	int i;

	cin >> n;

	for (i = 0; i < n; i++) {
		cin >> maze[i];
	}

	if (n == 1) {
		printf("0");
		return 0;
	}

	bfs(0);

	if (cnt.size() == 0) printf("-1");
	else printf("%d", *min_element(cnt.begin(), cnt.end()));
	
	return 0;
}
