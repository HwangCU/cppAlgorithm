# 코테 준비하면서 배운 알고리즘

## 1. Direct Address Table (D.A.T.)

데이터를 주소(인덱스)로 직접 입력하는 기법이다

```c++
char A[10] = {"ABCDEAA"};
int result[100] = {0};
for(int i;i<strlen(A);i++){
    result[A[i]]++;
}

cout<<result
//result[65]=3 A
//result[66]=1 B
//result[67]=1 C
//result[68]=1 D
//result[69]=1 E
```

- 대표적으로 가장 많은 갯수 구하기
- 패턴구하기 

## 2.  Direct Coding

네 방향 Offset 상, 하, 좌, 우 이동

```c++
int direct[4][2] ={  // dirrect 배열 저장.
    {-1, 0}, //up
    {1 , 0}, //down
    {0 ,-1}, //left
    {0 , 1} //right
}

for(i=0;i<4;i++){
    dy = y + direct[i][0];
    dx = x + direct[i][1];

    sum += data[dy][dx];
}
```

 - 범위 넘어가는 오버플로우 방지

 ```c++
 for(i=0;i<4;i++){
    dy = y + direct[i][0];
    dx = x + direct[i][1];

    if(dy>=0 && dy<4 && dx>=0 && dx<4>)
    {
        sum += data[dy][dx];
    }
}
```
### Direct 사용 예제

```c++
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	int arr[3][3] = {
		3,5,4,
		1,1,2,
		1,3,9
	};
	int y, x;
	cin >> y >> x;
	int direct[4][2] = {
		{-1,0},
		{1,0},
		{0,-1},
		{0,1}
	};
	int total = 0;
	int dy, dx;
	dy = y;
	dx = x;
	for (int i = 0; i < 4; i++)
	{
		dy = y + direct[i][0];
		dx = x + direct[i][1];
		if (dx >= 0 && dx < 3 && dy >= 0 && dy < 3) {
			total += arr[dy][dx];
		}
	}
	cout << total;
}
```

## 재귀호출 Recursive Call

> 함수 안에서 자기 자신을 호출하는 함수,     재귀함수를 이용한 코딩 기법을 배우게 됨

### abc(x+1)

1. x + 1 값을 abc함수로 보냄

2. x 변수값을 바꾸지 않는다.

### abc(x++)

1. x값을 그대로 보냄

2. 보낸뒤 x변수에 1추가

## 예시) n번 재귀호출하기

```c++
#include <iostream>
using namespace std;

int vect[5] = { 8, 7, 1, 2, 3};
void bbq(int level){
	cout<<level;
	if(level == 5){
		return;
	}
	cout<<vect[level];
	bbq(level + 1);
	cout<<vect[level];
}

int main(){
	bbq(0);

	return 0;
}
```

> 실행결과 :8712332178

## 예시) 입력받은 레벨까지 재귀함수 동작
입력: 2

출력: 0122122

```c++
#include<iostream>
using namespace std;

int limit;
void run(int level) {
	cout << level;
	if (level == limit) {
		return;
	}
	run(level + 1);
	run(level + 1);

	return;
}
int main()
{
	cin >> limit;
	run(0);
	return 0;
}
```
> 엄청 쉬운건데 생각하기 쉽지않음...

## strlen, strcpy, strcmp 사용하기

### 긴문장을 제일 앞으로
### strcmp는 같으면 0이 나온다 매우중요.
### memset(arr,'0',sizeof(arr)) 기억하기
```c++
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	char vect[3][11];
	int len;
	int maxlen;
	int maxIndex;

	//세 문장 입력
	for (int i = 0; i < 3; i++)
	{
		cin >> vect[i];
	}

	//가장 긴 문장 찾기
	maxlen = -1;
	for (int i = 0; i < 3; i++)
	{
		len = strlen(vect[i]);
		if (maxlen < len)
		{
			maxlen = len;
			maxIndex = i;
		}
	}

	//1번과 가장긴 문장 교환
	char temp[11];

	strcpy(temp, vect[maxIndex]);
	strcpy(vect[maxIndex], vect[0]);
	strcpy(vect[0], temp);


	for (int i = 0; i < 3; i++)
	{
		cout << vect[i] << endl;
	}

	return 0;
}
```

## 중력 문제 - 배열에서 떨어트리기

```c++
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

char vect[4][4];

// 특정 열(column)에 있는 문자를 중력의 영향을 받아 아래로 떨어뜨리는 함수
void drop(int column) {
    // 아래에서부터 위로 각 행(row)을 탐색
    for (int y = 3; y >= 0; y--) {
        // 현재 위치가 빈칸('_')인 경우
        if (vect[y][column] == '_') {
            bool found = false; // 빈칸 위에 문자가 있는지 여부를 저장하는 플래그

            // 현재 위치 위의 칸들을 탐색
            for (int t = y - 1; t >= 0; t--) {
                // 문자를 찾은 경우
                if (vect[t][column] != '_') {
                    // 현재 위치로 문자를 떨어뜨리고, 원래 위치는 빈칸으로 만듦
                    vect[y][column] = vect[t][column];
                    vect[t][column] = '_';
                    found = true; // 문자를 찾았음을 표시
                    break;
                }
            }

            // 위에 더 이상 문자가 없다면 탐색 중지
            if (!found) break;
        }
    }
}

int main() {
    // 4x4 배열 입력 받기
    freopen("input.txt", "r", stdin);
    for (int i = 0; i < 4; i++) {
        cin >> vect[i];
    }

    // 각 열에 대해 drop 함수를 호출하여 문자를 아래로 떨어뜨림
    for (int column = 0; column < 3; column++) {
        drop(column);
    }

    // 최종 배열 상태 출력
    for (int i = 0; i < 4; i++) {
        cout << vect[i] << endl;
    }

    return 0;
}
```
> 쉬워보이는 문제였지만 한칸만떨구는게아닌 끝까지 떨구는 거기 때문에 문제가생긴다. 문자기준이아니라 내가빈칸이면 위에서 받는 형식으로 구현이 좋다.

