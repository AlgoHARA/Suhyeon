# EVERYDAY I LEARNED...
.
.
.
## 순열 구하기
- 순열 : 순서가 존재하는 배열 (123, 132, 213, ...)
- 조합 : 순서가 없는 배열 (123 == 132 == 213 == ...; 다 같은 것)
- n개의 숫자로 만들 수 있는 모든 순열을 구하고 싶다면 next_permutation()을 활용하면 된다

#### 주석 없는 버전
```C++
#include <vector>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;

int main() {
    vector<char> ch = { '4', '1', '3', '0' };
    
    sort(ch.begin(), ch.end());

    do {
        string temp = "";
        for (int i = 0; i < ch.size(); i++) {
            temp += ch[i];
        }
    } while (next_permutation(ch.begin(), ch.end()));

    return 0;
}
```

#### 주석 있는 버전
```C++
#include <vector>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;

int main() {
    vector<char> ch = { '4', '1', '3', '0' };
    int cnt = 1;

    // next_permutation()을 사용하려면 배열이 오름차순 정렬돼있어야 함
    sort(ch.begin(), ch.end()); // {0, 1, 3, 4}

    do {
        string temp = "";
        for (int i = 0; i < ch.size(); i++) {
            temp += ch[i];
            printf("[cnt = %d] %s\n", cnt, temp.c_str());
        }
        printf("<end of while cnt = %d>\n", cnt++);
    } while (next_permutation(ch.begin(), ch.end()));

    return 0;
}
```

#### 출력 결과
<img src="https://user-images.githubusercontent.com/66207354/219849314-f0f24ea5-73f8-4caf-8d13-82ed94153727.png" width="60%" height="">

## 소수 구하기 : 에라토스테네스의 체
- 2~n까지의 수 중에 소수를 판별하기 위한 알고리즘
- 소수를 찾으면 그 수의 배수를 모두 지워나가는 방식
```C++
bool isPrime(int n) {
    if (n < 2) return false;

    // sqrt(n) : n에 루트를 씌운 수 <- #include <math.h>
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }

    return true;
}
```

## DFS (Depth-First Search)
스택 이용 or 재귀 함수 로 구현할 수 있다

