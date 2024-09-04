#include <iostream>

using namespace std;

int N, S, E;

int sum = 0;
int max_height = 0;
int calander[365][100];
int DAT[365];

void init()
{
	fill(calander[0], calander[0] + 365 * 100, 0);
	fill(DAT, DAT + 365, 0);
}

void input()
{
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		cin >> S >> E;

		for (int j = S-1; j <= E-1; j++)
		{
			DAT[j]++;
		}
	}
}

void func()
{
	int cnt = 0;
	for (int i = 0; i < 365; i++)
	{
		if (DAT[i] >= 1)
		{
			if (DAT[i] > max_height)
				max_height = DAT[i];
			cnt++;
		}

		if (DAT[i] == 0)
		{
			sum += max_height * cnt;
			max_height = 0;
			cnt = 0;
		}
	}
	sum += max_height * cnt;
	
}

int main()
{
	init();
	input();
	func();
	cout << sum;

	return 0;
}