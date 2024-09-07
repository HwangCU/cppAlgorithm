#include <iostream>
#include <vector>

using namespace std;

vector<int> computer[100];
int visited[100] = { 0 };
int cnt = 0;
int C, N;

void input()
{
	int a, b;
	cin >> C >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		computer[a].push_back(b);
		computer[b].push_back(a);
	}
}

void dfs(int lvl, int now)
{
	if (visited[now] == 1)
	{
		return;
	}

	visited[now] = 1;
	cnt++;

	for (int i = 0; i < computer[now].size(); i++)
	{
		int next = computer[now][i];
		dfs(lvl + 1, next);
	}
}

int main()
{
	input();
	dfs(0, 1);

	cout << cnt - 1;

	return 0;
}