### 문제 추천
- [여행경로](https://school.programmers.co.kr/learn/courses/30/lessons/43164?language=cpp) : 기본 DFS/백트래킹 기초
- [치즈](https://www.acmicpc.net/problem/2636) : [idea] 외부 공기 vs 내부 공기 구분, 외부 공기와 n개 이상 맞닿은 곳이 테두리
- [아이템 줍기](https://school.programmers.co.kr/learn/courses/30/lessons/87694?language=cpp)
- [idea] 좌표 2배로 뻥튀기 해서 bfs

### 1. 재귀

#### 인접 리스트
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

#### 2차원 배열 좌표 (대각선 기준 대칭인 인접 그래프랑은 다름)
[영역 구하기](https://www.acmicpc.net/problem/2583) 문제풀이 참고 ([출처](https://code-kh-studio.tistory.com/27))
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
        
        if (ny < 0 || nx < 0 || ny > 99 || nx > 99) continue;
        if (arr[ny][nx] == 0 || visited[ny][nx]) continue;
        
        visited[ny][nx] = true;
        cnt += dfs(ny, nx);
    }
    
    return cnt;
}
````

#### dfs + 재귀 -> 순열 구하기
[1 2 3]과 [1 3 2]를 다르게 취급 ([출처](https://paris-in-the-rain.tistory.com/35))
````C++
vector<int> arr;
vector<int> result;
int visited[MAX];

void print_permu() {
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << ' ';
    }
    cout << endl;
}

void dfs_permu(int cnt) {
    if (cnt == 3) { // 찾으려는 개수
        print_permu();
        return;
    }
    
    for (int i = 0; i < MAX; i++) {
        if (visited[i]) continue;
        visited[i] = true;
        result.push_back(arr[i]);
        dfs_permu(cnt + 1);
        
        result.pop_back();
        visited[i] = false;
    }
}

int main() {
    dfs_permu(0);
    return 0;
}
````

#### dfs + 재귀 -> 조합 구하기
[1 2 3]과 [1 3 2]를 같게 취급 ([출처](https://paris-in-the-rain.tistory.com/35))
````C++
vector<int> arr;
int visited[MAX];

// visited[]에서 true인 index의 arr에서의 값만 출력
void print_combi() {
    for (int i = 0; i < MAX; i++) {
        if (visited[i] = true) {
            cout << arr[i] << ' ';
        }
    }
    cout << endl;
}

void dfs_combi(int idx, int cnt) {
    if (cnt == 3) { // 찾으려는 개수
        print_combi();
        return;
    }
    
    for (int i = idx; i < MAX; i++) {
        if (visited[i]) continue;
        visited[i] = true;
        dfs_combi(i, cnt + 1);
        visited[i] = false;
    }
}

int main() {
    dfs_combi(0, 0);
    return 0;
}
````

### 2. 스택

#### 인접 리스트
[전력망을 둘로 나누기](https://school.programmers.co.kr/learn/courses/30/lessons/86971?language=cpp)
문제 풀이<br>
input[1] = {2, 3} 이라면 1번 노드가 2번, 3번 노드와 연결돼있단 뜻. input[2]에도 1이 있겠지.

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


## BFS
큐를 이용하여 구현

#### 인접 리스트
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

## DP (Dynamic Programming)
- idea
    - 피보나치 수열, 점화식
    - 내 위치(i)까지 올 수 있는 최댓값 (바로 전 위치의 값만 참조)
    - 배열의 경우 뒤에서부터 접근해보자?
- 문제 유형
    - DFS/BFS로 풀 수는 있지만 경우의 수가 너무 많은 문제
    - 경우의 수들에 중복적인 연산이 많은 문제
        - '이미 최댓값이 될 수 없는 조합들도 계속 연산을 해서 시간을 낭비하고 있네?'
        - 이걸 줄이고자, 각 위치까지 올 수 있는 최적의 값만 남겨놓고 나머지 조합은 다 버린다
        - 어차피 안 될 조합들은 미리미리 버려서 가장 좋은 조합들끼리만 경쟁을 시키고
        - 그중 가장 좋은 조합을 추리는 식으로 반복해서 문제를 풀기
- DP 없던 시절엔 최단 경로 찾거나 최고 점수 만들 때 모든 조합을 다 만들어보는 수밖에 없었다

## vector에서 erase로 요소 지우기
erase()는 해당 위치의 데이터를 지우고 그 뒤의 데이터들을 남은 자리만큼 앞으로 이동시킨다.
그래서 vector를 순차적으로 탐색해서 원하는 위치에 erase를 사용할 땐 주의가 필요하다.
#### vec.size()개의 원소에 대해 for문 돌릴 때
erase()가 실행되면 배열의 뒷 요소들이 자동으로 한 칸씩 당겨지므로
erase()가 실행되지 않은 경우에만 인덱스를 증가시키는 식으로 설계해야 한다.
```C++
for (vector<int>::size_type i = 0; i < vec.size(); ) {
    if (삭제의 조건문) {
        vec.erase(vec.begin() + i);
    }
    else {
        i++;
    }
}
```
#### iterator로 for문 돌릴 때
해당 iterator의 요소를 삭제하면 그 iterator는 무효화가 된다. it 값이 사라져버린다.
다행히도 erase()는 삭제에 성공할 시, 삭제한 요소의 바로 다음 iterator를 반환하므로
이 iterator을 it에 그대로 대입하면 된다.
```C++
for (it = vec.begin(); it != vec.end(); ) {
    if (삭제의 조건문) {
        it = vec.erase(it);
    }
    else {
        it++;
    }
}
```

## char <-> int
#### ASCII Code (아스키 코드)
<img src="https://user-images.githubusercontent.com/66207354/222041073-32d33e2c-ed57-4284-886b-89593d8fe6ea.png" width="60%" height="">
'0' = 48 / 'A' = 65 / 'a' = 97    
