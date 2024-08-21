//탈주범 검거

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <climits>
#include <string>
using namespace std;

int map[51][51];
int visited[51][51];
int result;
int N;//세로
int M;//가로
int maxtime;
struct Point {
	int y;
	int x;
};

int pipedir1[4][2] = {//1 상하좌우
	-1,0,
	1,0,
	0,-1,
	0,1
};
int pipedir2[2][2] = {//2 상하
	-1,0,
	1,0,
};
int pipedir3[2][2] = {//3 좌우
	0,-1,
	0,1
};
int pipedir4[2][2] = {//4 상우
	-1,0,
	0,1
};
int pipedir5[2][2] = {//5 하우
	1,0,
	0,1
};
int pipedir6[2][2] = {//6 하좌
	1,0,
	0,-1,
};
int pipedir7[2][2] = {//7 상좌
	-1,0,
	0,-1,
};

Point sp;
void init() {
	result = 0;
	memset(map, 0, sizeof(map));
	memset(visited, 0, sizeof(visited));
}

void input() {
	cin >> N >> M >> sp.y >> sp.x >> maxtime;//가로,세로,맨홀위치, 시간;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}
}

int cangoback(Point cp, Point bp, int direct) {
	int ny;
	int nx;
	if (direct == 1) {
		for (int i = 0; i < 4; i++)
		{
			ny = cp.y + pipedir1[i][0];
			nx = cp.x + pipedir1[i][1];

			if (bp.y == ny && bp.x == nx) {
				return 1;
			}
		}
		return 0;
	}

	if (direct == 2) {
		for (int i = 0; i < 2; i++)
		{
			ny = cp.y + pipedir2[i][0];
			nx = cp.x + pipedir2[i][1];

			if (bp.y == ny && bp.x == nx) {
				return 1;
			}
		}
		return 0;
	}

	if (direct == 3) {
		for (int i = 0; i < 2; i++)
		{
			ny = cp.y + pipedir3[i][0];
			nx = cp.x + pipedir3[i][1];

			if (bp.y == ny && bp.x == nx) {
				return 1;
			}
		}
		return 0;
	}

	if (direct == 4) {
		for (int i = 0; i < 2; i++)
		{
			ny = cp.y + pipedir4[i][0];
			nx = cp.x + pipedir4[i][1];

			if (bp.y == ny && bp.x == nx) {
				return 1;
			}
		}
		return 0;
	}

	if (direct == 5) {
		for (int i = 0; i < 2; i++)
		{
			ny = cp.y + pipedir5[i][0];
			nx = cp.x + pipedir5[i][1];

			if (bp.y == ny && bp.x == nx) {
				return 1;
			}
		}
		return 0;
	}

	if (direct == 6) {
		for (int i = 0; i < 2; i++)
		{
			ny = cp.y + pipedir6[i][0];
			nx = cp.x + pipedir6[i][1];

			if (bp.y == ny && bp.x == nx) {
				return 1;
			}
		}
		return 0;
	}

	if (direct == 7) {
		for (int i = 0; i < 2; i++)
		{
			ny = cp.y + pipedir7[i][0];
			nx = cp.x + pipedir7[i][1];

			if (bp.y == ny && bp.x == nx) {
				return 1;
			}
		}
		return 0;
	}
}

