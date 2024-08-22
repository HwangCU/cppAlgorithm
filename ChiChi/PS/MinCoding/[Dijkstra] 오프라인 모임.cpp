#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M, P;
int dist[1001];
struct Edge
{
	int num;
	int cost;
};
vector<Edge> v[1001];

struct cmb
{
	bool operator()(Edge a, Edge b)
	{
		return a.cost > b.cost;
	}
};

void input()
{
	cin >> N >> M >> P;
	for (int i = 0; i < M; i++)
	{
		int s, e, w;
		cin >> s >> e >> w;
		v[s].push_back({ e,w });
	}
}

void dijkstra(int st)
{
	priority_queue<Edge, vector<Edge>, cmb> pq;
	
	pq.push({ st,0 });
	dist[st] = 0;
	while (!pq.empty())
	{
		Edge now = pq.top();
		pq.pop();

		if (dist[now.num] < now.cost) continue;

		for (int i = 0; i < v[now.num].size(); i++)
		{
			int nextCost = now.cost + v[now.num][i].cost;
			int tar = v[now.num][i].num;
			if (dist[tar] > nextCost)
			{
				dist[tar] = nextCost;
				pq.push({ tar,nextCost });
			}
		}
	}
}

int main()
{
	input();
	int sumNode[1001] = { 0 };
	// N만큼 다익스트라 돌리기
	for (int i = 1; i <= N; i++)
	{
		for (int i = 1; i <= N; i++)
		{
			dist[i] = 21e8;
		}
		dijkstra(i);
		sumNode[i] += dist[P];
	}

	// P에서 각자 집으로 돌아가기
	for (int i = 1; i <= N; i++)
	{
		dist[i] = 21e8;
	}
	dijkstra(P);

	int maxVal = 0;
	int ans = 0;

	for (int i = 1; i <= N; i++)
	{
		sumNode[i] += dist[i];
		if (maxVal < sumNode[i])
		{
			maxVal = sumNode[i];
		}
	}
	cout << maxVal;
}