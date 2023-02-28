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
