#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Dungeon
{
	int N;
	int K;
};

int map[10][10] = { 0 };
int cost[10] = {0};

int N, M, K;

void input()
{
	int a, b, c;
	cin >> N >> M >> K;

	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		map[a][b] = c;
	}
	
}

void bfs(int st)
{
	queue<int> q;
	q.push(st);

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		for (int i = 0; i < 10; i++)
		{
			if (map[now][i] != 0)
			{
				q.push(i);
				cost[i] = cost[now] + map[now][i];
			}
				
		}
	}

	for (int i = 1; i < N; i++)
	{
		if (cost[i] <= K && cost[i] > 0)
			cout << i << " ";
	}
}

int main()
{
	input();
	bfs(0);
	return 0;

}