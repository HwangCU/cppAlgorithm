# 알고리즘 총정리 - 매주 일요일 업데이트
>240728 update
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

## 백터 라이브러리 함수들.

```c++
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main() {
	vector<int> v(3, 1);
	vector<int>::iterator it = v.begin();

	cout << "1. 초기화 : ";
	for (int n : v) cout << n << " ";
	cout << "\n";

	it = v.insert(it, 2);
	cout << "2. 맨앞에 삽입 : ";
	for (int n : v) cout << n << " ";
	cout << "\n";

	it = v.insert(it, 2, 3);
	cout << "3. 맨앞에 여러개 삽입 : ";
	for (int n : v) cout << n << " ";
	cout << "\n";

	it = v.insert(it+3, 2, 4);
	cout << "4. 3번째부터 여러개 삽입 : ";
	for (int n : v) cout << n << " ";
	cout << "\n";


	int arr[] = { 5, 50, 500, 5000};

	it = v.insert(v.begin(), arr, arr+4);
	cout << "5. 맨앞의 배열 삽입 : ";
	for (int n : v) cout << n << " ";
	cout << "\n";

	// 1<= 삭제 < 4 인걸 주의해야 한다.
	v.erase(v.begin() + 1, v.begin() + 4);
	cout << "6. 1~3까지 삭제 : ";
	for (int n : v) cout << n << " ";
	cout << "\n";

	return 0;
}
```
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

> 생각보다 많이 쓰게 된다.

```c++
bool cp(string a, string b) {
	
	if (a.length() == b.length()) {
		return a < b;
	}
	
	return a.length() < b.length();
	
}

sort(arr, arr+T, cp);
```

조금 헷갈리는데 a<b 를 리턴했다면 a < b이다. 오름차순 정렬되는거

반대로 a > b면 앞에 것이 더 크도록 sorting 내림차순

# Greedy

> 당장의 눈앞의 이익만 잘 쫓는다.
> 각각의 시행이 독립적일 때 효과적

# Recursion

> 자기자신을 호출하는 함수를 재귀함수라고 한다.

# 백트래킹

## N-Queen
```c++
#include <iostream>

using namespace std;

int visited[15]; // 열 방문 확인
int slash[30]; // '/' 대각선 방문 확인
int backslash[30]; // '\' 대각선 방문 확인
int N;
int resultcount = 0;

void func(int level) {
	if (level == N) {
		resultcount++;
		return;
	}

	for (int i = 0; i < N; i++) {
		if (visited[i] || slash[level + i] || backslash[level - i + N - 1]) {
			continue;
		}

		visited[i] = slash[level + i] = backslash[level - i + N - 1] = 1;
		func(level + 1);
		visited[i] = slash[level + i] = backslash[level - i + N - 1] = 0;
	}
}

int main() {
	cin >> N;

	func(0);

	cout << resultcount;
	return 0;
}

```
## **Path**

- 경로기억하기 -> 왔던 길을 기억해야한다.

```c++
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int N;

int path[2] = { -1, -1 };

void func(int level) {
	if (level == N) return;

	for (int i = 0; i < 2; i++)
	{
		path[level] = i;
		func(level + 1);
		path[level] = -1;

	}

}
int main() {
	//freopen("input.txt", "r", stdin);

	cin >> N;
	func(0);

}
```

## 주사위 N번던져서 나오는 경우의 수 출력하기

백트래킹이나 DFS나 거기서 거기다. 가지치기가 매우중요. 백트래킹은 level==N일때 정지.

# DFS


입력에 따라 다르게 맵을 사용해야한다.

행렬로들어오면 행렬로, A to B형식으로 들어오면 벡터로

양방향인지, 가지치기 조건이 더 없는지 항상 확인해야한다.

## 기본적으로 이 포맷을 벗어나질 않는다.

```c++
void func(int now, int sum) {

	if (now == en) {
		minCnt = min(minCnt, sum);
		maxCnt = max(maxCnt, sum);
		return;
	}

	for (int i = 0; i < nodeCnt; i++)
	{
		if (visited[i] == 1)continue;
		if (arr[now][i] == 0)continue;


		visited[i] = 1;
		func(i, sum + arr[now][i]);
		visited[i] = 0;


	}


}
```

### 2105. [모의 SW 역량테스트] 디저트 카페

- 시작점은 제시 X 모든점에서 시작한다.
- 시작점, 현재점, 방향
- 현재점이 초기점과 같다면 반환 (처음제외)
- 다음점이 범위밖이면 리턴
- DAT로 갔던 값이면 리턴 (갔던곳 또못감)
- 회전할 수 있으면 돌려서 DFS
- 직진 DFS

## 중요) 맵크기가 20이 넘어간다면? DFS를 쓰면 시간초과가 난다. 

