//바로 직전의 값이랑 현재 다루는 값이랑 같으면 컨티뉴...
#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[9];
int path[9];
int visited[9];

void func(int level) {
	if (level == M) {


		for (int i = 0; i < M; i++)
		{
			cout << path[i] << " ";

		}
		cout << '\n';
		return;
	}
	int temp= 0;
	for (int i = 0; i < N; i++)
	{


		if (visited[i] == 1 || temp==arr[i])continue;

		temp = arr[i];
		visited[i] += 1;
		path[level] = arr[i];
		func(level + 1);
		path[level] = 0;
		visited[i] -= 1;
	}


}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];

	}
	sort(arr, arr + N);
	func(0);

}