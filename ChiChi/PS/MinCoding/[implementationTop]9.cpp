#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

char map[8][8];
int N;
// 상, 하, 좌, 우, 왼쪽위, 오른쪽위, 왼쪽아래, 오른쪽아래
int dy[] = { -1,1,0,0,-1,-1,1,1 };
int dx[] = { 0,0,-1,1,-1,1,-1,1 };
struct Point
{
	int y;
	int x;
};
Point P[64];
void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int y, x;
		cin >> y >> x;
		P[i] = {x,y };
	}
}
void print()
{
	for (int i = 7; i >= 0; i--)
	{
		for (int j = 0; j <= 7; j++)
		{
			cout << map[i][j];
		}
		cout << '\n';
	}
	cout << '\n';
}

void solve()
{
	for (int i = 0; i < N; i++)
	{
		if (i % 2 == 0)
			map[P[i].y][P[i].x] = '@';
		else if (i % 2 == 1)
			map[P[i].y][P[i].x] = 'O';
		//print();
		for (int d = 0; d < 8; d++)
		{
			int ny = P[i].y + dy[d];
			int nx = P[i].x + dx[d];
			int cnt_black = 0;
			int cnt_white = 0;
			int dir = 1;
			bool action = false;
			while (1)
			{
				if (ny < 0 || ny >= 8 || nx < 0 || nx >= 8)
				{
					cnt_black = 0;
					cnt_white = 0;
					break;
				}

				if (map[ny][nx] == '_')
				{
					cnt_black = 0;
					break;
				}

				if (i % 2 == 0)
				{
					if (map[ny][nx] == 'O')
					{
						cnt_black++;
						dir++;
					}
					if (map[ny][nx] == '@')
					{
						action = true;
						break;
					}
				}
				else if (i % 2 == 1)
				{
					if (map[ny][nx] == '@')
					{
						cnt_white++;
						dir++;
					}
					if (map[ny][nx] == 'O')
					{
						action = true;
						break;
					}
				}
				ny = P[i].y + dy[d] * dir;
				nx = P[i].x + dx[d] * dir;
			}
			//흑돌로 뒤집기
			if (cnt_black > 0 && action)
			{
				for (int j = 1; j <= cnt_black; j++)
				{
					map[P[i].y + dy[d] * j][P[i].x + dx[d] * j] = '@';
					//print();
				}
			}
			//백돌로 뒤집기
			if (cnt_white > 0 && action)
			{
				for (int j = 1; j <= cnt_white; j++)
				{
					map[P[i].y + dy[d] * j][P[i].x + dx[d] * j] = 'O';
					//print();
				}
			}
		}
	}
}

int main()
{
	memset(map, '_', sizeof(map));
	//freopen("input.txt", "r", stdin);
	input();
	solve();
	for (int i = 7; i >= 0; i--)
	{
		for (int j = 0; j <= 7; j++)
		{
			cout << map[i][j];
		}
		cout << '\n';
	}
}