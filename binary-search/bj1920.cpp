/*-----------------------------------------------------------------------------------
* 문제 번호 | [bj1920] 수 찾기 (실버4)
* 소요 시간 | I couldn't make it
* 체감 난이도 | god bless googling
*
* 새로이 알게 된 것 |
*	1. ios::sync_with_stdio(false);
*		printf, scanf에 비해 cin, cout은 굉장히 느리다.
*		ios::sync_with_stdio()는 c의 stdio와 cpp의 iostream을 동기화해준다.
*		이때 stdio와 iostream의 버퍼를 모두 사용하기 때문에 딜레이가 발생한다.
*
*		위 코드를 작성하면 동기화를 비활성화한다.
*		이로 인해 c++만의 독립적인 버퍼가 생성되어 c의 버퍼와 병행하여 사용할 수 없게 된다.
*		그래서 printf, scanf를 쓸 수 없다.
*		하지만 사용하는 버퍼의 수가 줄었으므로 실행 속도는 빨라진다.
*
*	2. cin.tie(NULL); cout.tie(NULL);
*		기본적으로 cin과 cout은 묶여있고, 묶여있는 스트림들은
*		한 스트림이 다른 스트림에서 각 IO 작업을 진행하기 전에 자동으로 버퍼를 비워줌을 보장한다.
*		그런데 cin.tie(NULL)로 cin과 cout의 tie를 풀어주면
*		cout 뒤에 바로 cin이 왔을 때, 출력이 되지도 않았는데 먼저 입력을 받는 경우가 발생할 수 있다.
*		cout이 버퍼에 추가되고 바로 비워지지 않기 때문이다.
*		그래서 이런 상황에서 cin.tie(NULL)을 추가한 후 출력 후 입력을 받고 싶다면
*		cout으로 출력을 할 때 버퍼를 비워줘야 한다.
*
*	3. endl
*		endl은 개행 문자 출력과 함께 출력 버퍼를 비우는 역할까지 같이 해서 딜레이가 발생한다.
*		따라서 알고리즘 풀 때는 실행 속도를 높이기 위해 C 스타일의 '\n'으로 개행을 하자.
*
*	4. cin으로 입력 받고 배열의 어떤 위치에 넣어줄 때.
*		for문 돌리면서 cin >> arr[i] 식으로 입력 받으면 제대로 데이터 저장이 안 된다.
*		왜 안 되는지는 잘 모르겠다..
*		cin >> temp; arr[i] = temp; 식으로 입력 받자.
*
*	5. 이진탐색 구현
*		기본적으로 정렬이 돼있어야 한다.
		또 int low, mid, high가 필요하다. (모두 배열에서의 index 값을 나타낸다)
*		low와 high 값을 설정하고, mid를 둘의 가운데 값으로 잡는다.
*		그렇게 계속 가운데 값(arr[mid])이 찾으려는 값보다 큰지 작은지 같은지 확인하며
*		low나 high를 이동한다, as long as low <= high
*
*	6. sort() 사용법
*		vector<int> v;
*		sort(v.begin(), v.end());
*		뿐만 아니라 배열에 대해서도 주소값을 인자로 주면서 sort()를 쓸 수 있다.
*		int[10] arr;
*		sort(arr, arr + 10); 이렇게.
*
*	7. 함수에 인자로 배열 넘겨주는 법
*		int[10] arr;
*		함수 정의 부분: void fun(int arr[]);
*		함수 호출 부분: fun(arr)
------------------------------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[100001];
int n, m;

void find(int goal) {
	int mid;
	int low = 0;
	int high = n - 1;

	while (low <= high) {
		mid = (low + high) / 2;

		if (arr[mid] == goal) {
			cout << "1\n";
			return;
		}
		else if (arr[mid] > goal) { // pos보다 좌측에서 goal을 찾아야 한다
			high = mid - 1;
		}
		else { // pos보다 우측에서 goal을 찾아야 한다
			low = mid + 1;
		}
	}

	cout << "0\n";
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int i;
	int goal;

	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> goal;
		arr[i] = goal;
	}
	sort(arr, arr + n); // 오름차순 정렬

	cin >> m;

	for (i = 0; i < m; i++) {
		cin >> goal;
		find(goal);
	}

	return 0;
}
