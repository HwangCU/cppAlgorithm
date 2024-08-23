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
int resultcount;
int root;

void dfs(int lev) {
    bool isLeaf = true; // 리프 노드인지 확인

    for (int k : v[lev]) {
        if (k == erase) {
            continue;
        }
        isLeaf = false; // 자식이 하나라도 있으면 리프 노드가 아님
        dfs(k);
    }

    if (isLeaf) { // 모든 자식이 erase 또는 없는 경우 리프 노드로 간주
        resultcount++;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    cin >> N;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        if (temp == -1) {
            root = i; // 루트 노드를 저장
            continue;
        }
        v[temp].push_back(i);
    }
    cin >> erase;

    if (erase == root) { // 루트 노드를 지우면 전체 트리가 삭제됨
        cout << "0";
        return 0;
    }

    dfs(root);

    cout << resultcount;

    return 0;
}
