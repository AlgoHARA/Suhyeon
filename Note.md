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
