#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;



bool cp(string a, string b) {
	
	if (a.length() == b.length()) {
		return a < b;
	}
	
	return a.length() < b.length();
	
}
int main()
{
	int T;
	cin >> T;
	string arr[100];

	for (int i = 0; i < T; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr+T, cp);

	for (int i = 0; i < T; i++)
	{
		cout << arr[i] << '\n';
	}
	return 0;
}