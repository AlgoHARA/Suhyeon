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

## DFS
- 스택 이용 or 재귀 함수 로 구현할 수 있다
#### 스택을 이용한 방법
- 프로그래머스 '전력망을 둘로 나누기' 문제 풀이
- 인접 리스트를 이용한 방식: input[1] = {2, 3} 이라면 1번 노드가 2번, 3번 노드와 연결돼있단 뜻. input[2]에도 1이 있겠지.
```C++
int dfs(
    int start, // 탐색을 시작할 root node
    vector<vector<int>> input) // 노드들 간의 연결 정보가 저장된 2차원 vector
{
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
