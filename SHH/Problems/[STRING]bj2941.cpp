#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string croatia[8] = {
	"c=",
	"c-",
	"dz=",
	"d-",
	"lj",
	"nj",
	"s=",
	"z=",
};

int main() {
	//freopen("sample_input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string arr;
	cin >> arr;

	int result = 0;

	for (int i = 0; i < 8; i++) {
		size_t pos = arr.find(croatia[i]);
		while (pos != string::npos) {
			arr.replace(pos, croatia[i].length(), "@");
			pos = arr.find(croatia[i]);  
		}
	}

	cout << arr.length() << '\n';

	return 0;

}