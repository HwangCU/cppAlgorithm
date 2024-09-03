#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, M;
int map[1001][1001];

int dx[] = { 1,0,-1,0 }; //우하좌상
int dy[] = { 0,1,0,-1 };
void print()
{
	cout << '\n';
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << map[i][j];
		}
		cout << '\n';
	}
}
struct Point
{
	int x, y;
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;

	for (int t = 0; t < T; ++t)
	{
		int result = 0;
		cin >> N >> M;
		queue<Point> q;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				char ch;
				cin >> ch;
				if (ch == 'W') {
					map[i][j] = 0;
					q.push({ i,j });
				}
				else
					map[i][j] = -1;
			}
		}

		while (!q.empty()) {
			Point cp = q.front();
			q.pop();
			//print();
			for (int d = 0; d < 4; d++) {
				int nx = cp.x + dx[d];
				int ny = cp.y + dy[d];

				if ((nx >= 0 && nx < N) && (ny >= 0 && ny < M)) {
					if (map[nx][ny] == -1) {
						map[nx][ny] = map[cp.x][cp.y] + 1;
						result += map[nx][ny];
						q.push({ nx,ny });
					}
				}
			}
		}
		cout << "#" << t + 1 << ' ' << result << '\n';

	}

}