## 중요 String 사용하기

- string.length(); // 스트링길이구하기
- string1.find(string2) // string1안에서 string2있는지 체크, 없으면 -1, string::npos 반환, 있으면 찾은 첫번째 인덱스반환
- pos1= string1.find(sample);
- string1.find(sample,pos+1); // 찾은곳 이후부터 다시찾음, 한문장안에 여러 샘플 찾기 문제
### 주요예제
```c++
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);
	int result1 = 0;
	int result2 = 0;
	string a;
	cin >> a;

	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] >= 'A'&&a[i] <= 'Z') {
			a[i] = a[i] - 'A' + 'a';
		}
	}
	size_t pos = a.find("pass");
	while (pos != string::npos) {
		result1 += 1;
		pos = a.find("pass", pos + 1);
	}

	size_t pos2 = a.find("fail");
	while (pos2 != string::npos) {
		result2 += 1;
		pos2 = a.find("fail", pos2 + 1);
	}
	double temp = (static_cast<double>(result1) / (result1 + result2)) * 100;
	cout << temp << "%";
}

```

### string parsing 중요...
```c++
#include <iostream>
#include <string>
using namespace std;

int isValid(string tar)
{
	if (tar.length() != 5) return 0;
	for (int i = 0; i < 5; i++) {
		if (!(tar[i] >= '0' && tar[i] <= '9')) return 0;
	}
	return 1;
}

void go(string str)
{
	int a = 0;
	int b;

	while (1) {
		a = str.find('[', a);
		if (a == -1) return;
		b = str.find(']', a + 1);
		if (b == -1) return;

		string temp = str.substr(a + 1, b - a - 1);
		if (isValid(temp) == 1) {
			cout << "[" << temp << "]\n";
		}
		a = b + 1;
	}
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;

		go(str);
	}

	return 0;
}
```
### string parsing 같은 문자로 _
```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	string arr;
	string temp;
	cin >> arr;
	int count = 1;
	size_t pos = 0;
	

	while (arr.find("_") != -1) {
		pos = arr.find("_");
		temp = arr.substr(0, pos);
		cout << count<<"#"<<temp <<'\n';
		int len = 0;
		for (int i = arr.find("_"); arr[i] =='_'; i++)
		{
			len++;
		}
		arr = arr.substr(pos+len, arr.length()-pos-len+1);
		count++;
	}
	cout <<count<<"#"<< arr;
}
```

## 구현
>2중 for문 구현 시 time limit에 걸림
```c++
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

long int arr[100001];

int main() {
	//freopen("input.txt", "r", stdin);
	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++)
	{
		cin >> arr[tc];
	}
	sort(arr, arr + T);
	long int maxresult = 0;
	long int maxvalue = 0;
	long int value = 0;

	for (int i = 0; i < T; i++)
	{
		long int compare = arr[i] * (T - i); //정렬했으니 뒤로는 전부구매가능
		if (compare > maxresult) {
			maxresult = compare;
			maxvalue = arr[i];
		}
		else if (compare == maxresult) {
			maxvalue = min(maxvalue, arr[i]);
		}
	}
	cout << maxresult << " " << maxvalue;

	return 0;
}
```

### 오목 판정하기

```c++
#include <iostream>

using namespace std;

int arr[20][20];
// 우측, 하단, 우하단 대각선, 좌하단 대각선
int dy[4] = { 0, 1, 1, -1 };
int dx[4] = { 1, 0, 1, 1 };

bool check(int y, int x, int dir) {
	// 육목 체크
	// 1. 6칸 째 위치에 같은 색이 있다면 무조건 실패
	if (arr[y][x] == arr[y + 5 * dy[dir]][x + 5 * dx[dir]]) return false;
	// 2. 바로 이전 위치에 같은 색이 있다면 무조건 실패
	if (arr[y][x] == arr[y - dy[dir]][x - dx[dir]]) return false;

	// 5칸 확인
	for (int i = 0; i < 5; i++) {
		// 하나라도 다르다면 실패
		if (arr[y][x] != arr[y + i * dy[dir]][x + i * dx[dir]]) return false;
	}

	return true;
}

int main() {
	// 입력
	for (int i = 1; i < 20; i++) {
		for (int j = 1; j < 20; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i < 20; i++) {
		for (int j = 1; j < 20; j++) {
			// 돌이 놓여져 있다면
			if (arr[i][j]) {
				for (int dir = 0; dir < 4; dir++) {
					bool result = check(i, j, dir);
					if (result) {
						cout << arr[i][j] << '\n' << i << " " << j;
						return 0;
					}
				}
			}
		}
	}
	cout << "0";
	return 0;
}
```