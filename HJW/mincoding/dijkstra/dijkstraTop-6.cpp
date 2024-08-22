/*
무서운 시어머니
1. 시작점 코스트
2. -1은 걸러야 함
3. maxVal 꺼내고 싶어도 21e8일 경우 걸러야 함.
*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// 맵의 정보를 저장하는 구조체
struct Node
{
    int y;
    int x;
    int cost;
};

// 비용을 오름차순으로 정렬
struct cmp
{
    bool operator()(Node a, Node b)
    {
        return a.cost > b.cost;
    }
};

int Y, X, N;
int MAP[1000][1000];
int dist[1000][10000];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int max_val = 0;

// map의 dist 값을 21e8로 채움
void init()
{
    fill(&dist[0][0], &dist[0][0] + 1000 * 1000, 21e8);
}

void dijkstra(Node st)
{
    //priority_queue로 cost 내림차순 정렬
	priority_queue<Node, vector<Node>, cmp> pq;
    pq.push(st);
    // 시작지점 cost 지정
    dist[st.y][st.x] = st.cost;

    while(!pq.empty()) // bfs
    {
        Node now = pq.top();
        pq.pop();

        if(dist[now.y][now.x] < now.cost) continue;

        for (int i = 0; i < 4; i++) // 모든 방향 탐색
        {
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];

            // 맵 밖을 만났을 때
            if(ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
            // 벽을 만났을 때
            if(MAP[ny][nx] == -1) continue;

            int next_cost = now.cost + MAP[ny][nx];  // 다음 지점은 현재 cost + 가는 데 비용

            // 비용이 더 작으면 진행하지 않음
            if(dist[ny][nx] <= next_cost) continue;
            dist[ny][nx] = next_cost;

            pq.push({ny, nx, next_cost });
        }
        
    }

}

int main()
{
    cin >> Y >> X >> N;

    init();
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> MAP[i][j];    
        }
        
    }

    dijkstra({Y, X, MAP[Y][X]});

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(dist[i][j] == 21e8) continue;
            if(dist[i][j] > max_val) max_val = dist[i][j];
        }
        
    }
    
    cout << max_val;
}