/*
백준 7576. 토마토 풀이
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int days = 0;
int flag = 0;

struct Point
{
	int y;
	int x;
	int cnt;
};

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int map[1000][1000];
int M, N;

queue<Point> q;

void init()
{
	fill(map[0], map[0] + 1000 * 1000, 0);
}

void input()
{
	cin >> M >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
			{
				q.push({ i, j, 0 });
			}
		}
	}
}

void func()
{
	while (!q.empty())
	{
		Point now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue;

			if (map[ny][nx] == 0)
			{
				map[ny][nx] = 1;
				q.push({ ny, nx, now.cnt + 1 });
				days = now.cnt + 1;
			}
		}

	}
}

void find_zero()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 0) {
				flag = 1;
			}
		}
	}
}

void output()
{
	if (flag == 1)
	{
		cout << -1;
	}
	else
		cout << days;
}

int main()
{
	init();
	input();
	func();
	find_zero();
	output();
}