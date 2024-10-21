#include <iostream>
#include <algorithm>
using namespace std;

int N;
int Map[11][11];
int visited[11][11];
int Mini = 21e8;
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

struct Point {
	int y, x;
};

void input() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> Map[i][j];
		}
	}
}

void dfs(int seed, int sum, Point now) {

	if (seed == 3) {
		Mini = min(sum, Mini);
		return;
	}

	if (sum > Mini) {
		return;
	}

	for (int i = 1; i < N - 1; i++)
	{
		for (int j = 1; j < N - 1; j++)
		{
			bool flag = true;
			if (visited[i][j]) continue;
			int local_sum = Map[i][j];

			// 꽃이 핀곳 check
			for (int d = 0; d < 4; d++)
			{
				Point next = { i + dy[d], j + dx[d] };
				if (visited[next.y][next.x]) {
					flag = false;
					break;
				}

			}
			// 꽃이 필 곳이 다 빈땅이면
			if (flag) {
				visited[i][j] = 1;
				for (int d2 = 0; d2 < 4; d2++)
				{
					Point next = { i + dy[d2], j + dx[d2] };
					visited[next.y][next.x] = 1;
					local_sum += Map[next.y][next.x];
				}
			}
			else continue;

			dfs(seed + 1, sum + local_sum, { i, j });
			visited[i][j] = 0;
			for (int d2 = 0; d2 < 4; d2++)
			{
				Point next = { i + dy[d2], j + dx[d2] };
				visited[next.y][next.x] = 0;
			}
		}
	}
}
int main() {
	input();
	dfs(0, 0, { 1,1 });
	cout << Mini;
}