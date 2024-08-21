#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int N;

int card[6] = { 1,2,3,4,5,6 };
int path[5] = { -1,-1,-1,-1,-1 };
int visited[6];
void func(int level, int M) {

	if (level == N) {
		for (int i = 0; i < N; i++)
		{
			cout << card[path[i]] << " ";
		}
		cout << '\n';
		return;
	}
	if (M == 1) {
		for (int i = 0; i < 6; i++)
		{
			path[level] = i;
			func(level + 1, M);
			path[level] = -1;
		}
	}
	else if (M == 2) {
		for (int i = 0; i < 6; i++)
		{
			
			if (level!=0 && i < path[level-1]) {
				continue;
			}
			path[level] = i;
			func(level + 1, M);
			path[level] = -1;
			
			

		}
	}
	else if (M == 3) {//한번 사용한 주사위 번호는 다시사용하지 않는다.
		for (int i = 0; i < 6; i++)
		{
			if (visited[i] == 1) {
				continue;
			}
			visited[i] = 1;
			path[level] = i;
			func(level + 1, M);
			path[level] = -1;
			visited[i] = 0;
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	int M;
	cin >> N >> M;
	func(0, M);

}