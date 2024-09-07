// SWEA 7569. 토마토
/*
풀이법
상자의 모든 배열을 뒤져야 함.
이렇게 되면 시간이 초과될 것 같음.
토마토의 좌표를 저장하고, 익은 토마토의 옆만 확인해서 넣기. 

좌표 구조체 Point에 일수도 추가
floodfill처럼 일수 계산

모든 큐가 비고, 일 수 출력 시 상자 모두 검색
안익은 토마토가 있다면 -1 출력
*/

#include <iostream>
#include <queue>

using namespace std;

struct Point
{
	int z;
	int y;
	int x;
	int day;
};

int box[100][100][100];
int M, N, H;
int day;
queue<Point> q;

int dz[] = { -1,1,0,0,0,0 };
int dy[] = { 0,0,-1,1,0,0 };
int dx[] = { 0,0,0,0,-1,1 };

void init()
{
	fill(box[0][0], box[0][0] + 100 * 100 * 100, 0);
}

void input()
{
	cin >> M >> N >> H;

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				cin >> box[i][j][k];
				if (box[i][j][k] == 1)
					q.push({ i,j,k,0 });
			}
		}
	}
}

void bfs()
{
	int flag = 1;

	while (!q.empty())  // queue가 빌 때까지
	{
		Point now = q.front();
		q.pop();

		for (int i = 0; i < 6; i++)
		{
			int nz = dz[i] + now.z;
			int ny = dy[i] + now.y;
			int nx = dx[i] + now.x;

			if (nz < 0 || nz >= H || ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue;

			if (box[nz][ny][nx] == 1 || box[nz][ny][nx] == -1)
				continue;

			if (box[nz][ny][nx] == 0)
			{
				box[nz][ny][nx] = 1;
				q.push({ nz, ny, nx, now.day + 1 });
				day = now.day + 1;
			}
		}
	}


}

void output()
{
	int flag = 0;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				if (box[i][j][k] == 0)
				{
					flag = 1;
				}
			}
		}
	}

	if (flag == 1)
	{
		cout << -1;
	}
	else
	{
		cout << day;
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	init();
	input();
	bfs();
	output();

	return 0;
}