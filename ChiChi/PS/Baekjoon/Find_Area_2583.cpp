#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;
// 맵은 (N,M)임
int map[101][101] = { 0 };
int visited[101][101];
vector<int> ans;
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
struct Point
{
	int y, x;
};
void input()
{
	cin >> M >> N >> K;
	for (int i = 0; i < K; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		// make map
		for (int x = x1; x < x2; x++)
		{
			for (int y = y1; y < y2; y++)
			{
				map[M-y-1][x] = 1;
			}
		}
	}
}

void print() {
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << map[i][j]<<' ';
		}
		cout << '\n';
	}
	cout << "\n";
}

void bfs(Point st)
{
	int sum = 1;
	queue<Point> q;
	q.push(st);
	visited[st.y][st.x] = 1;
	while (!q.empty()) {
		Point now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (ny < 0 || ny >= M || nx < 0 || nx >= N) continue;
			if (visited[ny][nx]) continue;
			if (map[ny][nx]) continue;
			visited[ny][nx] = 1;
			sum++;
			q.push({ ny,nx });
		}
	}
	ans.push_back(sum);
}

void solve() {
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visited[i][j] && map[i][j] == 0) {
				bfs({ i,j });
			}
		}
	}
}

int main()
{
	input();
	solve();
	//print();
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << ' ';
	}
}