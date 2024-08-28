#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int N;
char map[101][101];
char rgmap[101][101];
int visited[101][101];
int result, rgresult;
int direct[4][2] = {
	-1,0,
	1,0,
	0,-1,
	0,1
};
struct Point {
	int y;
	int x;
};

void bfs(Point sp) {
	queue<Point> q;
	q.push(sp);
	visited[sp.y][sp.x] = 1;
	char currenttype = map[sp.y][sp.x];
	
	while (!q.empty()) {
		Point now = q.front();
		q.pop();
		int ny, nx;
		for (int i = 0; i < 4; i++)
		{
			ny = now.y + direct[i][0];
			nx = now.x + direct[i][1];

			if (ny < 0 || ny >= N || nx < 0 || nx >= N)continue;
			if (visited[ny][nx] == 1)continue;
			if (map[ny][nx] != currenttype)continue;

			visited[ny][nx] = 1;
			q.push({ ny,nx });
		}
	}
	result++;
}

void rgbfs(Point sp) {
	queue<Point> q;
	q.push(sp);
	visited[sp.y][sp.x] = 1;
	char currenttype = rgmap[sp.y][sp.x];

	while (!q.empty()) {
		Point now = q.front();
		q.pop();
		int ny, nx;
		for (int i = 0; i < 4; i++)
		{
			ny = now.y + direct[i][0];
			nx = now.x + direct[i][1];

			if (ny < 0 || ny >= N || nx < 0 || nx >= N)continue;
			if (visited[ny][nx] == 1)continue;
			if (rgmap[ny][nx] != currenttype)continue;

			visited[ny][nx] = 1;
			q.push({ ny,nx });
		}
	}
	rgresult++;
}

void process() {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visited[i][j] == 1)continue;
			else {
				bfs({ i,j });
			}
		}
	}

	memset(visited, 0, sizeof(visited));//초기화

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visited[i][j] == 1)continue;
			else {
				rgbfs({ i,j });
			}
		}
	}
}
int main() {
	//freopen("input.txt", "r", stdin);
	result = 0;
	rgresult = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'G') {
				rgmap[i][j] = 'R';
			}
			else {
				rgmap[i][j] = map[i][j];
			}
		}
	}

	process();
	cout << result << " "<<rgresult;
}