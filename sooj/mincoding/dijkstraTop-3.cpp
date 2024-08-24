#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;

struct Edge {
	int y;
	int x;
	int cost;
};

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int connected[100][100];
int dist[100][100];

struct compare {
	bool operator()(Edge a, Edge b)
	{
		return a.cost > b.cost;
	}
};

void find_answer(int sy, int sx)
{
	priority_queue<Edge, vector<Edge>, compare> pq;
	pq.push({ sy, sx, connected[sy][sx] });
	dist[sy][sx] = connected[sy][sx];

	while (pq.size())
	{
		Edge now = pq.top(); pq.pop();
		if (dist[now.y][now.x] < now.cost) continue;
		for (int i = 0; i < 4; i++)
		{
			Edge next = now;
			next.y = now.y + dy[i];
			next.x = now.x + dx[i];
			if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= m) continue;
			next.cost = now.cost + connected[next.y][next.x];
			if (next.cost > dist[next.y][next.x]) continue;
			dist[next.y][next.x] = next.cost;
			pq.push(next);
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> connected[i][j];
		}
	}
	fill(&dist[0][0], &dist[0][0] + 10000, 21e8);
	find_answer(0,0);
	cout << dist[n - 1][m - 1];
}