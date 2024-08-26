#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    const int MAX_N = 10;
    int adj[MAX_N][MAX_N]; // 인접 행렬로 연결 정보 저장
    int cost[MAX_N][MAX_N]; // 비용 정보 저장
    bool visited[MAX_N] = { false }; // 방문 여부 확인

    // 배열 초기화
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++) {
            adj[i][j] = 0;
            cost[i][j] = 0;
        }
    }

    // 던전 간의 연결 정보 입력 받기
    for (int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        adj[A][B] = 1; // A에서 B로의 경로가 존재
        cost[A][B] = C; // 그 경로의 비용
    }

    queue<int> q;
    int reachable[MAX_N];
    int reachableCount = 0;

    // 0번 던전에서 시작
    visited[0] = true;
    q.push(0);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        // 현재 던전에서 갈 수 있는 다음 던전들 탐색
        for (int i = 0; i < N; i++) {
            if (adj[current][i] && !visited[i] && cost[current][i] <= K) {
                visited[i] = true;
                reachable[reachableCount++] = i;
                q.push(i);
            }
        }
    }

    // 오름차순으로 정렬
    sort(reachable, reachable + reachableCount);

    // 결과 출력
    for (int i = 0; i < reachableCount; i++) {
        cout << reachable[i] << " ";
    }

    return 0;
}
