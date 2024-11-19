#include <iostream>

using namespace std;

char Map[6][6];
int visited[6][6];
int R, C, K;
int ans = 0;
int dy[4] = { -1,1,0,0, };
int dx[4] = { 0,0,-1,1 };

struct Point
{
	int y, x;
};
//input
void input() {
	cin >> R >> C >> K;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> Map[i][j];
		}
	}
}

void dfs(int lev, Point now) {
	//거리가 K이면 탈출
	if (lev == K-1 && now.y == 0 && now.x == C-1) {
		ans++;
		return;
	}

	for (int d = 0; d < 4; d++)
	{
		Point next = { now.y + dy[d], now.x + dx[d] };

		if (next.y < 0 || next.y >= R || next.x < 0 || next.x >= C) continue;
		if (Map[next.y][next.x] == 'T') continue;
 		if (visited[next.y][next.x]) continue;

		visited[next.y][next.x] = 1;
		dfs(lev + 1, next);
		visited[next.y][next.x] = 0;

	}
}

int main() {
	input();
	visited[R - 1][0] = 1;
	dfs(0, { R - 1,0 });
	cout << ans;
}