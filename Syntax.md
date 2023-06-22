# C++ 기초 문법

## 목차
1. [메모리 초기화](#1-메모리-초기화)
2. [메모리 복사](#2-메모리-복사)
3. [정수와 문자열](#3-정수와-문자열)
4. [STL (Standard Template Library)](#4-stl-standard-template-library)
<br> 4-1. [Pair](#4-1-pair) / 4-2. [Vector](#4-2-vector) / 4-3. [Queue](#4-3-queue) / 4-4. [Stack](#4-4-stack)
<br> 4-5. [Set](#4-5-set) / 4-6. [Map](#4-6-map) / 4-7. [Priority Queue](#4-7-priority-queue)
6. [Algorithm Header](#5-algorithm-header)
7. [자료형](#6-자료형)
8. [입출력](#7-입출력)
---

## 1. 메모리 초기화
````C++
#include <cstring>

bool visited[10];
memset(visited, false, sizeof(visited)); // memset()은 0으로만 초기화 가능

// 0이 아닌 다른 값으로 초기화하고 싶다면?
int arr[2][3];
fill(&arr[0][0], &arr[1][2], 5); // (첫 위치, 어느 인덱스까지, 초기값)
````

***

## 2. 메모리 복사
````C++
vector<int> from;
vector<int> to;

copy(from.begin(), from.end(), to.begin());
````

***

## 3. 정수와 문자열
````C++
#include <string>

string a = "0123456789abcdefg";
cout << a.substr(10); // abcdefg
cout << a.substr(0, 3); // 012 (0번째부터 3개)

int b = 127;
string c = "127";
char d[10] = "2023";
printf("%s", c.c_str()); // string을 printf() + %s 로 출력하려면 .c_str()을 붙여줘야 한다

to_string(b); // int → string 변환
stoi(c); // string → int 변환
atoi(d); // char* -> int 변환
d[0] + '0'; // int → char 변환 : int를 char로 바꾸려면 '0'을 더한다
d[0] - '0'; // char → int 변환 : char를 int로 바꾸려면 '0'을 빼준다
````

***

## 4. STL (Standard Template Library)

### 4-1. Pair
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

### 4-2. Vector
크기가 가변적인 배열<br>
C의 array는 크기가 정적이라 크기 변경 불가<br>

```C++
#include <vector>

// 초기화, 선언
vector<int> a = {1, 2, 3};
vector<int> b(10); // 기본값(0)으로 초기화된 원소 10개의 vector 생성
vector<int> c(5, 2); // 2로 초기화된 원소 5개의 vector 생성
vector<int> d(a); // a를 복사한(얕은 복사) vector d 생성
vector<int>::iterator it;

// 삽입 연산
a.push_back(1); // 마지막에 1 추가
a.insert(a.begin(), 1); // 맨 앞에 1 삽입
a.insert(a.begin() + 2, 1); // idx 2 위치에 1 삽입

// 삭제 연산
a.pop_back(); // 마지막에서 데이터 제거
a.erase(a.begin() + 2); // a[2]를 지운다 (인자: iterator)
a.erase(a.begin(), a.begin() + 2); // [first,last) 제거, last에 있던 원소를 가리키는 iterator 반환
a.clear(); // 모든 값 삭제

// 정보 가져오기
a.size(); // 원소의 개수
a.front(); // 첫 번째 원소
a.back(); // 마지막 원소
it = a.begin(); // 첫번째 위치 (반환: iterator)
it = a.end(); // 마지막의 다음 위치 (반환: iterator)

// 값 변경
a.swap(b); // vector b(위에서 0으로 초기화됐음)와 a를 교체
a.reverse(a.begin(), a.end()); // 참고: string도 reverse가 된다

find(a.begin(), a.end(), 2); // a 내에 2가 존재하는지 탐색, iterator 반환(값 못 찾으면 end iterator 반환)
```

#### 2차원 vector 복사
````C++
vector<vector<int>> from;
from.assign(10, vector<int>(11, 0);

vector<vector<int>> to;
to.assign(from.size(), vector<int>(from[0].size()));
copy(from.begin(), from.end(), to.begin());
````

#### 2차원 배열 복사
````C++
int from[n][m];
int to[n][m];
copy(&from[0][0], &from[0][0] + n * m, &to[0][0]);
````

### 4-3. Queue
FIFO<br>
BFS에 매우 유용

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

### 4-4. Stack
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

### 4-5. Set
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

### 4-6. Map
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

if (m.find(k) != m.end()) {} // 'm 안에 k라는 key가 존재하면'
```

### 4-7. Priority Queue
- 선언 format : priority_queue<자료형, 컨테이너, 우선순위> 변수명
- 컨테이너 : 디폴트 컨테이너는 vector
- 우선순위 : 디폴트 우선순위는 less<자료형> → max heap(우선순위 내림차순 정렬)
- sort에서 less<> 쓰면 오름차순, greater<> 쓰면 내림차순 정렬인데, pq에선 반대군!
- (자동 정렬이 된다는 공통점 아니더라도) pq랑 map이랑 같이 쓰면 유용할 때도 있나봐-
```C++
#include <queue>

priority_queue<int, vector<int>, less<int>> pq_d; // 우선순위 내림차순 정렬 (최대 힙 - 최대값이 최상단에 위치)
priority_queue<int, vector<int>, greater<int>> pq_u; // 우선순위 오름차순 정렬 (최소 힙)
  
priority_queue<int> pq_v; // 자료형은 정수, 우선순위 내림차순 정렬
priority_queue<int, deque<int>> pq_d; // 자료형은 정수, 컨테이너는 덱

q.push(); // q에 원소를 추가
q.pop(); // q에서 우선순위가 가장 높은 원소를 제거 -> 두 번째로 큰 정수가 top에 위치하게 됨
q.top(); // q에서 우선순위가 가장 높은 원소
q.size(); // q의 원소 개수
q.empty(); // q 비어있는가(T/F)
```
#### 우선순위를 customize
```C++
#include <queue>
  
struct compare {
  bool operator() (pair<int, int>& a, pair<int, int>& b) {
    return a.second > b.second;
  }
}

// 1번째 값 기준, 오름차순 정렬
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq_1;
// 2번째 값 기준, 오름차순 정렬
priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq_2;
```

## 5. Algorithm Header
정렬/순열 등을 사용할 때, vector container과 함께 사용되는 경우가 많다

### 최소값 min
````C++
min(1, 3); // 1
min_element(v.begin(), v.end()); // iterator 반환, *min_element로 값 접근
````

### 최대값 max
````C++
max(1, 6); // 6
max_element(v.begin(), v.end()); // iterator 반환, *max_element로 값 접근
````

### 정렬 sort
- sort(iterator-begin, iterator-end, 비교함수)
- default : 오름차순 정렬
- 내림차순 정렬 : <functional> 헤더의 greater<int>() 사용
````C++
#include <functional>

// 1. 기본 사용법
vector<int> v1;
sort(v1.begin(), v1.end()); // default : 오름차순 정렬
sort(v1.begin(), v1.end(), greater<int>()); // 내림차순 정렬

// 2. 비교 함수 재정의
bool compare(const pair<int, int>& a, const pair<int, int>& b) {
  if (a.first == b.first) // first가 같다면
    return a.second < b.second; // second로 오름차순
  return a.first < b.first; // first가 더 작은 게 앞으로 -> 오름차순
}

vector<pair<int, int>> v2;
sort(v2.begin(), v2.end(), compare);

// 3. 람다 표현식(익명 함수) 사용
// 람다 표현식 기본 format : [캡처절] (매개변수) -> 반환형식 { 함수내용 }
vecotr<int> v3;
sort(v3.begin(), v3.end(), [](int& a, int& b) {return a > b;});
````

### 순열 permutation
```` C++
vector<int> v;
next_permutation(v.begin(), v.end());
prev_permutation(v.begin(), v.end());
````
- 인자로: container의 begin/end iterator나, array의 주소값을 넣어준다
- 다음/이전 순열이 존재하면 true, 없으면 false 반환
- 용례는 NOTE.MD 참고!

### 이분 탐색 binary_search
````C++
vector<int> v;
binary_search(v.begin(), v.end(), 3); // 값 '3'이 존재하는지 찾는다
````
- 인자로: container의 begin/end iterator나, array의 주소값을 넣어준다
- container(또는 배열)에서 찾으려는 value가 존재하면 true, 없으면 false 반환

### 중복 원소 찾기 unique
````C++
vector<int> v;
// 중복 원소를 찾아 (중복을) 전부 제거하기
sort(v.begin(), v.end());
v.erase(unique(v.begin(), v.end()), v.end());
````
- 중복 원소를 찾거나, 찾아서 제거할 때 사용된다
- unique()는 연속된 중복 원소를 vector의 제일 뒷부분으로, 쓰레기값으로 보내버린다.
- unique()는 vector에서 쓰레기값의 첫 번째 인덱스를 반환
- 따라서 반드시 sort()로 정렬 후 unique()를 사용해야 한다

## 6. 자료형

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

***

## 7. 입출력
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

***
