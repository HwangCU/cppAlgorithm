//DAT2개문제
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int apt[1001][1001];
int black[1001][1001];
int ay, ax;
int by, bx;
int bucket[100001];
int blackbucket[100001];
int maxcount;
int blackman;
int whiteman;

void input() {
	cin >> ay >> ax;
	for (int i = 0; i < ay; i++)
	{
		for (int j = 0; j < ax; j++)
		{
			cin >> apt[i][j];
		}
	}
	cin >> by >> bx;
	for (int i = 0; i < by; i++)
	{
		for (int j = 0; j < bx; j++)
		{
			cin >> black[i][j];
		}
	}
}

void process() {
	for (int i = 0; i < ay; i++)
	{
		for (int j = 0; j < ax; j++)
		{
			bucket[apt[i][j]]++;
		}
	}

	for (int i = 0; i < by; i++)
	{
		for (int j = 0; j < bx; j++)
		{
			blackbucket[black[i][j]]=1;
		}
	}
}

int main()
{

	//freopen("input.txt", "r", stdin);
	input();
	maxcount = ay * ax;
	process();
	int flag = false;
	
	int count = 0;

	for (int i = 0; i < ay; i++)
	{
		for (int j = 0; j < ax; j++)
		{
			if (blackbucket[apt[i][j]] == 1) {
				blackman++;
			}
		}
	}

	cout << blackman << '\n';
	cout << ay*ax- blackman;

}