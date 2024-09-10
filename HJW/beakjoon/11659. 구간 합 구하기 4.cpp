// beakjoon 11659. 구간 합 구하기 4

#include <iostream>

using namespace std;

int N, M;
int arr[100001];
int sum_arr[100001];

void init()
{
	fill(arr, arr + 100001, 0);
	fill(sum_arr, sum_arr + 100001, 0);
}

void input()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		if (i == 0)
			sum_arr[i] = arr[i];
		else
			sum_arr[i] = sum_arr[i - 1] + arr[i];
	}
}

void func()
{
	int a, b;

	for (int i = 0; i < M; i++)
	{
		int sum = 0;
		cin >> a >> b;
	
		cout << sum_arr[b - 1] - sum_arr[a - 2] << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	init();
	input();
	func();

	return 0;
}