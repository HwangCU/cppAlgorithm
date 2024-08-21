#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct Point {
	int y;
	int x;
	int cost;
};

int map[101][101];
int dist[101][101];
int N, M;
Point sp ;
Point ep ;
struct compare {
	bool operator() (Point a, Point b) {
		return a.cost > b.cost;
	}
};
int direct[4][2] = {
	-1,0,
	1,0,
	0,-1,
	0,1
};

void init() {
	memset(map, -1, sizeof(map));
}

void input() {
	cin >> N >> M;
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}
	sp = { 0,0,map[0][0] };
}

void dijkstra(Point sp) {
	priority_queue<Point, vector<Point>, compare> pq;
	pq.push(sp);
	dist[sp.y][sp.x] = map[sp.y][sp.x];

	while (!pq.empty()) {
		Point now = pq.top();
		pq.pop();
		if (dist[now.y][now.x] < now.cost) {//가지치기
			continue;
		}
		for (int i = 0; i < 4; i++)
		{
			int ny = now.y + direct[i][0];
			int nx = now.x + direct[i][1];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
			int nextcost = now.cost + map[ny][nx];
			if (nextcost > dist[ny][nx]) continue;
			dist[ny][nx] = nextcost;
			pq.push({ny,nx,nextcost});
		}
	}
}

int main() {
	init();
	input();
	fill(&dist[0][0], &dist[0][0] + 101*101, 21e8);
	dijkstra(sp);
	cout << dist[N - 1][M - 1];
}