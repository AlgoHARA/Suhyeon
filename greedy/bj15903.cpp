#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

/*--------------------------------------------------------------------------------------
* 문제 번호 | [bj15903] 카드 합체 놀이 (실버1)
* 소요 시간 | 50분
* 체감 난이도 | 막 어렵진 않은데 C++/STL 문법을 몰라 오래 걸렸다.
* 헤맨 이유 |
*	  1. C++에서 동적 배열 사용법을 몰랐다 = vector
*	  2. min_element() 함수가 주소값(&)을 반환하는 줄 알았다 (vector<T>::iterator 반환함)
*	  3. 한 줄에 공백으로 구분된 정수를 입력받는 게 익숙지 않다.
*	     for문으로 반복문 돌리면서 'cin >>'으로 입력받으면 된다.
*	     cin은 공백을 포함해 입력받지 못하기 때문.
*	  4. 찾아보며 C++에선 &가 참조자로 쓰이는 것을 알았다. 다만 선언 시 초기화 돼야 함.
----------------------------------------------------------------------------------------*/

int main() {
	int n; // [input] n장의 카드 (2 ~ 1000)
	int m; // [input] 합체 m번 (0 ~ 15*n)
	vector<long> num; // [input] n개의 수 (각 수는 1 ~ 1,000,000)
	
	int i;
	long min1, min2; // [최소값] num vetor 내 최소값
	vector<long>::iterator temp; // [위치] num vector 내 최소값을 가진 곳의 위치(주소)

	long sum = 0; // [output] 각 카드에 적힌 수의 합

	cin >> n;
	cin >> m;

	for (i = 0; i < n; i++) {
		cin >> min1; // 딱히 min1에 입력받는 이유는 없다, 안 쓰는 변수여서 쓰는 것.
		num.push_back(min1);
	}

	for (i = 0; i < m; i++) {
		temp = min_element(num.begin(), num.end()); // min1
		min1 = *temp;
		num.erase(temp); // vector 내 min1을 삭제
		
		temp = min_element(num.begin(), num.end()); // min2
		min2 = *temp;
		num.erase(temp); // vector 내 min2를 삭제

		num.push_back(min1 + min2);
		num.push_back(min1 + min2);
	}

	for (i = 0; i < num.size(); i++) {
		sum += num[i];
	}
	cout << sum;
	
	return 0;
}
