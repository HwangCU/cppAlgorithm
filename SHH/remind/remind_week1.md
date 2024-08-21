<h1> 1주차 복습 </h1>

# DAT
> Direct Access Table : 즉각 접근 자료구조
 
key 값을 배열의 인덱스로 사용하는 기법이다. 매우 유용하고 중요한 기법이다.
- 정렬이 자동으로 된다 (인덱스값으로 사용하기 때문에)

A,B,C,D,E를 E,D,C,B,A순으로 입력을 받았다 하자.

```c++
int dat[200];
char temp;
for(int i=0; i<5;i++){
    cin>>temp;
    dat[temp]++;
}
```

이렇게 된다면 dat배열에는 65,66,67,68,69번 인덱스의 값이 ++되었을 것이다.

- 최빈수 구하기가 정말 쉬워진다. 그냥 dat테이블에서 가장 큰 값의 인덱스가 최빈수다.

- for문을 하나 줄일 수 있다.(매우중요)

중요한 문제는 Problems에 추가한다.

- 공간차지를 많이한다. 하지만 이는 생각할 이유가 없다. 코딩테스트를 준비한다면 Time Limit이 매우 중요하기 때문이다.


# Direct
> 방향배열을 이용하여 전체 탐색하는 것이다.


## 방향배열

> 동서남북, y와 x의 이동을 배열로 만들어 사용한다.
- y,x 쌍의 구조체를 만들어 사용한다면 묶어서 사용하기 더 쉽다.

말보다는 문제로 보는게 더 이해하기 쉽다.

### 대각선값들의 합이 가장 큰 좌표 구하기
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


# cstring

- strlen(문자열) : 길이반환
- strstr(문자열, 찾는문자): 문자열에서 찾은문자의 주소 반환, 없다면 NULL반환
- strcmp(문자열, 문자열) : compare함수, 같으면 0 반환
- strcpy(문자열, 바꾸고싶은 내용) : 문자열에 내용을 넣는다. 기존의 값이 있어도 0번부터 넣기 때문에 뒤쪽에 기존문자열이 남을 수 있다. 하지만 \0값이 끝에들어감.
- strcat(문자열, 내용) : 문자열의 \0의 위치부터 내용을 추가해서 넣는다.
- memset(arr, 0, sizeof(arr)) : cstring 안에있는 memset, 0이랑 -1 초기화만 된다.
- memcpy(arr1,arr2,sizeof(arr1)) : arr1에 arr2의 내용을 size만큼 넣는다.

# string

- str.size(), str.length()   :  두개는 별 차이 없다. 벡터는 size함수임.
- str.find("찾는거") : 찾는 문자의 첫번째 주소 반환
- str.substr(시작주소, 길이) : 시작주소부터 길이만큼 자름
- str.erase(시작주소,길이) : 시작주소부터 길이만큼 자름
- str.insert(시작주소, 내용) : 시작주소부터 내용 넣음
- stoi(str) : string to number 스트링을 int로 바꿔줌
- to_string(intNum) : intNum을 string으로 바꿔줌
- str + str : 그냥 더하면 된다. strcat안해도된다.

# string parsing

> 스트링을 분할하는 기법이다. 매우 중요하다.어렵다

## 이건 3번씩봐서 이해해야한다.

- str.find("찾는거") : 찾는 문자의 첫번째 주소 반환
- str.substr(시작주소, 길이) : 시작주소부터 길이만큼 자름



# vector

- 크기할당 X,동적할당, -> 정적배열이 빠르다.
- <type> 탬플릿이라고한다.
- v.push_back(값)
- v.pop_back() : pop과 다르게 return은 없이 삭제만한다.
- v.clear() : 벡터를 비운다
- 사용자가 정의한 구조체도 벡터의 템플릿으로 이용할 수 있다.

# Sort
> 정렬은 기본. 하지만 개발 시에는 라이브러리 사용
## 버블, 삽입, 선택정렬
$$ n^2 $$

### 버블정렬
- 바로 옆의 값을 계속비교한다.
- 최댓값을 가장 오른쪽으로 미는형태

### 선택정렬
- 최솟값을 찾아서 가장 앞으로 넣는다.

### 삽입정렬
- 키값을 정해서 뒤에서부터 비교한다.
- 인덱스 1번(두번째값)부터 key로 정해서 그앞의 값들과 비교한다.
- 한개씩 넣으면서 뒤에서부터 비교하는 기법

## 병합, 퀵, 힙정렬
$$ n \log_2n $$

> c++ sort 라이브러리는 퀵정렬

> 파이썬은 병합정렬

- 병합정렬 (merge sort) - 폰 노이만 개발
> 계속 나눈다. 한 개 될때까지. 분할정복 알고리즘

> 구현하기 매우 어렵다. devide, merge
- 힙정렬

- 퀵정렬
> 젤앞은 pivot, 피봇기준 좌우 
> 나눈 두부분 계속 반복.

## sort 라이브러리 사용하기
배열과 벡터의 정렬
```c++
    int arr[10] = { 3,4,5,6,2,1,5,4,3,1 };
	int len = sizeof(arr) / sizeof(arr[0]);
	sort(arr,arr+len);//배열의 시작주소, 끝주소

    vector<int> v = { 4,2,5,3,10 };
    sort(v.begin(),v.end());
```
역순정렬
```c++
	vector<int> v = { 4,2,5,3,10 };
	sort(v.begin(),v.end(),greater<int>());

	int arr[5] = { 1,2,3,4,5 };
	sort(arr, arr + (sizeof(arr) / sizeof(arr[0])), greater<int>());

```
String 정렬
```c++
    string str[5] = {
		"bddcdc",
		"cbccd",
		"ebacc",
		"adcsc",
		"Abccf"
	};
    sort(str, str + 5, greater<string>());
```
## Custom 정렬.
> 개발자가 비교함수를 만들어 sort함수의 3번째 인자로 넣으면 된다.

```c++
bool cp(string a, string b) {
	
	if (a.length() == b.length()) {
		return a < b;
	}
	
	return a.length() < b.length();
	
}

sort(arr, arr+T, cp);
```

# Greedy

> 당장의 눈앞의 이익만 잘 쫓는다.
> 각각의 시행이 독립적일 때 효과적

# Recursion

> 자기자신을 호출하는 함수를 재귀함수라고 한다.

<<<<<<< Updated upstream
=======
# Greedy

# Recursion
>>>>>>> Stashed changes
