#include <iostream>
#include <string>

using namespace std;

string video[64];

// 재귀함수
void printCompResult(int size, int y, int x)
{
	char curr = video[y][x];

	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++)
			if (video[i][j] != curr)
			{
				cout << '(';
				printCompResult(size / 2, y, x);
				printCompResult(size / 2, y, x + size / 2);
				printCompResult(size / 2, y + size / 2, x);
				printCompResult(size / 2, y + size / 2, x + size / 2);
				cout << ')';
				return;
			}
	}
	cout << curr;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> video[i];

	printCompResult(N, 0, 0);

	return 0;
}