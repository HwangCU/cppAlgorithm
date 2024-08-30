#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int V, E,K;
struct Edge
{
	int num;
	int cost;
};
vector<Edge> vec[20001];
int dist[20001];

struct cmp
{
	bool operator() (Edge a, Edge b)
	{
		return a.cost > b.cost;
	}
};

void input()
{
	cin >> V >> E>>K;
	for (int i = 0; i < E; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		vec[u].push_back({ v,w });
	}
}

void dijkstra(int st)
{
	priority_queue<Edge, vector<Edge>, cmp> pq;
	pq.push({ st,0 });
	dist[st] = 0;

	while (!pq.empty())
	{
		Edge now = pq.top();
		pq.pop();

		if (dist[now.num] < now.cost) continue;

		for (int i = 0; i < vec[now.num].size(); i++)
		{
			int nextCost = now.cost + vec[now.num][i].cost;
			int tar = vec[now.num][i].num;

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
	for (int i = 0; i <= V; i++)
	{
		dist[i] = 21e8;
	}
	dijkstra(K);
	for (int i = 1; i <= V; i++)
	{
		if (dist[i] == 21e8)
			cout << "INF\n";
		else
			cout << dist[i] << '\n';
	}
}