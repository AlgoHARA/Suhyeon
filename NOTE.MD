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

## ??
