# 매일 알고리즘 정리
## 2024.07-26 (금) Recursion

재귀 - Recursion
### 함수 재귀.

```c++
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int arr[6];
void func(int level) {
	
	if (level == 5) {
		cout << arr[level] << " ";
		return;
	}
	cout << arr[level] << " ";
	func(level + 1);
	cout << arr[level] << " ";
}
int main()
{


	for (int i = 0; i < 6; i++)
	{
		cin >> arr[i];
	}

	func(0);


	return 0;
}
```
> 자기자신을 호출하는 함수. 재귀.

ex) 1 2 3 4 5 6 입력
    1 2 3 4 5 6 5 4 3 2 1  출력되는 코드를 작성하시오

### *3재귀

```c++
void func(int level){
	if(level==3){
		return;
	}
	for(int i=0;i<3;i++){
		func(level+1);
	}
}
```
---
3배로 증가한다.1->3>->9>...
순서중요


---
<hr style="border: 5px solid red; ">

---


## 2024.07-25 (목) Sort, Greedy

> 정렬은 기본이다. 하지만 라이브러리 쓴다.


### sort 정렬 $$ n^2 $$

> 느린데 왜 알아야 할까?

1. 데이터셋이 작다면 쓸만하다.
2. 라이브러리 못 쓸때 쓸만하다. 생각하기 쉬움.
3. 가끔 구현하라고 한다.

- 버블정렬
> 바로 옆에 것과 계속 교환하여 최댓값을 가장 오른쪽으로 미는 형태.
```c++
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int temp;
	//freopen("input.txt", "r", stdin);
	int arr[10] = { 3,4,5,6,2,1,5,4,3,1 };
	int len = sizeof(arr) / sizeof(int);
	for (int i = len - 1; i >= 0; i--)
	{
		for (int j = 0; j <= i-1; j++)
		{
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}
```
- 선택정렬
> 최솟값을 찾아서 앞에서부터 넣는다.

- 삽입정렬
> 키값을 차례대로 정해서 뒤에서부터비교한다. 작다면 삽입하고 그값은 뒤로보낸다.

> 한개씩 넣으면서 기존값과 비교한다고 생각해야함.

### sort 정렬  $$ n \log_2n $$

> c++ sort 라이브러리는 퀵정렬

> 파이썬은 병합정렬

- 병합정렬 (merge sort) - 폰 노이만 구조
> 계속 나눈다. 한 개 될때까지. 분할정복 알고리즘

> 구현하기 매우 어렵다. devide, merge
- 힙정렬

- 퀵정렬
> 젤앞은 pivot, 피봇기준 좌우 
> 나눈 두부분 계속 반복.

### sort 라이브러리 사용하자! (중요) c++

- 배열의 사이즈구하기
> 벡터.size() 스트링.length() 스트링.size()
```c++
int len = sizeof(arr)/sizeof(arr[0]);
```

- sort함수 사용하기

```cpp
#include <algorithm>

min, max, sort 포함 라이브러리


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int temp;
	//freopen("input.txt", "r", stdin);
	int arr[10] = { 3,4,5,6,2,1,5,4,3,1 };
	int len = sizeof(arr) / sizeof(arr[0]);
	sort(arr,arr+len);//배열의 시작주소, 끝주소
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}
```
vector 정렬

```cpp
int main()
{
	int temp;
	vector<int> v = { 4,2,5,3,10 };
	sort(v.begin(),v.end());
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	return 0;
}
```
### 역순 정렬(DESC)
```cpp
int main()
{
	int temp;
	vector<int> v = { 4,2,5,3,10 };
	sort(v.begin(),v.end(),greater<int>());

	int arr[5] = { 1,2,3,4,5 };
	sort(arr, arr + (sizeof(arr) / sizeof(arr[0])), greater<int>());

	return 0;
}
```
### string 정렬하기
```cpp
int main()
{
	string str[5] = {
		"bddcdc",
		"cbccd",
		"ebacc",
		"adcsc",
		"Abccf"
	};
	sort(str, str + 5, greater<string>());
	for (int i = 0; i < 5; i++)
	{
		cout << str[i] << " ";
	}
	return 0;
}
```
> 대소문자는 대문자가 값이 더 작다. 정렬하려면 섞지말고 전부다 대문자, 소문자로 변환 후 정렬

### 커스텀 정렬
내가 원하는대로 정렬

- 길이가 다른 경우 짧은 순.
- 길이가 같은 경우 사전 순.
> 내가 원하는 기준을 함수로 쓴다.
스트링 비교하면 제일 앞의 값비교한다. 같다면 다음글자

