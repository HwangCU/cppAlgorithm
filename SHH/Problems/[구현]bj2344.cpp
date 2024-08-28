//거울 구현 like swea핀볼
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int N, M;
int map[1001][1001];
int direct[4][2] = {
	0,1,//우
	-1,0,//상
	0,-1,//좌
	1,0//하
};
struct Point {
	int y;
	int x;
};
vector<Point> resultlist;
int numbering[2001][2001];
void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}
}


void func(Point cp, int dir) {
	queue<Point> q;
	q.push(cp);
	int directnumb = dir;
	if (map[cp.y][cp.x] == 1) {
		if (directnumb == 0) {//우
			directnumb = 1;
		}
		else if (directnumb == 1) {//상
			directnumb = 0;
		}
		else if (directnumb == 2) {//좌
			directnumb = 3;
		}
		else if (directnumb == 3) {//하
			directnumb = 2;
		}
	}
	while (!q.empty()) {
		Point now = q.front();
		q.pop();

		int ny = now.y + direct[directnumb][0];
		int nx = now.x + direct[directnumb][1];

		if (ny < 0 || ny >= N || nx < 0 || nx >= M) {
			resultlist.push_back({ ny, nx });
			break;
		}
		if (map[ny][nx] == 1) {//거울만나면? 방향바꿔
			if (directnumb == 0) {//우
				directnumb = 1;
			}
			else if (directnumb == 1) {//상
				directnumb = 0;
			}
			else if (directnumb == 2) {//좌
				directnumb = 3;
			}
			else if (directnumb == 3) {//하
				directnumb = 2;
			}
		}
		q.push({ ny,nx });
	}
	return;
}

void process() {
	int index = 0;

	for (int i = 0; i < N; i++)//처음아래로내리기
	{
		index++;
		numbering[i][1500] = index;
		func({ i,0 }, 0);
	}


	for (int j = 0; j < M; j++)//-->>>
	{
		index++;
		numbering[2000][j] = index;
		if (index == 4) {
			int a = 1;
		}
		func({ N - 1,j }, 1);
	}

	for (int i = N - 1; i >= 0; i--)//위로
	{
		index++;
		numbering[i][2000] = index;
		func({ i,M - 1 }, 2);
	}

	for (int j = M - 1; j >= 0; j--)//왼쪽
	{
		index++;
		numbering[1500][j] = index;
		func({ 0,j }, 3);
	}


}
void printresult() {
	for (int i = 0; i < resultlist.size(); i++)
	{

		if (resultlist[i].y == -1) {//위로박혀있는거임
			cout << numbering[1500][resultlist[i].x] << " ";
		}
		else if (resultlist[i].x == -1) {//왼쪽박힘
			cout << numbering[resultlist[i].y][1500] << " ";
		}
		else if (resultlist[i].y == N) {//아래로박힘
			cout << numbering[2000][resultlist[i].x] << " ";
		}
		else if (resultlist[i].x == M) {//오른쪽박힘
			cout << numbering[resultlist[i].y][2000] << " ";
		}
	}
}
int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	input();
	process();
	printresult();


	return 0;
}