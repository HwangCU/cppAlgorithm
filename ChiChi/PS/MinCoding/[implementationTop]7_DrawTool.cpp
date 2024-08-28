#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N, Q;
int map[11][11];
int ans = 0;
struct Draw
{
	int color, y1, x1, y2, x2;
};
vector<Draw> v;

void input()
{
	cin >> N >> Q;
	for (int i = 0; i < Q; i++)
	{
		int color, y1, x1, y2, x2;
		cin >> color >> y1 >> x1 >> y2 >> x2;
		v.push_back({ color,y1,x1,y2,x2 });
	}
}

void makeMap()
{
	memset(map, 0, sizeof(0));
	for (int i = 0; i < v.size(); i++)
	{
		int color = v[i].color;
		int y1 = v[i].y1;
		int x1 = v[i].x1;
		int y2 = v[i].y2;
		int x2 = v[i].x2;

		if (y1 > y2)
		{
			int temp = y1;
			y1 = y2;
			y2 = temp;
		}
		if (x1 > x2)
		{
			int temp = x1;
			x1 = x2;
			x2 = temp;
		}
		for (int j = y1; j <= y2; j++)
		{
			for (int k = x1; k <= x2; k++)
			{
				if (map[j][k] < color)
					map[j][k] = color;
			}
		}
	}
}

void solve()
{
	makeMap();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] > 0)
			{
				int color = map[i][j];
				int size = 1;
				while (1)
				{
					if (map[i + size][j + size] == color)
						size++;
					else
						break;
				}
				if (ans < size)
					ans = size;
			}
		}
	}
}

int main()
{
	input();
	solve();
	cout << ans * ans;
}