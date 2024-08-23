#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
int result = 21e8;
int K;
int map[51][51];
int tempmap[51][51];

int direct[4][2] = {
	0,1,//오른쪽
	1,0, //아래쪽
	0,-1,
	-1,0
};

int nowy;
int nowx;

void caclresult() {
	int tempresult = 0;
	for (int i = 0; i < N; i++)
	{
		tempresult = 0;
		for (int j = 0; j < M; j++)
		{
			tempresult += map[i][j];
		}
		result = min(result, tempresult);
	}
}

void dfs(int ny, int nx, int dir, int s, int centery, int centerx, int before) {
	if (ny == nowy && nx == nowx && dir == 3) {
		return;
	}
	int nexty = ny + direct[dir][0];
	int nextx = nx + direct[dir][1];

	if (nexty < centery - s || nexty > centery + s || nextx < centerx - s || nextx > centerx + s) {//범위밖이면 방향틀어
		dfs(ny, nx, dir + 1, s, centery, centerx, before);
	}
	else {
		int tempval = map[nexty][nextx];
		map[nexty][nextx] = before;
		dfs(nexty, nextx, dir, s, centery, centerx, tempval);
	}
}

void cacl(int cy, int cx, int s)//시계방향회전
{
	for (int i = 1; i <= s; i++)//제일 안쪽부터
	{
		nowy = cy - i; //시작지점
		nowx = cx - i; //시작지점
		dfs(nowy, nowx, 0, i, cy, cx, map[nowy][nowx]);
	}
}

void copyMap(int dest[51][51], int src[51][51]) {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			dest[i][j] = src[i][j];
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	cin >> N >> M >> K;

	vector<vector<int>> operations(K, vector<int>(3));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < K; i++)
	{
		cin >> operations[i][0] >> operations[i][1] >> operations[i][2];
	}

	vector<int> perm(K);
	for (int i = 0; i < K; i++) perm[i] = i;

	do {
		copyMap(tempmap, map);
		for (int i = 0; i < K; i++) {
			int one = operations[perm[i]][0];
			int two = operations[perm[i]][1];
			int three = operations[perm[i]][2];
			cacl(one - 1, two - 1, three);
		}
		caclresult();
		copyMap(map, tempmap);
	} while (next_permutation(perm.begin(), perm.end()));

	cout << result;
	return 0;
}
