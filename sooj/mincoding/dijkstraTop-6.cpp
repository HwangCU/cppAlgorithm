#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Node
{
	int y;
	int x;
	int cost;
};

int sy, sx, n;
int map[1000][1000];
int dist[1000][1000];

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

struct compare {
	bool operator()(Node a, Node b)
	{
		return a.cost > b.cost;
	}
};

void init()
{
	fill(&dist[0][0], &dist[0][0] + 1000 * 1000, 21e8);
}

void find_answer(Node start)
{
	priority_queue<Node, vector<Node>, compare> pq;
	pq.push(start);
	dist[start.y][start.x] = start.cost;
	//dist[start.y][start.x] = 0;

	while (pq.size())
	{
		Node now = pq.top(); pq.pop();
		//cout << now.y << ' ' << now.x << '\n';

		if (dist[now.y][now.x] < now.cost) continue;

		for (int i = 0; i < 4; i++)
		{
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
			if (map[ny][nx] == -1) continue;
			int next_cost = now.cost + map[ny][nx];
			if (dist[ny][nx] <= next_cost) continue;
			dist[ny][nx] = next_cost;
			
			pq.push({ ny,nx,next_cost });
		}

	}

}

int main()
{
	//freopen("input.txt", "r", stdin);
	init();
	cin >> sy >> sx;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}

	find_answer({sy,sx,map[sy][sx]});

	int answer = -21e8;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (dist[i][j] == 21e8) continue;
			if (dist[i][j] > answer) answer = dist[i][j];
		}
	}

	cout << answer;
}