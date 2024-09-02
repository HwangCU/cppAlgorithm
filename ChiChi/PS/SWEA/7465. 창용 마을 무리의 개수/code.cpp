#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

int N, M;
vector<int> v[101];
int visited[101];
int ans = 0;

void init()
{
	memset(v, 0, sizeof(v));
	memset(visited, 0, sizeof(visited));
	ans = 0;
}

void input()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int st, e;
		cin >> st >> e;
		v[st].push_back(e);
		v[e].push_back(st);
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

		for (int i = 0; i < v[now].size(); i++)
		{
			int tar = v[now][i];
			if (visited[tar]) continue;
			visited[tar] = 1;
			q.push(tar);
		}
	}
}

void solve()
{
	for (int i = 1; i <= N; i++)
	{
		if (visited[i]) continue;
		bfs(i);
		ans++;
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		init();
		input();
		solve();
		cout << '#' << t << ' ' << ans<<'\n';
	}
}