#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int T, N, M, K, A, B;
int ans;
struct Customer
{
	int receptionNum;
	int repareNum;
	int arrTime;
};
struct Room
{
	int timeToTake;
	int timeToFinish;
	int curCustomerNumber;
};
Customer customer[1001];
Room reception[10];
Room repaire[10];
void init()
{
	ans = 0;
	memset(reception, 0, sizeof(reception));
	memset(repaire, 0, sizeof(repaire));
	for (int i = 1; i <= 9; i++)
	{
		reception[i].timeToFinish = -1;
		repaire[i].timeToFinish = -1;
	}
}
void input()
{
	cin >> N >> M >> K >> A >> B;
	for (int i = 1; i <= N; i++)
		cin >> reception[i].timeToTake;
	for (int i = 1; i <= M; i++)
		cin >> repaire[i].timeToTake;
	for (int i = 1; i <= K; i++)
		cin >> customer[i].arrTime;
}
void solve()
{
	queue<int> q1;
	queue<int> q2;
	int time = 0;
	int outCnt = 0;
	while (1)
	{

			for (int i = 1; i <= K; i++)
				if (customer[i].arrTime == time)
					q1.push(i);

			for (int i = 1; i <= N; i++)
			{
				if (reception[i].timeToFinish == time)
				{
					reception[i].timeToFinish = -1;
					q2.push(reception[i].curCustomerNumber);
				}
			}

			for (int i = 1; i <= N; i++)
			{
				if (q1.empty())
					break;
				if (reception[i].timeToFinish == -1)
				{
					reception[i].timeToFinish = reception[i].timeToTake + time;
					reception[i].curCustomerNumber = q1.front
					();
					customer[q1.front()].receptionNum = i;
					q1.pop();
				}
			}

			for (int i = 1; i <= M; i++)
			{
				if (repaire[i].timeToFinish == time)
				{
					repaire[i].timeToFinish = -1;
					outCnt++;
				}
			}

			for (int i = 1; i <= M; i++)
			{
				if (q2.empty())
					break;
				if (repaire[i].timeToFinish == -1)
				{
					repaire[i].timeToFinish = repaire[i].timeToTake + time;
					repaire[i].curCustomerNumber = q2.front();
					customer[q2.front()].repareNum = i;
					q2.pop();
				}
			}
			if (outCnt == K)
				break;
		time++;
	}
	for (int i = 1; i <= K; i++)
		if (customer[i].receptionNum == A && customer[i].repareNum == B)
			ans += i;
	if (ans == 0)
		ans = -1;
}
int main()
{
	// freopen("sample_input.txt", "r", stdin);
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		init();
		input();
		solve();
		cout << "#" << tc << " " << ans << "\n";
	}
	return 0;
}