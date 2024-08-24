#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, K;

struct Way
{
	int dir;
	int cost;
};

vector<Way> route[100001];
long long visited[100001] = { 0 };

int cnt = 0;

void input()
{
	int A, B, C;
	cin >> N >> M >> K;

	for (int i = 0; i < M; i++)
	{
		cin >> A >> B >> C;

		route[A].push_back({ B, C });
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

		for (int i = 0; i < route[now].size(); i++)
		{
			q.push(route[now][i].dir);
			visited[route[now][i].dir] = visited[now] + route[now][i].cost;

			if (visited[route[now][i].dir] < K)
				cnt++;
		}
	}

}

int main()
{
	input();
	bfs(1);
	cout << cnt;

	return 0;
}