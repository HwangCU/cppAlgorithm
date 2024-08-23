#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
int N;

vector<int> v[51];
int erase;
int dat[51];
int resultcount;

void dfs(int lev) {

	bool isleaf = true;
	for (int k : v[lev])//erase에 연결된거 다지워
	{
		if (k == erase) {//지울노드는 가지않는다.
			continue;
		}
        isleaf=false;
		dfs(k);
	}
    if(isleaf){
        resultcount++;
    }
}

int main() {
	//freopen("input.txt", "r", stdin);
	cin >> N;
    int root =0;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		if (temp ==-1) {
            root=i;
			continue;
		}
		if (temp==-1) {//부모가없다면 루트가주어진다
			resultcount++;
			continue;
		}
		v[temp].push_back(i);
	}
	cin >> erase;

	if (erase == root) {
		cout << "0";
		return 0;
	}

	dfs(root);


	cout << resultcount;
	


}