#include<iostream>
using namespace std;

int A, B, V;

int main() {
	cin >> A >> B >> V;
	int ans = 1;
	// 5 1 6
	int target = V - A; // 1
	int mod = A - B; // 4

	if (target % mod != 0) {
		// 1 + 1 + 1
		ans += target / mod + 1;
	}
	else {
		ans += target / mod;
	}
	cout << ans;
}