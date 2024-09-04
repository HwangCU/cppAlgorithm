#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int cal[366];
int answer = 0;

int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> n;
	int start, end;
	for (int i = 0; i < n; i++)
	{
		cin >> start >> end;
		for (int j = start; j <= end; j++)
		{
			cal[j]++;
		}
	}

	int width = 0, height = 0;
	for (int i = 1; i <= 365; i++)
	{
		if (cal[i] >= 1) {
			height = max(height, cal[i]);
			width++;
		}
		else {
			answer += (width * height);
			height = 0;
			width = 0;
		}
	}
	answer += (width * height);

	cout << answer;
}