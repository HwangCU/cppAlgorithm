#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int N;

char card[3] = { 'A','B','C' };
int path[3] = { -1,-1,-1 };
void func(int level) {
	
	if (level == 3) {
		for (int i = 0; i < 3; i++)
		{
			cout << card[path[i]] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < strlen(card); i++)
	{
		path[level] = i;
		func(level + 1);
		path[level] = -1;
	}

}

int main() {
	//freopen("input.txt", "r", stdin);
	

	func(0);

}