```c++
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct Member {
	string name;
	int age;
};

bool cp(Member a, Member b) {
	return a.age > b.age;
}
int main()
{
	Member members[3] = {
		{"조니",40},
		{"실비",20},
		{"나나",4},
	};
	sort(members, members + 3, cp);

	return 0;
}
```
> 원하는 비교방법 함수로 생성하고 sort함수의 3번째 인자로 넣음. 

>매개변수는 전 후이고, sort에 넣을 때는 함수이름만.
### 커스텀 정렬 중요 예제

```c++
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;



bool cp(string a, string b) {
	
	if (a.length() == b.length()) {
		return a < b;
	}
	
	return a.length() < b.length();
	
}
int main()
{
	int T;
	cin >> T;
	string arr[100];

	for (int i = 0; i < T; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr+T, cp);

	for (int i = 0; i < T; i++)
	{
		cout << arr[i] << '\n';
	}
	return 0;
}
```

### greedy(탐욕)

> 당장의 눈앞의 이익만 잘 쫓는다.
> 각각의 시행이 독립적일 때 효과적

### 잔돈반환 


---
<hr style="border: 5px solid red; ">

---

## 2024.07-24 (수) String parsing
> c++은 모든 c를 사용할수있다.

>c는 string이 없다 / 절차지형언어

```c++
#include <cstring>
#include <string.h> //똑같다
```

### cstring사용하기

- strlen(문자열) : 길이 반환
- strstr(문자열, 찾고싶은문자) : 문자열에서 찾은문자 주소반환, 없으면? NULL반환
- strcmp(문자열, 문자열) : 같으면 0
- strcpy(문자열, 바꾸고싶은내용) : 목적지에 문자열 넣음(기존문자열 남아있지만 0번부터넣음)
- strcat(문자열, 내용) : 문자열의 '\0'부터 내용을 뒤로 추가함.

```c++
int main()
{
	//freopen("input.txt", "r", stdin);

	char text[50] = "Hello world!";

	cout << text << '\n';
	cout << "len: " << strlen(text)<<'\n';

	strcpy(text, "hi");
	cout << text << '\n';
	return 0;
}
```
> 중요한부분 strcpy해도 뒤에 내용은 사라지지않는다. 하지만 끝점은 '\0'으로 판단

```c++
int main()
{
	//freopen("input.txt", "r", stdin);

	char text[50] = "Hello world!";

	cout << text << '\n';
	cout << "len: " << strlen(text)<<'\n';

	cout << strstr(text, "world");
	return 0;
}
```
> strstr 사용예제

> strlen, strstr, strcpy, strcmp, strcat 다섯가지 c함수 기억.

> 길이, 찾기, 복사, 비교, 추가

### C++에서는? String

string str
>클래스 안의 함수들은 메서드라고 한다. 객체지향 언어는 메서드.

- str.size(), str.length()   :  두개는 별 차이 없다. 벡터는 size함수임.
- str.find("찾는거") : 찾는 문자의 첫번째 주소 반환
- str.substr(시작주소, 길이) : 시작주소부터 길이만큼 자름
- str.erase(시작주소,길이) : 시작주소부터 길이만큼 자름
- str.insert(시작주소, 내용) : 시작주소부터 내용 넣음
- stoi(str) : string to number 스트링을 int로 바꿔줌
- to_string(intNum) : intNum을 string으로 바꿔줌
- str + str : 그냥 더하면 된다. strcat안해도된다.



```c++
	string text = "Hello world";
	text = "hi";
	cout << text;
	string text2 = "hi";
	if (text == text2) {
		cout << "같다";
	}
```
> 이게 된다. strcpy처럼 뒤에 남지도 않음.

### memset과 memcpy

>string은 memset안쓴다. 그냥 = "";하면되니까

- memset(arr, 0, sizeof(arr)) : cstring 안에있는 memset, 0이랑 -1 초기화만 된다.
- memcpy(arr1,arr2,sizeof(arr1)) : arr1에 arr2의 내용을 size만큼 넣는다.


---
<hr style="border: 5px solid red;">

---
## 2024.07-23 (화) 벡터, 방향배열
> 정적 배열은 매우 불편한다.
> CRUD - Create, Read, Update ,Delete 생성, 읽기, 수정, 삭제

### 1. vector
- 크기를 정하지 않는다.
- 동적할당. 배열이 훨씬 빠르다.
- <type> 템플릿이라고 한다. string vector도 가능하다.
- 1. v.push_back(값) : append랑 비슷
- 2. v.pop_back() : pop과 비슷 하지만 return값은 없음. 끝에 삭제
- 3. v.clear() : 안의 값을 다 비워줘;
- 출력은 아래 예제와 같이
- 시간이 매우 오래걸린다. 동적할당의 문제점
- 시간초과 나올 확률이 높다.

