# 매일 알고리즘 정리

## 2024.08-20 (화)

### Priority Queue

- Queue는 FIFO원칙이지만 PQ는 내가 우선순위를 정한다

기본 라이브러리 퀵소트

```c++
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int a, int b)
{
    // 오름차순
    // return a < b;
    // 내림차순
    // return a > b;
}

int main()
{
    int arr[6] = { 3, 2, 4, 1, 5, 7, };

    sort(arr, arr + 6, compare);

    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << '\n';
    return 0;
}
```

PQ는 이름만 Queue고 Queue가 아니다. max heap이다

넣으면 정렬되더라.

1. 데이터를 집어넣어가면서 정렬을 유지해야할때

2. 다익스트라(PQ)

정렬

1. 오름차순
2. 내림차순 (PQ의 기본)
3. 커스텀

```c++
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//priority_queue<int, vector<int>, greater<int>> pq;

struct compare {
	bool operator()(int a, int b) {
		return a < b;
	}
};

priority_queue<int, vector<int>, compare> pq;

int main() {
	pq.push(1);
	pq.push(3);
	pq.push(2);
	pq.push(4);

	while (!pq.empty()) {
		cout << pq.top()<<'\n';
		pq.pop();
	}
}
```

struct안에 operator()함수로 정의한다.

아래 외워라

```c++
struct compare {
	bool operator()(int a, int b) {
		return a < b;
	}
};

priority_queue<int, vector<int>, compare> pq;
```

부등호는 sort의 compare함수와 반대이다.

퀵소트, 힙소트

```c++
#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

struct Member
{
	int id;
	string name;
};

struct compare {
	bool operator()(Member m1, Member m2)
	{
		if (m1.id == m2.id) return m1.name > m2.name;
		return m1.id > m2.id;
	}
};

priority_queue<Member, vector<Member>, compare> pq;

int main()
{
	pq.push({ 1,"라" });
	pq.push({ 5,"나" });
	pq.push({ 1,"가" });
	pq.push({ 3,"다" });

	while (pq.size())
	{
		cout << pq.top().id << ' ' << pq.top().name << ' ';
		pq.pop();
	}
}
```

## 2024.08-21 (수)

### Dijkstra 다익스트라

<p align="center">
  <img src="../imgs/다익스트라.JPG">
</p>

- dijkstra를 안쓰고 최단거리를 구해라

```c++
#include <iostream>
#include <queue>
using namespace std;

int map[4][4] = {
	0,1,5,0,
	1,0,8,1,
	5,8,0,1,
	0,1,1,0
};
int visited[4];
int ep = 2;//3이니까 2번인덱스
int sp = 0;

int result = 21e8;
void dfs(int cp, int cost) {
	if (cp == 2) {
		result = min(result, cost);
	}

	for (int i = 0; i < 4; i++)
	{
		if (map[cp][i] == 0)continue;//못감

		if (visited[i] == 1)continue;
		else {
			visited[i] = 1;
			dfs(i, cost + map[cp][i]);
			visited[i] = 0;
		}
	}
}

int main() {
	dfs(sp,0);
	cout << result;
}
```

<p align="center">
  <img src="../imgs/다익스트라2.JPG">
</p>

- 모든 정점으로 가는 경로를 미리 계산하기!!!

-

### 다익스트라 기본

```c++
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge
{
    int num;
    int cost;
};

struct cmp
{
    bool operator()(Edge a, Edge b)
    {
        return a.cost > b.cost;
    }
};

// N: 6
// M: 7
int N, M;
// 1번부터 6번까지
int dist[7];
vector<Edge> v[7];

void dijkstra(int st)
{
    priority_queue<Edge, vector<Edge>, cmp> pq;
    pq.push({ st, 0 });
    dist[st] = 0;
    while (!pq.empty())
    {
        Edge now = pq.top();
        pq.pop();

        // 가지치기 조건
        if (dist[now.num] < now.cost)
            continue;

        for (int i = 0; i < v[now.num].size(); i++)
        {
            int nextCost = now.cost + v[now.num][i].cost;

            int tar = v[now.num][i].num;
            if (nextCost < dist[tar])
            {
                dist[tar] = nextCost;
                pq.push({ tar, nextCost });
            }
        }
    }
}

int main()
{
    freopen("sample_input.txt", "r", stdin);
    cin >> N >> M;
    int from, to, cost;
    for (int i = 0; i < M; i++)
    {
        cin >> from >> to >> cost;
        v[from].push_back({ to, cost });
        v[to].push_back({ from, cost });
    }

    // 초기 dist 세팅
    for (int i = 1; i <= N; i++)
    {
        dist[i] = 21e8;
    }

    dijkstra(1);

    return 0;
}
```