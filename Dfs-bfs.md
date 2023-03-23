# DFS/BFS 개념 정리
### 관련 문제
- [여행경로](https://school.programmers.co.kr/learn/courses/30/lessons/43164?language=cpp) : 기초 DFS/백트래킹
- [치즈](https://www.acmicpc.net/problem/2636)
- [아이템 줍기](https://school.programmers.co.kr/learn/courses/30/lessons/87694?language=cpp)

### 문제 풀이 idea
- 좌표 2배로 뻥튀기 해서 bfs
- 외부 공기 vs 내부 공기 구분, 외부 공기와 n개 이상 맞닿은 곳이 테두리

## DFS (Depth-First Search)
- 재귀적으로 구현 or 스택 이용
- BFS처럼 visited[] 배열이 필요하다

### 1. 재귀 + (graph) adjacency list
- input[1] = {2, 3} 이라면 1번 노드가 2번, 3번 노드와 연결돼있단 뜻. input[2]에도 1이 있겠지.
````C++
bool visited[9]; // 0~8번 노드가 방문됐는지 표시
vector<int> graph[9]; // 0~8번 노드가 vector<int>를 가진다, 인접 리스트

// start : 탐색을 시작할 root node
void dfs(int start) {
    visited[start] = true;
    
    for (int i = 0; i < graph[start].size(); i++) {
        int next = v[start][i];
        
        if (!check[next]) { // 방문하지 않았다면 dfs() 호출
            dfs(next);
        }
    }
}
````

### 2. 재귀 + (지도) 2차원 배열 좌표
- 대각선 기준 대칭인 인접 그래프랑은 다르다
- [영역 구하기](https://www.acmicpc.net/problem/2583) 문제풀이 참고 ([출처](https://code-kh-studio.tistory.com/27))
````C++
int dy[4] = {0, 0, 1, -1}; // [행] 동서남북
int dx[4] = {1, -1, 0, 0}; // [열] 동서남북
int arr[100][100] = { 0 };
bool visited[100][100] = { false };

int dfs(int y, int x) {
    int cnt = 1;
    
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = y + dx[i];
        
        if (ny < 0 || nx < 0 || ny >= 100 || nx >= 100) continue;
        if (arr[ny][nx] == 0 || visited[ny][nx]) continue;
        
        visited[ny][nx] = true;
        cnt += dfs(ny, nx);
    }
    
    return cnt;
}
````

### 3. 재귀 + (graph) adjacency matrix
- [2-친구](https://www.acmicpc.net/problem/1058)

### 4. dfs + 재귀 → 순열 구하기
- [1 2 3]과 [1 3 2]를 다르게 취급 ([출처](https://paris-in-the-rain.tistory.com/35))
- [차이] 순열 vs 조합
	- result 배열
		- 수열 구할 땐 순서가 중요하니 visited[] 외에<br>
		원소를 push_back, pop_back할 vector<int> result가 필요하다
		- 조합 구할 땐 순서가 안 중요하니 visited[]에 t/f 표시하는 것으로 충분
	- for문에서 i가 0부터 도는지, start부터 도는지
		- 수열 구할 땐 순서가 중요하니 무조건 0번째 원소부터 고려
		- 조합 구할 땐 중복 생기면 안 되니 start번째 원소부터 고려
- [차이] 원소 n개 vs 가능한 모든
	- 원소 n개 : dfs()에 인자로 주어진 cnt가 n에 도달하면 그때마다 결과 출력
	- 가능한 모든 : 위와 같은 조건 필요 X, 새 원소가 추가될 때마다 결과 출력

#### 4-1. 2개의 원소를 갖는 수열 구하기
- [차이를 최대로](https://www.acmicpc.net/problem/10819)
````C++
int n = 3; // v의 원소의 개수
vector<int> v = { 0, 1, 2 };
vector<int> result;
bool visited[3] = { false };

void print_permu() {
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << ' ';
	}
	cout << "\n";
	return;
}

void dfs_permu(int cnt) {
	if (cnt == 2) { // 찾으려는 개수
		print_permu();
		return;
	}

	for (int i = 0; i < n; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		result.push_back(v[i]);
		dfs_permu(cnt + 1);

		result.pop_back();
		visited[i] = false;
	}

	return;
}

int main() {
	dfs_permu(0);
	return 0;
}

/*
0 1
0 2
1 0
1 2
2 0
2 1
*/
````

#### 4-2. 가능한 모든 수열 구하기
````C++
int n = 3; // v의 원소의 개수
vector<int> v = { 0, 1, 2 };
vector<int> result;
bool visited[3] = { false };

void print_permu() {
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << ' ';
	}
	cout << "\n";
	return;
}

void dfs_permu(int cnt) {

	for (int i = 0; i < n; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		result.push_back(v[i]);
		print_permu();
		dfs_permu(cnt + 1);

		result.pop_back();
		visited[i] = false;
	}

	return;
}

int main() {
	dfs_permu(0);
	return 0;
}

/*
0
0 1
0 1 2
0 2
0 2 1
1
1 0
1 0 2
1 2
1 2 0
2
2 0
2 0 1
2 1
2 1 0
*/
````

### 5. dfs + 재귀 → 조합 구하기
- [1 2 3]과 [1 3 2]를 같게 취급 ([출처](https://paris-in-the-rain.tistory.com/35))<br>
- v의 [0&#126;마지막번째]에서, [start&#126;마지막번째]의 원소를 조합의 cnt+1번째 원소로 넣어보겠다.<br>
    (start번째 앞의 원소들은 쳐다도 안 보겠다! 이미 고려했으니까..)<br>
- 순서대로 visited[i]를 true로 표시하고, 원하는 원소 개수의 조합을 찾으면<br>
    print_combi()에서 visited[]에서 true인 원소만 출력한다.
    
#### 5-1. 3개의 원소를 갖는 조합 만들기
````C++
int n = 4; // v의 원소의 개수
vector<int> v = { 0, 1, 2, 3 };
bool visited[4] = { false };

void print_combi() {
	for (int i = 0; i < n; i++) {
		if (visited[i]) {
			cout << v[i] << ' ';
		}
	}
	cout << "\n";
	return;
}

// (cnt+1)개의 원소를 갖는 조합을 만드는데, v[i]를 그 조합의 (cnt+1)번째 원소로 한다.
void dfs_combi(int start, int cnt) {
	if (cnt == 3) { // 찾으려는 개수
		print_combi();
		return;
	}

	for (int i = start; i < n; i++) {
		if (visited[i]) continue;
		visited[i] = true; // 이로써 (cnt+1)개의 원소를 가진 조합이 생겼다
		dfs_combi(i, cnt + 1);
		visited[i] = false; // 조합의 (cnt+1)번째 원소가 v[i]였는데 이를 뺐다
	}

	return;
}

int main() {
	dfs_combi(0, 0); // v[0]이 조합의 1번째 원소가 되는 조합을 구하러 가볼까~?
	return 0;
}

/*
0 1 2
0 1 3
0 2 3
1 2 3
*/
````

#### 5-2. 가능한 모든 조합 만들기
- [신맛/쓴맛 조합 문제](https://www.acmicpc.net/problem/2961)
- 위 코드와의 차이점 : 'print_combi()를 언제 하는가'
- next_permutation() 쓸 때랑 결과가 비슷한 듯!

````C++
int n = 4; // v의 원소의 개수
vector<int> v = { 0, 1, 2, 3 };
bool visited[4] = { false };

void print_combi() {
	for (int i = 0; i < n; i++) {
		if (visited[i]) {
			cout << v[i] << ' ';
		}
	}
	cout << '\n';
	return;
}

void dfs_combi(int start) {
	for (int i = start; i < n; i++) {
		if (visited[i]) continue;
		visited[i] = true; // 이로써 (cnt+1)개의 원소를 가진 조합이 생겼다
		printf("[start = %d, i = %d] ", start, i);
		print_combi();

		dfs_combi(i);
		visited[i] = false; // 조합의 (cnt+1)번째 원소가 v[i]였는데 이를 뺐다
	}

	return;
}

int main() {
	dfs_combi(0);
	return 0;
}

/*
[start = 0, i = 0] 0
[start = 0, i = 1] 0 1
[start = 1, i = 2] 0 1 2
[start = 2, i = 3] 0 1 2 3
[start = 1, i = 3] 0 1 3
[start = 0, i = 2] 0 2
[start = 2, i = 3] 0 2 3
[start = 0, i = 3] 0 3
[start = 0, i = 1] 1
[start = 1, i = 2] 1 2
[start = 2, i = 3] 1 2 3
[start = 1, i = 3] 1 3
[start = 0, i = 2] 2
[start = 2, i = 3] 2 3
[start = 0, i = 3] 3
*/
````

### 6. 스택 + 인접 리스트
- [전력망을 둘로 나누기](https://school.programmers.co.kr/learn/courses/30/lessons/86971?language=cpp) 풀이<br>

##### 주석 없는 버전
```C++
vector<vector<int>> input;

int dfs(int start) {
    int size = input.size();
    vector<bool> visited(size, false);
    stack<int> s;
    int cnt = 1; // 일반 dfs는 없어도 됨
    
    s.push(start);
    visited[start] = true;
    
    while (!s.empty()) {
        int cur = s.top();
        s.pop();
        
        for (int a = 0; a < input[cur].size(); a++) {
            int next = input[cur][a];
            
            if (!visited[next]) {
                //printf("%d ", next);
                visited[next] = true;
                cnt++;
                
                s.push(cur);
                s.push(next);
                break;
            }
        }
    }
    
    return cnt;
}
```

##### 주석 있는 버전
```C++
vector<vector<int>> input; // 노드들 간의 연결 정보가 저장된 2차원 vector

// start : 탐색을 시작할 root node
int dfs(int start) {

    int size = input.size(); // 몇 번째 노드까지 있는가 (1~9번 노드가 있으면 10개의 원소를 갖는 input을 선언했다)
    vector<bool> visited(size, false); // 방문 여부를 체크
    stack<int> s;
    int cnt = 1; // 일반 dfs는 없어도 됨, start와 연결된 노드가 몇 개인지 센다, 일단 start가 하나 있으므로 1부터 시작
    
    s.push(start);
    visited[start] = true;
    
    while (!s.empty()) {
        
        // 스택에서 하나를 꺼낸다
        int cur = s.top();
        s.pop();
        
        // cur과 인접한 노드들 중
        for (int a = 0; a < input[cur].size(); a++) {
            
            int next = input[cur][a];
            
            // next를 아직 방문 안 했다면 방문하자
            if (!visited[next]) { // 'next != b &&' 같은 조건을 추가하면 cur과 b가 연결된 경우는 제외하고 탐색할 수 있다
                //printf("%d ", next); // 방문 순서를 알 수 있다
                visited[next] = true;
                cnt++;
                
                // cur을 pop()했었기 때문에 cur도 넣어줘야 한다
                s.push(cur);
                s.push(next);
                break;
            }
        }
    }
    
    return cnt;
}
```

# BFS (Breath-First Search)
큐를 이용

### 1. 큐 + (graph) adjacency list
````C++
bool visited[9]; // 0~8번 노드가 방문됐는지 표시
vector<int> graph[9]; // 0~8번 노드가 vector<int>를 가진다, 인접 리스트
queue<int> q;

void bfs(int start) {
    q.push(start);
    visited[start] = true;
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i];
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}
````
