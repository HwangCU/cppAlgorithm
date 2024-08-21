#include <iostream>

using namespace std;

int visited[8];
int path[8];
int N, M;
int resultcount = 0;
void func(int level) {
	if (level == N) {
		resultcount++;
        return;
	}

	for (int i = 1; i <= N; i++)
	{
		if (visited[i] == 1) {
			continue;
		}
		visited[i] = 1;
		path[level] = i;
		func(level + 1);
		path[level] = 0;
		visited[i] = 0;
	}

}

int main() {

	cin >> N;

	func(0);

	cout << resultcount;
	return 0;
}