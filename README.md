# Suhyeon
수현이의 알고리즘 공부💚   
.   
.   
.   
.   
.   

## 자료형

### 정수형
```C++
char c;
short int si;      // valid
short s;           // preferred
int i;
long int li;       // valid
long l;            // preferred
long long int lli; // valid
long long ll;      // preferred
```

### 부호 있는 정수
- signed : 음수&양수 모두 저장 가능
```C++
signed char c;
signed short s;
signed int i;
signed long l;
signed long long ll;
```

### 부호 없는 정수
- unsigned : 양수만 저장 가능
```C++
unsigned char c;
unsigned short s;
unsigned int i;
unsigned long l;
unsigned long long ll;
```

### 실수
```C++
float f;
double d;
long double ld;
f = 1.23456f; // f가 붙어야 float로 인식
```

## 입출력
1) 동기화를 끊는다면 C++ stream은 C stream과는 다른 독립적인 버퍼를 갖게 된다.  
그래서 출력 순서가 보장되지 않아서, C와 C++의 입출력 방식 혼용하여 쓰는 것이 위험하다.  
2) untie시, cin으로 입력 받기 전 뭔가를 띄우고 싶다면, 매번 수동적으로 cout을 flush 시켜줘야 한다.  
```C++
#include <stdio.h> // 또는 <cstdio>, scanf()/printf() 사용 위해
#include <iostream>
using namespace std;

scanf();
printf();
cin >> temp;
cout << "Hello" << temp << "\n";

ios::sync_with_stdio(false); // 1
cin.tie(NULL); // 2
cout.tie(NULL);
```

## 메모리 초기화
````C++
#include <cstring>

bool visited[10];
memset(visited, false, sizeof(visited));
````

## STL

### Pair
utility 헤더에서 제공하는데, vector/algorithm 헤더 파일에 포함돼서 utility는 include 안 해도 된다.

```C++
#include <stdio.h> // 또는 <cstdio>, scanf()/printf() 사용 위해
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char* argv[]) {
  pair<int, char> p;
  
  scanf("%d %c", &p.first, &p.second);
  
  p.first = 1;
  p.second = 'a';
  
  p = make_pair(3, 'b'); // p가 <3, b>로 바뀐다
  return 0;
}
```

### Vector
크기가 가변적인 배열.
C의 array는 크기가 정적이라 크기 변경 불가.

```C++
#include <vector>

vector<int> a = {1, 2, 3};
vector<int> b(10); // 기본값(0)으로 초기화된 원소 10개의 vector 생성
vector<int> c(5, 2); // 2로 초기화된 원소 5개의 vector 생성
vector<int> d(a); // a를 복사한(얕은 복사) vector d 생성
vector<int>::iterator it;

a.front(); // 첫 번째 원소
a.back(); // 마지막 원소
it = a.begin(); // 첫번째 위치 (반환: iterator)
it = a.end(); // 마지막의 다음 위치 (반환: iterator)
a.push_back(); // 마지막에 데이터 추가
a.pop_back(); // 마지막에서 데이터 제거
a.size(); // 원소의 개수
a.clear(); // 비우기
a.swap(b); // 0으로 초기화된 b와 a를 교체
a.reverse(a.begin(), a.end()); // → string도 reverse가 된다

a.erase(a.begin() + 2); // 2번째 원소 제거, 인자 = iterator
a.erase(a.begin(), a.begin() + 2); // 1번째 ~ 2번째 원소 제거
a.find(a.begin(), a.end(), 2); // a 내에 2가 존재하는지 탐색, iterator 반환(값 못 찾으면 end iterator 반환)
```

### Queue
FIFO, BFS에 매우 유용

```C++
#include <queue>

queue<int> q;
q.push(); // 마지막에 데이터 추가
q.pop(); // 맨앞에서 데이터 제거
q.front(); // 첫 번째 원소
q.back(); // 마지막 원소
q.size(); // 큐의 크기
q.empty(); // 큐가 비어있는가(T/F)
```

### Stack
LIFO

