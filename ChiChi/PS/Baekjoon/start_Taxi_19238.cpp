#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M, K; // N: 격자 크기, M: 승객 수, K: 연료
int map[21][21]; // 격자 지도
int dx[4] = { -1, 1, 0, 0 }; // 상하좌우 이동
int dy[4] = { 0, 0, -1, 1 };
struct Passenger {
    int sy, sx, ey, ex, distToTaxi, distToDest;
};
vector<Passenger> passengers;
struct Point {
    int y, x;
};
Point taxi;

// BFS 함수: 특정 출발점에서 목적지까지 최단 거리 계산
int bfs(Point start, Point end) {
    queue<Point> q;
    int visited[21][21] = { 0 };
    q.push(start);
    visited[start.y][start.x] = 1;

    while (!q.empty()) {
        Point curr = q.front();
        q.pop();
        if (curr.y == end.y && curr.x == end.x) {
            return visited[curr.y][curr.x] - 1; // 이동한 거리 반환
        }

        for (int i = 0; i < 4; i++) {
            int ny = curr.y + dy[i];
            int nx = curr.x + dx[i];
            if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
            if (map[ny][nx] == 1 || visited[ny][nx]) continue;

            visited[ny][nx] = visited[curr.y][curr.x] + 1;
            q.push({ ny, nx });
        }
    }
    return -1; // 도달할 수 없을 때
}

// 승객 태우기 및 목적지까지 이동
int solve() {
    for (int i = 0; i < M; i++) {
        // 1. 택시에서 가장 가까운 승객 찾기
        for (int j = 0; j < passengers.size(); j++) {
            passengers[j].distToTaxi = bfs({taxi.y, taxi.x}, {passengers[j].sy, passengers[j].sx});
            if (passengers[j].distToTaxi == -1) return -1; // 승객에게 도달 불가
        }

        // 거리, 행, 열 순으로 승객 정렬
        sort(passengers.begin(), passengers.end(), [](Passenger& a, Passenger& b) {
            if (a.distToTaxi == b.distToTaxi) {
                if (a.sy == b.sy) return a.sx < b.sx;
                return a.sy < b.sy;
            }
            return a.distToTaxi < b.distToTaxi;
        });

        // 2. 가장 가까운 승객까지 이동
        Passenger target = passengers[0];
        if (K < target.distToTaxi) return -1; // 연료 부족
        K -= target.distToTaxi;
        taxi = { target.sy, target.sx };

        // 3. 목적지까지 이동
        target.distToDest = bfs({ target.sy, target.sx }, { target.ey, target.ex });
        if (target.distToDest == -1 || K < target.distToDest) return -1; // 도달 불가 또는 연료 부족
        K -= target.distToDest;
        K += target.distToDest * 2; // 연료 충전
        taxi = { target.ey, target.ex }; // 택시 위치 갱신

        // 4. 승객 제거
        passengers.erase(passengers.begin());
    }
    return K; // 남은 연료량 반환
}

int main() {
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    int ty, tx;
    cin >> ty >> tx;
    taxi = { ty - 1, tx - 1 };

    for (int i = 0; i < M; i++) {
        Passenger p;
        cin >> p.sy >> p.sx >> p.ey >> p.ex;
        p.sy--; p.sx--; p.ey--; p.ex--;
        passengers.push_back(p);
    }

    int result = solve();
    cout << result << endl;

    return 0;
}