## 방향배열 실수했는지 항상 확인해라

# BFS

## 큐를 사용한다. 기본적으로 아래 포맷을 사용하면 대부분 풀린다.

```c++
void bfs(int st) {
	queue<int> q;
	visited[st] = 1;
	q.push(st);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < 7; i++)
		{
			if (visited[i] == 1) continue;
			if (arr[now][i] == 0)continue;
			visited[i] = 1;
			q.push(i);
		}
		cout << now << " ";
	}

}
```

## 백준 2178번 BFS문제를 반복 학습하자.

- 2차원 bfs는 flood fill

# 다익스트라 Dijkstra

최단경로 알고리즘 매우중요하다.

```c++
#include <iostream>
#define INF 1000000000
#define N 5
using namespace std;

int weight[N][N] = { { 0,7,4,6,1},
                     { INF,0,INF,INF,INF},
                     { INF,2,0,5,INF},
                     { INF,3,INF,0,INF},
                     { INF,INF,INF,1,0} };

bool visit[N];
int dist[N];
int min_node;

int get_small_node() {
    // 최소비용노드 탐색 함수
    int min = INF;
    int minpos = 0;
    for (int i = 0; i < N; i++) {
        if (dist[i] < min && !visit[i]) {
            min = dist[i];
            minpos = i;
        }
    }
    return minpos;
}

void dijkstra(int start) {
    for (int i = 0; i < N; i++) {
        dist[i] = weight[start][i];
    }

    visit[start] = true;
    for (int repeat = 0; repeat < N - 1; repeat++) {
        min_node = get_small_node(); // 최소비용노드 탐색
        visit[min_node] = true; // 최소비용노드 방문처리
        for (int i = 0; i < N; i++) {
            // 방문하지 않은 노드 중에, 시작점이 최소비용노드를 경유하는게
            // 더 가까우면 값 갱신
            if (!visit[i])
                if (dist[min_node] + weight[min_node][i] < dist[i])
                    dist[i] = dist[min_node] + weight[min_node][i];
        }
    }
}

int main() {
    
    dijkstra(0);

    for (int i = 0; i < N; i++)
        cout << dist[i] << "  ";

    return 0;
}
```

# DP

DP, Dynamic Programming(동적 계획법)은 무엇일까?
DP란, 하나의 큰 문제를 작은 문제로 나누어 해결하는 기법을 의미한다. 

```
int f(int n){
	if(n == 0 || n == 1) return 1;
    return f(n-1) + f(n-2);
}
```
DP의 사용 조건
DP가 적용되기 위해서, 또는 문제풀이 기법이 DP라 부르기 위해서는 2가지 조건이 필요하다. 

겹치는 소문제 ( Overlapping Subproblems )
최적 부분 구조 ( Optimal Substructure )

값을 저장해서 나중에 cost가 높은 계산은 하지않고 불러오는 형식으로 하는 방법이다.

간단한듯 어려움

## Top-Down

- 큰 문제부터 점점 쪼개나간다.

## Bottom-Up

- 작은 문제부터 차례대로 풀어간다.


## Flood Fill

### SWEA 1953. 탈주범 검거

문제 

---

```plain

교도소로 이송 중이던 흉악범이 탈출하는 사건이 발생하여 수색에 나섰다.

탈주범은 탈출한 지 한 시간 뒤, 맨홀 뚜껑을 통해 지하터널의 어느 한 지점으로 들어갔으며,

지하 터널 어딘가에서 은신 중인 것으로 추정된다.

터널끼리 연결이 되어 있는 경우 이동이 가능하므로 탈주범이 있을 수 있는 위치의 개수를 계산하여야 한다.

탈주범은 시간당 1의 거리를 움직일 수 있다.

탈주범이 탈출 한 시간 뒤 도달할 수 있는 지점은 한 곳이다.

3시간 후에는 [그림 1-4] 과 같이 총 5개의 지점에 있을 수 있다.

```
---

### 지문 속 중요한 구문

> 한 시간 뒤, 맨홀 뚜껑을 통해 지하터널의 어느 한 지점으로 들어갔다

- L(시간)이 1일 경우 탈주범이 할 수 있는건 하나다. 

> 터널끼리 연결이 되어 있는 경우 이동이 가능하다

> 탈주범은 시간당 1의 거리를 움직일 수 있다.

> 맨홀 위치가 주어진다.

- 맨홀 위치부터 터널을 따라 퍼지는 flood fill

---
### 아이디어

- 파이프는 현재 뿐만 다음 좌표의 파이프도 고려해야한다.

- BFS - Flood fill문제

- now에서 next로 간다 current point -> next point 

- next에서 now로 올 수 있는지 확인한다.<중요> next point -> current point
---

음...내가뭘할수잇지

삼성전자 SW역량평가 B형 취득을 위한 공부