```c++
#include <iostream>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

int main() {
	vector<char> v;
	v.push_back('A');
	v.push_back('B');
	v.push_back('C');
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i];
	}
	cout << '\n';
	string a = "abcdddeeee";
	for (char c : a) { // 범위 기반 for 문 사용
		cout << c;
	}
	cout << '\n';
	char arr[10] = "qwerqwer";
	for (char c : arr) { // 범위 기반 for 문 사용
		cout << c;
	}
	cout << '\n';
	vector<string> v3 = { "Hello", "World", "C++" };

	for (string s : v3) { //const string& s도가능
		cout << s << " ";
	}
	cout << '\n';

	vector<int> v4[3] = {
		{1,2,3,4},
	{3,5,6},
	{1,1,1,1,2,3,4,5}
	};

	for (vector<int> c: v4 )
	{
		for (int a : c) {
			cout << a << " ";
		}
		cout << '\n';
	}
	return 0;
}
```
### 2. 구조체 벡터

```c++
#include <iostream>
#include <vector>

using namespace std;

struct Student
{
	char name[10];
	int age;
};

int main() {
	Student st1 = { "데이비드",23 };
	Student st2 = { "실비",30 };
	
	vector<Student> v ;
	v.push_back(st1);
	v.push_back(st2);

	for (Student c : v)
	{
		cout << c.name;
		cout << c.age;
	}

	return 0;
}
```
### 3. 2차원 벡터

> vector의 vector 가능은 하다

> 하지만 보기 매우 힘드니 벡터 배열을 사용하자

```c++
int main()
{
	vector<int> v[3] = {
		{1,2,3,4,5,6},
	{3,6,5},
	{1,1,1,2,3,4,5}
	};

	for (vector<int> tempv : v )
	{
		for (int c : tempv) {
			cout << c << " ";
		}
		cout << '\n';
	}

}
```

### 방향배열

- 동서남북
> y와 x의 쌍을 이루기 위해 구조체 Point 사용


```c++
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int direct[4][2] = {
	{-1,0},
	{1,0},
	{0,-1},
	{0,1}
};

int map[4][4] = {
	{1,3,7,2},
	{2,2,6,1},
	{1,4,5,1},
	{1,1,2,1}
};

struct Point
{
	int y;
	int x;
};
int main()
{
	Point st = { 0,0 };

	int total = 0;
	for (int i = 0; i < 4; i++)
	{
		int ny = st.y + direct[i][0]; // y + dy[i]
		int nx = st.x + direct[i][1]; // x + dx[i]


		if (ny >= 0 && ny < 4 && nx >= 0 && nx < 4) {
			total += map[ny][nx];
		}
	}
	cout << total;
}
```

### 방향백터 문제1) 가장 큰곳 찾기

- map 배열을 하드코딩 해주세요.

- 그리고 map에서 대각선 방향(왼쪽 위, 오른쪽 위, 왼쪽 아래, 오른쪽 아래)의 합이 가장 큰 값이 나오는 좌표(y, x)를 출력하세요.

- 단, 대각선 방향의 합을 구하는 sum(y, x) 함수를 만들어서 사용해 주세요.

- sum(y, x)는 특정 좌표 (y, x)에서 대각선 방향의 합을 반환하는 함수입니다.
```c++
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


int direct[4][2] = {
	{-1,-1},
	{1,-1},
	{-1,1},
	{1,1}
};

int MAP[5][5] = {
	{3, 3, 5, 3, 1},
	{2, 2, 4, 2, 6},
	{4, 9, 2, 3, 4},
	{1, 1, 1, 1, 1},
	{3, 3, 5, 9, 2}
};

struct Point
{
	int y;
	int x;
};

int sum(Point p) {
	int total=0;
	for (int i = 0; i < 4; i++)
	{
		int ny = p.y + direct[i][0]; 
		int nx = p.x + direct[i][1]; 


		if (ny >= 0 && ny < 5 && nx >= 0 && nx < 5) {
			total += MAP[ny][nx];
		}
	}
	return total;
}
int main()
{
	Point st = { 0,0 };
	Point result;
	int maxvalue = 0;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			st = { i,j };
			if (sum(st) > maxvalue) {
				maxvalue = sum(st);
				result = st;
			}
		}
	}
	cout << result.y << " " << result.x;

}
```
### 방향백터 문제2) 



---
<hr style="border: 5px solid red;">

