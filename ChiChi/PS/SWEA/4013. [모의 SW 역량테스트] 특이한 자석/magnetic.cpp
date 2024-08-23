#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int K, ans;
int Gear[4][8];
struct Rotate
{
	int num; int wise;
};
Rotate R[20];

void input()
{
	cin >> K;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cin >> Gear[i][j];
		}
	}

	for (int i = 0; i < K; i++)
	{
		cin >> R[i].num >> R[i].wise;
	}
}

void turnWise(int num, int w)
{
	// 시계로 돌리기
	if (w == 1)
	{
		int temp = Gear[num][7];

		for (int i = 7; i >= 1; i--)
		{
			Gear[num][i] = Gear[num][i - 1];
		}
		Gear[num][0] = temp;
	}
	// 반시계로 돌리기
	else if (w == -1)
	{
		int temp = Gear[num][0];

		for (int i = 0; i < 7; i++)
		{
			Gear[num][i] = Gear[num][i + 1];
		}
		Gear[num][7] = temp;
	}
}

void solve()
{
	// 0 0 1 0 0 1 0 0 >> 시계방향 회전 >> 0 0 0 1 0 0 1 0
	// 1 = 시계 방향 회전, -1 = 반시계 방향 회전
	for (int i = 0; i < K; i++)
	{
		int gearNum = R[i].num - 1;
		int wise = R[i].wise;
		int rotate_list[4] = { 0 };

		rotate_list[gearNum] = wise;
		// 0번 톱니
		if (gearNum == 0)
		{
			if (Gear[gearNum][2] != Gear[gearNum + 1][6])
				rotate_list[1] = -rotate_list[0];

			if (Gear[gearNum + 1][2] != Gear[gearNum + 2][6] && rotate_list[1] != 0)
				rotate_list[2] = -rotate_list[1];

			if (Gear[gearNum + 2][2] != Gear[gearNum + 3][6] && rotate_list[2] != 0)
				rotate_list[3] = -rotate_list[2];
		}
		// 1번 톱니
		else if (gearNum == 1)
		{
			// 1번에서 0번 톱니
			if (Gear[gearNum - 1][2] != Gear[gearNum][6])
				rotate_list[0] = -rotate_list[1];
			// 1번 2번 톱니
			if (Gear[gearNum][2] != Gear[gearNum + 1][6])
				rotate_list[2] = -rotate_list[1];
			// 1번에서 3 톱니
			if (Gear[gearNum + 1][2] != Gear[gearNum + 2][6] && rotate_list[2] != 0)
				rotate_list[3] = -rotate_list[2];
		}
		// 2번 톱니
		else if (gearNum == 2)
		{
			// 2번에서 1번 톱니
			if (Gear[gearNum - 1][2] != Gear[gearNum][6])
				rotate_list[1] = -rotate_list[2];
			// 2번에서 0번 톱니
			if (Gear[gearNum - 2][2] != Gear[gearNum - 1][6] && rotate_list[1] != 0)
				rotate_list[0] = -rotate_list[1];
			// 2번에서 4번 톱니
			if (Gear[gearNum][2] != Gear[gearNum + 1][6])
				rotate_list[3] = -rotate_list[2];
		}
		// 3번 톱니
		else if (gearNum == 3)
		{
			// 3번에서 2번
			if (Gear[gearNum - 1][2] != Gear[gearNum][6])
				rotate_list[2] = -rotate_list[3];
			// 1번
			if (Gear[gearNum - 2][2] != Gear[gearNum - 1][6] && rotate_list[2] != 0)
				rotate_list[1] = -rotate_list[2];
			// 0번
			if (Gear[gearNum - 3][2] != Gear[gearNum - 2][6] && rotate_list[1] != 0)
				rotate_list[0] = -rotate_list[1];
		}
		// 톱니 돌리기
		for (int j = 0; j < 4; j++)
		{
			if (rotate_list[j] != 0)
			{
				turnWise(j, rotate_list[j]);
			}
		}
	}
	// 답구하기
	ans = 0;
	for (int i = 0; i < 4; i++)
	{
		if (Gear[i][0] == 1)
		{
			ans += pow(2, i);
		}
	}
}

int main()
{
	//freopen("sample_input.txt", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		input();
		solve();
		cout << '#' << t << ' ' << ans<<'\n';
	}
}