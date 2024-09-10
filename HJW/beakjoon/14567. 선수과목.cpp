// 백준 14567. 선수과목

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Point
{
	int n;
	int cnt;
};

int N, M;

vector<int> alist[1001];
queue<Point> q;
int life[1001];
int total[1001];

void input()
{
	int a, b;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;

		alist[a].push_back(b);
		life[b]++;
	}

	for (int i = 1; i <= N; i++)
	{
		if (life[i] == 0)
		{
			q.push({ i, 1 });
			total[i] = 1;
		}
	}
}

void bfs()
{
	while (!q.empty())
	{
		Point now = q.front();
		q.pop();

		for (int next : alist[now.n])
		{
			life[next]--;

			if (life[next] == 0)
			{
				q.push({ next, now.cnt + 1 });
				total[next] = now.cnt + 1;
			}
		}
	}
}

void output()
{
	for (int i = 1; i <= N; i++)
	{
		cout << total[i] << " ";
	}
}

int main()
{
	input();
	bfs();
	output();
	return 0;
}