#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
int N, M;
int map[101][101];
int visited[101][101];
struct Point {
	int y;
	int x;
};
int direct[4][2]{//상하좌우 방향배열
	-1,0,
	1,0,
	0,-1,
	0,1
};
void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;
		for (int j = 0; j < M; j++)
		{
			map[i][j] = '0' - temp[j]; //string으로 입력받으면 신경써야함
		}
	}
}

void dfs(Point sp) {
	queue<Point> q;
	q.push(sp);
	visited[sp.y][sp.x]=1;//넣고시작
	while (!q.empty()) {
		Point now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = now.y + direct[i][0];
			int nx = now.x + direct[i][1];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M)continue;
			if (visited[ny][nx] >0)continue;
			if (map[ny][nx] == 0)continue;

			visited[ny][nx] = visited[now.y][now.x] + 1;//누적
			q.push({ ny,nx });
		}

	}
	cout << visited[N - 1][M - 1];
}

int main() {
	input();
	dfs({ 0,0 });
}