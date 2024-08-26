#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int tc, n;
int op[4], num[12];
int min_val, max_val;
int visited[4];

void init()
{
	min_val = 21e8;
	max_val = -21e8;
}

void find_answer(int depth, int total)
{
	if (depth == n-1) {
		min_val = min(min_val, total);
		max_val = max(max_val, total);
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (visited[i] == op[i])continue;
		visited[i]++;
		if (i == 0)
		{
			find_answer(depth + 1, total + num[depth + 1]);
		}
		else if (i == 1)
		{
			find_answer(depth + 1, total - num[depth + 1]);
		}
		else if (i == 2)
		{
			find_answer(depth + 1, total * num[depth + 1]);
		}
		else
		{
			find_answer(depth + 1, total / num[depth + 1]);
		}
		visited[i]--;
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> tc;
	for (int t = 1; t <= tc; t++)
	{
		init();
		cin >> n;
		for (int i = 0; i < 4; i++)
		{
			cin >> op[i];
		}
		for (int i = 0; i < n; i++)
		{
			cin >> num[i];
		}

		find_answer(0, num[0]);

		cout << '#' << t << ' ' << abs(min_val - max_val) << '\n';
	}


}