void countvisited() {//다녀간 칸 갯수 세는 함수
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (visited[i][j]!=0 &&visited[i][j] <= maxtime) {
				result++;
			}
		}
	}
}
void bfs(Point sp) {
	queue<Point> q;
	q.push(sp);
	int timer = 1;
	visited[sp.y][sp.x] = 1;

	while (!q.empty()) {
		Point now = q.front();
		q.pop();
		if (visited[now.y][now.x]==maxtime) {
			break;
		}
		
		int ny = 0;
		int nx = 0;
		Point np;
		bool iscan = false;
		if (map[now.y][now.x] == 1) {
			for (int i = 0; i < 4; i++)
			{

				ny = now.y + pipedir1[i][0];
				nx = now.x + pipedir1[i][1];
				if (ny < 0 || ny >= N || nx < 0 || nx >= M)continue;//범위밖이면
				if (visited[ny][nx] > 0)continue;
				if (map[ny][nx] == 0)continue;
				np.y = ny;
				np.x = nx;
				iscan = cangoback(np, now, map[ny][nx]);
				if (iscan) {
					iscan = false;
					visited[ny][nx] = visited[now.y][now.x]+1;
					q.push(np);
				}
			}
		}
		
		if (map[now.y][now.x] == 2) {
			for (int i = 0; i < 2; i++)
			{

				ny = now.y + pipedir2[i][0];
				nx = now.x + pipedir2[i][1];
				if (ny < 0 || ny >= N || nx < 0 || nx >= M)continue;//범위밖이면
				if (visited[ny][nx] > 0)continue;
				if (map[ny][nx] == 0)continue;
				np.y = ny;
				np.x = nx;
				iscan = cangoback(np, now, map[ny][nx]);
				if (iscan) {
					iscan = false;
					visited[ny][nx] = visited[now.y][now.x] + 1;
					q.push(np);
				}
			}
		}

		if (map[now.y][now.x] == 3) {
			for (int i = 0; i < 2; i++)
			{

				ny = now.y + pipedir3[i][0];
				nx = now.x + pipedir3[i][1];
				if (ny < 0 || ny >= N || nx < 0 || nx >= M)continue;//범위밖이면
				if (visited[ny][nx] > 0)continue;
				if (map[ny][nx] == 0)continue;
				np.y = ny;
				np.x = nx;
				iscan = cangoback(np, now, map[ny][nx]);
 				if (iscan) {
					iscan = false;
					visited[ny][nx] = visited[now.y][now.x] + 1;
					q.push(np);
				}
			}
		}

		if (map[now.y][now.x] == 4) {
			for (int i = 0; i < 2; i++)
			{

				ny = now.y + pipedir4[i][0];
				nx = now.x + pipedir4[i][1];
				if (ny < 0 || ny >= N || nx < 0 || nx >= M)continue;//범위밖이면
				if (visited[ny][nx] > 0)continue;
				if (map[ny][nx] == 0)continue;
				np.y = ny;
				np.x = nx;
				iscan = cangoback(np, now, map[ny][nx]);
				if (iscan) {
					iscan = false;
					visited[ny][nx] = visited[now.y][now.x] + 1;
					q.push(np);
				}
			}
		}

		if (map[now.y][now.x] == 5) {
			for (int i = 0; i < 2; i++)
			{

				ny = now.y + pipedir5[i][0];
				nx = now.x + pipedir5[i][1];
				if (ny < 0 || ny >= N || nx < 0 || nx >= M)continue;//범위밖이면
				if (visited[ny][nx] > 0)continue;
				if (map[ny][nx] == 0)continue;
				np.y = ny;
				np.x = nx;
				iscan = cangoback(np, now, map[ny][nx]);
				if (iscan) {
					iscan = false;
					visited[ny][nx] = visited[now.y][now.x] + 1;
					q.push(np);
				}
			}
		}

		if (map[now.y][now.x] == 6) {
			for (int i = 0; i < 2; i++)
			{

				ny = now.y + pipedir6[i][0];
				nx = now.x + pipedir6[i][1];
				if (ny < 0 || ny >= N || nx < 0 || nx >= M)continue;//범위밖이면
				if (visited[ny][nx] > 0)continue;
				if (map[ny][nx] == 0)continue;
				np.y = ny;
				np.x = nx;
				iscan = cangoback(np, now, map[ny][nx]);
				if (iscan) {
					iscan = false;
					visited[ny][nx] = visited[now.y][now.x] + 1;
					q.push(np);
				}
			}
		}

		if (map[now.y][now.x] == 7) {
			for (int i = 0; i < 2; i++)
			{

				ny = now.y + pipedir7[i][0];
				nx = now.x + pipedir7[i][1];
				if (ny < 0 || ny >= N || nx < 0 || nx >= M)continue;//범위밖이면
				if (visited[ny][nx] > 0)continue;
				if (map[ny][nx] == 0)continue;
				np.y = ny;
				np.x = nx;
				iscan = cangoback(np, now, map[ny][nx]);
				if (iscan) {
					iscan = false;
					visited[ny][nx] = visited[now.y][now.x] + 1;
					q.push(np);
				}
			}
		}
	}
	countvisited();
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		init();
		input();
		bfs(sp);
		cout << "#" << tc << " " << result << '\n';
	}

}