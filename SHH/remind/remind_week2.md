<h1> 2주차 복습 </h1>

# 백트래킹

## N-Queen //더하면 왼쪽
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