---
## 2024.07-22 (월) D.A.T
> sort함수는 char array가 꽉차있으면 에러가 난다. 15개가 꽉차있다면 16으로 사이즈를 정해 제일 끝 칸을 비워야한다.
### DAT 문제1) DAT를 안쓰고 배열의 알파뱃 종류를 찾아내는 코드를 작성하세요
"A, D, B, F, A, D"
> 나의 답
```c++
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

char arr[7] = { "ADBFAD" };

int main() {
	//freopen("input.txt", "r", stdin);
	char result[7] = { 0 };
	int isalreadydone[7] = { 0 };
	int counting = 0;
	bool flag;
	for (int j = 'A'; j < 'Z'; j++)
	{
		for (int i = 0; i < strlen(arr); i++)
		{
			flag = false;
			if (j == arr[i]) {
				for (int p = 0; p < 7; p++)
				{
					if (j == isalreadydone[p]) {
						flag = true;
					}
				}
				if (flag == false) {
					cout << arr[i]<<" ";
					isalreadydone[counting] = arr[i];
					counting++;
				}
			}
		}
	}
}
```
>알파벳 A~Z 까지 체크하고 이미체크한건 is alreadydone배열에 추가하여 isalreadydone배열을 추가로 확인하도록 하여 flag로 다시 안나오게 한다는 컨셉.

> 정답
```c++
#include <iostream>

using namespace std;

char arr[10] = "ADBFAD";

int main()
{
    for (int i = 0; arr[i] != '\0'; i++) {
        bool isUnique = true;
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isUnique = false;
                break;
            }
        }
        if (isUnique) {
            cout << arr[i];
        }
    }
    return 0;
}
```
>2중 포문으로 체크하는 방법. 비효율적

### DAT면 1중 포문으로 해결할 수 있다.
문자도 index로 쓸 수 있다.

A = 65 ~ Z = 90

a = 97 ~ z = 122

### D.A.T Direct Access Table
즉각 접근 자료구조

> 값을 인덱스로 사용하는 자료구조

```c++
#include <iostream>

using namespace std;

char arr[10] = "ADBFAD";
int result[100] = { 0 };
int main()
{

	for (int i = 0; i < strlen(arr); i++)
	{
		result[arr[i]]++;
	}

	for (int i = 0; i < 100; i++)
	{
		if (result[i] >= 1) {
			cout << char(i);
		}
	}
}
```
### 뭐가 좋아졌나?
- 2중 for문 -> 1중 for문
- 정렬이 자동으로 된다.
- 직관적이다.
- 배열이 길어지면 차이는 더 커진다.
### 뭐가 안좋나?
- 메모리낭비(공간낭비)

### DAT 문제2) 4 1 1 1 5 4 각각의 숫자가 몇개인지 출력하시오

```c++
#include <iostream>

using namespace std;

int arr[6] = { 4, 1, 1, 1, 5, 4 };
int result[10] = { 0 };
int main()
{
	for (int i = 0; i < 6; i++)
	{
		result[arr[i]]++;
	}
	for (int i = 0; i < 10; i++)
	{
		if (result[i] > 0) {
			cout << i << ":" << result[i] << "개\n";
		}
	}
}
```
### DAT 문제3) 8글자의 대문자 알파벳으로 구성된 문장을 입력 하세요. 입력한 문장에서 가장 많이 사용된 알파벳을 출력하세요.

```c++
#include <iostream>

using namespace std;

char arr[8];
int DAT[150];

int main()
{
    cin >> arr;

    for (int i = 0; i < 8; i++)
    {
        DAT[arr[i]]++;
    }

    int maxIdx = 0;

    for (int i = 65; i < 150; i++)
    {
        if (DAT[maxIdx] < DAT[i])
        {
            maxIdx = i;
        }
    }

    cout << (char)(maxIdx);

    return 0;
}
```

### DAT 문제4) 5 x 3에 채워진 알파벳을 정렬하여 한 줄로 공백 없이 출력합니다.

```c++
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

char alphabet[5][3] = {
	{'A', 'B', 'C'},
	{'A', 'G', 'H'},
	{'H', 'I', 'J'},
	{'K', 'A', 'B'},
	{'A', 'B', 'C'}
};

int main()
{
	//freopen("input.txt", "r", stdin);
	char result[16] = { 0 };
	int bucket[100] = { 0 };
	int counting = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			result[counting] = alphabet[i][j];
			counting++;

			bucket[alphabet[i][j]]++;
		}
	}
	sort(&result[0], &result[0] + 15);

	cout << result;
	cout << '\n';

	for (int i = 0; i < 100; i++)
	{
		if (bucket[i] > 0) {
			cout << char(i);
			bucket[i] -= 1;
			i = 0;
		}
	}	
}
```
> 두가지 방법으로 해결.

