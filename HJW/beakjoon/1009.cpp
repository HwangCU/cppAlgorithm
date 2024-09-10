#include <iostream>
#include <cmath>

using namespace std;

int one[] = { 1 };
int two[] = { 2,4,8,6 };
int three[] = { 3,9,7,1 };
int four[] = { 4, 6 };
int five[] = { 5 };
int six[] = { 6 };
int seven[] = { 7, 9, 3, 1 };
int eight[] = { 8,4,2,6 };
int nine[] = { 9,1 };


int main()
{
	int T;
	int a, b;
	int nam;


	long long c;

	cin >> T;

	for (int t = 0; t < T; t++)
	{
		cin >> a >> b;

		nam = a % 10;
		b -= 1;
		if (nam == 1)
		{
			cout << 1 << "\n";
		}
		else if (nam == 0)
		{
			cout << 10 << "\n";
		}

		else if (nam == 2)
		{
			int o = b % 4;
			cout << two[o] << "\n";
		}

		else if (nam == 3)
		{
			int o = b % 4;
			cout << three[o] << "\n";
		}

		else if (nam == 4)
		{
			int o = b % 2;
			cout << four[o] << "\n";
		}

		else if (nam == 5)
		{
			cout << 5 << "\n";
		}

		else if (nam == 6)
		{
			cout << 6 << "\n";
		}

		else if (nam == 7)
		{
			int o = b % 4;
			cout << seven[o] << "\n";
		}

		else if (nam == 8)
		{
			int o = b % 4;
			cout << eight[o] << "\n";
		}

		else if (nam == 9)
		{
			int o = b % 2;
			cout << nine[o] << "\n";
		}
	}

	return 0;
}