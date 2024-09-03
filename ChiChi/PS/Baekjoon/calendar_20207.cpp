#include <iostream>
#include <algorithm>
using namespace std;

int DAT[366] = { 0 };
int endV = 0;
int N;
int ans = 0;
void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int s, e;
		cin >> s >> e;
		for (int j = s; j <= e; j++)
		{
			DAT[j] += 1;
		}
		endV = max(endV, e);
	}
}

void solve()
{
	for (int i = 0; i <= endV; i++)
	{
		int w = 0;
		int h = 0;
		while (DAT[i])
		{
			w++;
			h = max(DAT[i], h);
			i++;
		}
		ans += w * h;
	}
}
int main()
{
	input();
	solve();
	cout << ans;
	return 0;
}