#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int map[10][10];
int visited[10] = { 0 };

int N;

void input()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
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

		if (visited[now] == 1)
			continue;
		visited[now] = 1;

		cout << now << " ";
		
		for (int i = 0; i < N; i++)
		{
			if (map[now][i] == 1 && visited[i] == 0)
			{
				q.push(i);
			}
		}
	}
}

int main()
{
	input();
	bfs(0);
    
	return 0;
}