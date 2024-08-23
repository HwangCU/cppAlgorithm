#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>

using namespace std;

int tc, k, answer;
int magnet[4][8];
int top[4];


void init()
{
	answer = 0;
	fill(top, top + 4, 0);
}

void rotate(int prev_select, int now, int direction)
{
	int prev = now - 1, next = now + 1;
	if (prev_select != 1 && prev >= 0)
	{
		int prev_2 = magnet[prev][(top[prev] + 2) % 8] ;
		int now_6 = magnet[now][(top[now] + 6) % 8];
		if (prev_2 != now_6) {
		
			rotate(-1, prev, -direction );
		}
	}
	if (prev_select != -1 && next <= 3)
	{
		int now_2 = magnet[now][(top[now] + 2) % 8];
		int next_6 = magnet[next][(top[next] + 6) % 8];

		if (now_2 != next_6) {
			rotate(1, next, -direction);
		}
	}


	top[now] -= direction;
	top[now] = (top[now] + 8) % 8;
	
}


int main()
{
	cin >> tc;

	for (int t = 1; t <= tc; t++)
	{
		init();

		cin >> k;

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				cin >> magnet[i][j];
			}
		}

		int m_num, direction;
		for (int i = 0; i < k; i++)
		{
			cin >> m_num >> direction;
			rotate(0, m_num-1, direction);
		}

		for (int i = 0; i < 4; i++)
		{
			answer += (magnet[i][top[i]] == 0? 0 : pow(2,i));
		}

		cout << '#' << t << ' ' << answer << '\n';
	}
}