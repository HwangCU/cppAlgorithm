#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
	int n, m, k;
	char map[20][20];
	int dy[4] = { -1,1,0,0 };
	int dx[4] = { 0,0,-1,1 };

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == '@')
			{
				map[i][j] = '%';
				for (int l = 0; l < 4; l++)
				{
					for (int o = 1; o <= k; o++)
					{
						int ny = dy[l] * o + i;
						int nx = dx[l] * o + j;

						if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
						else
						{
							if (map[ny][nx] == '#') break;
							else if (map[ny][nx] == '@') continue;
							else map[ny][nx] = '%';
						}
					}
				}
			}
		}
	}

	//출력
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << map[i][j];
		}
		cout << "\n";
	}

}