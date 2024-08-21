#include <iostream>
#include <queue>
using namespace std;

int visited[6];
int arr[6][6] = {
0,1,0,0,1,0,
0,0,1,0,0,1,
0,0,0,1,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
};

void bfs(int st) {
	queue<int> q;
	visited[st] = 1;
	q.push(st);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < 6; i++)
		{
			if (visited[i] == 1) continue;
			if (arr[now][i] == 0)continue;
			visited[i] = 1;
			q.push(i);
		}
		cout << now << " ";
	}
}

void bfs_remind(int st) {
	queue<int> q;
	q.push(st);
	visited[st] = 1;

	while (!q.empty()) {
		int now = q.front();
		cout << now << " ";

		q.pop();
		for (int i = 0; i < 6; i++)
		{
			if (arr[now][i] == 0)continue;
			if (visited[i] == 1)continue;
			visited[i] = 1;
			q.push(i);
		}
	}
}

void dfs(int st,int sum) {
	cout << st<<" "<<sum<<'\n';
	for (int i = 0; i < 6; i++)
	{
		if (arr[st][i] == 0)continue;
		if (visited[i] == 1)continue;
		visited[i] = 1;
		sum += arr[st][i];
		dfs(i,sum);

	}
}
int main() {
	int T;
	cin >> T;
	//bfs(T);
	bfs_remind(T);
	//visited[T] = 1;;
	//dfs(T,0);
}