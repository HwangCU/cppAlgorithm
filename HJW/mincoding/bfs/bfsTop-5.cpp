#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
int cnt = 0;

vector<int> com[101];
int visited[101] = { 0 };

void input()
{
	int a, b;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;

		com[a].push_back(b);
		com[b].push_back(a);
	}
}

void bfs(int st)
{
	queue<int> q;
	q.push(st);

	visited[st] = 1;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		cnt++;

		for (int i = 0; i < com[now].size(); i++)
		{
			if (visited[com[now][i]] == 1)
				continue;
			q.push(com[now][i]);
			visited[com[now][i]] = 1;
		}
	}
}

int main()
{
	input();
	bfs(1);
	cout << cnt-1;
	return 0;
}