```C++
#include <stack>

stack<int> s;
s.push(); // top에 데이터 추가
s.pop(); // top에서 데이터 제거
s.top(); // top에 있는 원소
s.size(); // 스택의 크기
s.empty(); // 스택이 비어있는가(T/F)
```

### Set
- associative container
- key라 불리는 원소들의 집합
- key값은 중복 허용 X

```C++
#include <set>

set<int> s;
s.insert(1); // 원소 1 삽입, 자동으로 오름차순 정렬
s.begin(); // 첫 번째 원소를 가리키는 iterator 반환
s.end(); // 마지막 원소를 가리키는 iterator 반환
s.find(k); // k를 가리키는 iterator 반환
s.size(); // set의 원소의 개수
s.empty(); // set이 비어있는가
```

### Map
- associative container
- <key, value> 쌍을 원소로 저장
- key값 중복 허용 x
- [] 연산자가 제공되어 key에 해당하는 원소의 value에 바로 접근 가능

```C++
#include <map>

map<char, int> m;
m.insert(make_pair('a', 1)); // key와 value의 pair로 원소를 삽입
m.erase(k); // key값이 k인 원소를 삭제
m.begin(); // 첫 번째 원소를 가리키는 iterator를 반환
m.end(); // 마지막 원소를 가리키는 iterator를 반환
m.find(k); // key값이 k인 원소를 가리키는 iterator를 반환
m.size(); // map의 원소 개수
m.empty(); // map이 비어있는가
m['a'] = 1;
```

### Priority queue
- priority_queue<자료형, 컨테이너, 우선순위> 변수명
  - 컨테이너: 생략 시 default 컨테이너는 vector
  - 우선순위: 생략 시 default 우선순위는 less<자료형>
  - priority_queue<int> q; // 자료형은 정수, 우선순위를 내림차순 정렬(가장 큰 정수가 top에 위치)
  - priority_queue<int, deque<int>> q; // 자료형은 정수, 컨테이너는 덱
```C++
#include <queue>

priority_queue<int, vector<int>, less<int>> q; // 우선순위를 내림차순 정렬 (최대 힙)
priority_queue<int, vector<int>, greater<int>> pq; // 우선순위를 오름차순 정렬 (최소 힙)

q.push(); // q에 원소를 추가
q.pop(); // q에서 우선순위가 가장 높은 원소를 제거 -> 두 번째로 큰 정수가 top에 위치하게 됨
q.top(); // q에서 우선순위가 가장 높은 원소
q.size(); // q의 원소 개수
q.empty(); // q 비어있는가(T/F)
```

### algorithm header
정렬/순열 등을 사용할 때, vector container과 함께 사용되는 경우가 많다
- 최소값 : min
  - min(1,3); // 1
  - vector v에서, min_element(v.begin(), v.end())는 iterator 반환, *min_element로 값 접근
- 최대값
  - max(1, 6); // 6
  - vector v에서, max_element(v.begin(), v.end())는 iterator 반환, *max_element로 값 접근
- 정렬 : sort(iterator-begin, iterator-end, 비교함수)
  - default는 오름차순 정렬
  - 내림차순 정렬하려면, <functional> 헤더의 greater<int>()를 사용해야 한다
  - vector를 오름차순 정렬 : sort(v.begin(), v.end());
  - vector를 내림차순 정렬 : sort(v.begin(), v.end(), greater<int>());
- 순열 : ????_permutation(iterator-begin, iterator-end)
  - next_permutation : 현재 vector(or array)로 표현된 순열의 다음 순열을 구해준다
  - prev_permutation : 현재 vector(or array))로 표현된 순열의 이전 순열을 구해준다
  - 인자로 : container의 시작과 끝 iterator나, array의 주소값을 넣어준다
  - 다음/이전 순열이 존재하면 true, 없으면 false 반환
- 이분 탐색 : binary_search(iterator-begin, iterator-end, 찾으려는 value)
    - 인자로 : container의 시작과 끝 iterator나, array의 주소값을 넣어준다
    - container(또는 배열)에서 찾으려는 value가 존재하면 true, 없으면 false
