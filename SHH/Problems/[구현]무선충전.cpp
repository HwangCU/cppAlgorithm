#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct BC {
	int y;
	int x;
	int dis;
	int pow;
};
vector<BC> BCs;
struct Point {
	int y;
	int x;
};
int M, A;
int map[11][11];
int direct[5][2] = {
	0,0,
	-1,0,
	0,1,
	1,0,
	0,-1
};
int result;
vector<int> amove;
vector<int> bmove;
void init() {
	result = 0;
	amove.clear();
	bmove.clear();
	BCs.clear();
}
int day = 0;
void input() {
	cin >> M >> A;
	for (int i = 0; i < M; i++)
	{
		int atemp;
		cin >> atemp;
		amove.push_back(atemp);
	}

	for (int i = 0; i < M; i++)
	{
		int btemp;
		cin >> btemp;
		bmove.push_back(btemp);
	}
	
	for (int i = 0; i < A; i++)
	{
		int tempy, tempx, distance, power;
		cin >> tempy >> tempx >> distance >> power;
		BCs.push_back({ tempx,tempy,distance,power });
	}
}


struct charger {
	int numb;
	int power;
};
bool compare(charger a, charger b){
	return a.power > b.power;
}
int charging(Point a, Point b) {
	vector<charger> tempa;
	vector<charger> tempb;
	int total = 0;
	for (int i = 0; i < BCs.size(); i++)
	{
		if((abs(BCs[i].y-a.y)+ abs(BCs[i].x-a.x)) <= BCs[i].dis){
			tempa.push_back({ i,BCs[i].pow });
		}

		if ((abs(BCs[i].y - b.y) + abs(BCs[i].x - b.x)) <= BCs[i].dis) {
			tempb.push_back({ i,BCs[i].pow });
		}
	}
	sort(tempa.begin(), tempa.end(), compare);
	sort(tempb.begin(), tempb.end(), compare);

	if (tempa.size() == 0 && tempb.size() == 0) {
		return 0;
	}
	else if (tempa.size() == 0) {
		return tempb[0].power;
	}
	else if (tempb.size() == 0) {
		return tempa[0].power;
	}
	else if (tempa[0].numb == tempb[0].numb) {//번호가같으면
		if (tempa.size() == 1 && tempb.size() == 1) {
			return tempa[0].power;
		}
		else if (tempa.size() == 1) {
			return tempa[0].power + tempb[1].power;
		}
		else if (tempb.size() == 1) {
			return tempa[1].power + tempb[0].power;
		}
		else {//둘다 사이즈1이아니면?
			if (tempa[1].power > tempb[1].power) {
				return tempa[1].power + tempb[0].power;
			}
			else {
				return tempa[0].power + tempb[1].power;
			}
		}
	}
	else {//번호가다르면
		return (tempa[0].power + tempb[0].power);
	}

}
void func() {
	Point man1 = { 1,1 };
	Point man2 = { 10,10 };
	result = charging(man1, man2);
	for (int i = 0; i < M; i++)
	{
		man1.y += direct[amove[i]][0];
		man1.x += direct[amove[i]][1];

		man2.y += direct[bmove[i]][0];
		man2.x += direct[bmove[i]][1];

		result += charging(man1, man2);
	}

}
int main() {
	//freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		init();
		input();
		func();
		cout << "#" << tc << " " << result << '\n';
	}

}