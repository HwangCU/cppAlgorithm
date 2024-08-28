#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int map[1000][1000];
int n, t = 0;
int dy[5] = { 0, -1, 0, 1, 0 };
int dx[5] = { 0, 0, 1, 0,-1 };

void print()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

struct Bumb
{
	int idx;
	int y;
	int x;
};

struct compare {
	bool operator()(Bumb a, Bumb b)
	{
		return a.idx > b.idx;
	}
};

priority_queue<Bumb, vector<Bumb>, compare> pq;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int temp;
			cin >> temp;
			pq.push({ temp,i,j });
		}
	}

	
	while (pq.size())
	{
		Bumb now = pq.top(); pq.pop();
		if (map[now.y][now.x]) continue;
		t = now.idx;

		for (int i = 0; i < 5; i++)
		{
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

			map[ny][nx] = 1;

		}
		//print();
	}

	cout << t << "초\n";
}