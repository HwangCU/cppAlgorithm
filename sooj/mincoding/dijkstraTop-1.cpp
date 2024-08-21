#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>


using namespace std;

struct Node
{
	int num; // 연결된 노드 넘버
	int cost; //연결된 노드까지 누적합
};

int n, t, answer;
vector<Node>connected[20000];
int dist[20000];

struct compare {
	bool operator()(Node a, Node b)
	{
		return a.cost < b.cost;
	}
};
priority_queue<Node,vector<Node>,compare> pq;

void init()
{
	fill(dist, dist + 20000, 21e8);
	answer = 0;
}

void dijkstra(int start)
{
	pq.push({ start,0 });
	dist[0] = 0;

	while (pq.size())
	{
		Node now = pq.top(); pq.pop();
		if (dist[now.num] < now.cost) continue;

		for (int i = 0; i < connected[now.num].size(); i++)
		{
			int next = connected[now.num][i].num;
			int next_cost = now.cost + connected[now.num][i].cost;
			if (dist[next] < next_cost) continue;
			dist[next] = next_cost;
			pq.push({ next,next_cost });
		}
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	init();
	cin >> n >> t;
	int a, b, w;
	for (int i = 0; i < t; i++)
	{
		cin >> a >> b >> w;
		connected[a].push_back({ b,w });
	}

	dijkstra(0);

	for (int i = 0; i < n; i++)
	{
		if (dist[i] == 21e8)
		{
			cout << "impossible\n";
			return 0;
		}
	}
	cout << dist[n - 1] << '\n';
}