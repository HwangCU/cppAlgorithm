#include <iostream>

using namespace std;

int visited[15]; // 열 방문 확인
int slash[30]; // '/' 대각선 방문 확인 level + i
int backslash[30]; // '\' 대각선 방문 확인 level - i + (N-1)
int N;
int resultcount = 0;

void func(int level) {
	if (level == N) {
		resultcount++;
		return;
	}

	for (int i = 0; i < N; i++) {
		if (visited[i] || slash[level + i] || backslash[level - i + N - 1]) {
			continue;
		}

		visited[i] = slash[level + i] = backslash[level - i + N - 1] = 1;
		func(level + 1);
		visited[i] = slash[level + i] = backslash[level - i + N - 1] = 0;
	}
}

int main() {
	cin >> N;

	func(0);

	cout << resultcount;
	return 0;
}
