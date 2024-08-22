/*
알뜰 기차여행
출발 지점부터 도착 지점까지의 최소 비용을 구하라
1. 출발은 0번에서 시작함
2. N-1번까지 도착하는 최소 거리를 구해야 함
3. 갈 수 없는 경우, impossible을 출력함
*/

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
    // a, b의 cost를 오름차순으로 정렬
	bool operator()(Edge a, Edge b)
	{
		return a.cost > b.cost;
	}
};

int N, T;
int dist[20000];
vector<Edge> v[300000];

void dijkstra(int st)
{
    //priority_queue로 cost 내림차순 정렬
	priority_queue<Edge, vector<Edge>, cmp> pq;
	pq.push({ st, 0 });
	dist[st] = 0;

	while (!pq.empty())  // pq 모두 탐색
	{
		Edge now = pq.top();
		pq.pop();

		if (dist[now.num] < now.cost)
		{
			continue;
		}

		for (int i = 0; i < v[now.num].size(); i++)
		{
            // 비용 누적
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
	cin >> N >> T;

	int from, to, cost;

	for (int i = 0; i < T; i++)
	{
		cin >> from >> to >> cost;
        // 단방향 진행
		v[from].push_back({ to, cost });
	}

	for (int i = 1; i < N; i++)
	{
		dist[i] = 21e8;
	}

	dijkstra(0);

	if (dist[N - 1] == 21e8) // 갈 수 없는 경우
	{
		cout << "impossible";
	}
	else
	{
		cout << dist[N - 1];
	}

	return 0;
}