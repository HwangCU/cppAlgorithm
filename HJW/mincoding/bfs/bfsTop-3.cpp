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
vector<int> rel[100001];
int visited[100001] = { 0 };

int N, M, K;
int coco;
int cnt = 0;

void input()
{
	int a, b;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;

		rel[a].push_back(b);
		rel[b].push_back(a);
	}

	cin >> coco;
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

		for (int i = 0; i < rel[now].size(); i++)
		{
			if (visited[rel[now][i]] == 1)
				continue;
			visited[rel[now][i]] = 1;
			q.push(rel[now][i]);
		}
	}

}

int main()
{
	input();
	bfs(coco);
	cout << cnt-1;

	return 0;
}