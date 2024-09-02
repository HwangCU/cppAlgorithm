#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int N, M;
char map[1001][1001];
int visited[1001][1001];
int costMap[1001][1001];
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
int ans = 0;

struct Point
{
	int y, x;
};

void init()
{
	memset(map, 0, sizeof(map));
	memset(visited, 0, sizeof(visited));
	memset(costMap, 0, sizeof(costMap));
	ans = 0;
}

void input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}
}

void print()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << visited[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

void bfs()
{
	queue<Point> q;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 'W')
			{
				q.push({i,j});
			}
		}
	}

	while (!q.empty())
	{
		Point now = q.front();
		q.pop();
		print();
		for (int d = 0; d < 4; d++)
		{
			Point next = { now.y + dy[d], now.x + dx[d] };
			if (next.y < 0 || next.y >= N || next.x < 0 || next.x >= M) continue;
			if (map[next.y][next.x] == 'W') continue;
			if (visited[next.y][next.x] > visited[now.y][now.x] + 1) continue;

			visited[next.y][next.x] = visited[now.y][now.x] + 1;
			q.push({ next.y, next.x });
		}
	}
}

void solve()
{
	bfs();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			ans += visited[i][j];
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		init();
		input();
		solve();
		cout << '#' << t << ' ' << ans << '\n';
	}
}