- sort함수를 이용 -> 반드시 \n들어갈 사이즈 키워야함. 그래야 sorting 에러안뜸.

- dat이용. bucket[i]의 값만큼 반복문.

### 5) 카운팅 값 찾기
- 1~9사이의 정수 N 1개를 입력 받습니다.
- 5 x 3 의 정수 배열 내에서 N개가 존재하는 숫자를 출력합니다.

만약 N개가 존재하는 숫자가 두 개 이상이라면, 오름차순으로 출력합니다.

```c++
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int arr[3][5] = {
	1,3,3,5,1,
	3,6,2,4,2,
	1,9,2,6,5
};

int bucket[10];
int main()
{
	//freopen("input.txt", "r", stdin);
	int x;
	cin >> x;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			bucket[arr[i][j]]++;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		if (bucket[i] == x) {
			cout << i<<" ";
		}
	}
}
```

### 중요 * DAT2개문제

```c++
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int apt[1001][1001];
int black[1001][1001];
int ay, ax;
int by, bx;
int bucket[100001];
int blackbucket[100001];
int maxcount;
int blackman;
int whiteman;

void input() {
	cin >> ay >> ax;
	for (int i = 0; i < ay; i++)
	{
		for (int j = 0; j < ax; j++)
		{
			cin >> apt[i][j];
		}
	}
	cin >> by >> bx;
	for (int i = 0; i < by; i++)
	{
		for (int j = 0; j < bx; j++)
		{
			cin >> black[i][j];
		}
	}
}

void process() {
	for (int i = 0; i < ay; i++)
	{
		for (int j = 0; j < ax; j++)
		{
			bucket[apt[i][j]]++;
		}
	}

	for (int i = 0; i < by; i++)
	{
		for (int j = 0; j < bx; j++)
		{
			blackbucket[black[i][j]]=1;
		}
	}
}

int main()
{

	//freopen("input.txt", "r", stdin);
	input();
	maxcount = ay * ax;
	process();
	int flag = false;
	
	int count = 0;

	for (int i = 0; i < ay; i++)
	{
		for (int j = 0; j < ax; j++)
		{
			if (blackbucket[apt[i][j]] == 1) {
				blackman++;
			}
		}
	}

	cout << blackman << '\n';
	cout << ay*ax- blackman;

}
```

### 중요 *키순으로 카드번호 확인 

```c++
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int T;
int N;
int k[1000001];
int keys[1000001];

int bucket[251];
int main()
{
	//freopen("input.txt", "r", stdin);

	cin >> T;
	for (int test = 0; test < T; test++)
	{
		memset(bucket, 0, sizeof(bucket));
		memset(k, 0, sizeof(k));
		memset(keys, 0, sizeof(keys));
		//입력부///////////////
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> k[i];
			bucket[k[i]]++;
		}
		for (int i = 0; i < N; i++)
		{

			cin >> keys[i];
		}
		/////////////////////////

		bool isok = false;
		int total = 0;
		for (int i = 251; i >= 0; i--)
		{
			if (bucket[i] > 0) { //i=232

				for (int p = 0; p < N; p++) 
				{
					if (k[p] == i) { //i=232 ,k[p] =232
						if (total < keys[p]  && keys[p] <= total + bucket[i]) {
							isok = true;
						}
						else {
							isok = false;
							break;
						}
					}
				}
				total = total + bucket[i];
				if (isok == false) {
					break;
				}
			}
		}


		//출력부
		if (test == T - 1) {
			if (isok) {
				cout << "YES";
			}
			else {
				cout << "NO";
			}
		}
		else {
			if (isok) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}

	}
}
```

>위 방법은 단순하게 생각해서 푼거다 하지만 251*N번돈다
>아래는 정답이다. 최대 O(n);

```c++
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

int T, N;
int DAT[1000001];
int heights[1000001];
int nums[1000001];

void init()
{
	memset(DAT, 0, sizeof(DAT));
}

void input()
{
	for (int i = 0; i < N; i++)
	{
		cin >> heights[i];
	}
	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
	}
}

bool isSortedDesc()
{
	int minVal = 999999;
	for (int i = 1; i <= N; i++)
	{
		if (minVal >= DAT[i])
		{
			minVal = DAT[i];
			continue;
		}
		return false;
	}
	return true;
}

int main()
{
	// freopen("sample_input.txt", "r", stdin);
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> N;

		init();
		input();

		for (int i = 0; i < N; i++)
		{
			DAT[nums[i]] = heights[i];
		}

		bool ret = isSortedDesc();
		if (ret)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
}
```