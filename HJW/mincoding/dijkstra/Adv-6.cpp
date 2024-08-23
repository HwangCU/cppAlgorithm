#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct tunnel
{
    int ay;
    int ax;
    int by;
    int bx;
    int c;
};

struct Node
{
    int y;
    int x;
    int cost;
};

struct cmp
{
    bool operator()(Node a, Node b)
    {
        return a.cost > b.cost;
    }
};

int dist[30][30];
int map[30][30];
tunnel tun[30];

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

int N, M;

void init()
{
    fill(&dist[0][0], &dist[0][0] + 30 * 30, 21e8);
}

void dijkstra(Node st)
{
    priority_queue<Node, vector<Node>, cmp> pq;
    pq.push(st);
    dist[st.y][st.x] = 0;

    while(!pq.empty())
    {
        Node now = pq.top();
        pq.pop();

        if(dist[now.y][now.x] < now.cost)
        {
            continue;
        }

        for (int i = 0; i < M; i++) // 현재 노드에 있는 터널 확인
        {
            int ny, nx;
            if(tun[i].ay == now.y && tun[i].ax == now.x)
            {
                ny = tun[i].by;
                nx = tun[i].bx;
            }

            else if(tun[i].by == now.y && tun[i].bx == now.x)
            {
                ny = tun[i].ay;
                nx = tun[i].ax;
            }
            else
            {
                continue;
            }

            int nc = now.cost + tun[i].c; // 기존 코스트에서 터널 코스트를 합함

            if(dist[ny][nx] > nc)
            {
                dist[ny][nx] = nc;
                pq.push({ny, nx, nc});
            }
        }
        

        for (int i = 0; i < 4; i++) // 현재 노드에서 방향 배열만큼 이동
        {
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];
            int c;

            if(ny < 0 || ny >=N || nx < 0 || nx >= N)
            {
                continue;
            }

            // 가는 곳이 높이가 더 높으면
            if(map[now.y][now.x] < map[ny][nx])
            {
                c = dist[now.y][now.x] + (map[ny][nx] - map[now.y][now.x]) * 2;
            }
            // 가는 곳과 높이가 같다면
            if(map[now.y][now.x] == map[ny][nx])
            {
                c = dist[now.y][now.x] + 1;
            }

            // 가는 곳이 높이가 더 낮다면
            if(map[now.y][now.x] < map[ny][nx])
            {
                c = dist[now.y][now.x];
            }

            if(dist[ny][nx] > c)
            {
                Node
            }
        }
        
    }
}

int main()
{
    int T;
    cin >> T;

    for (int tc = 0; tc < T; tc++)
    {
        cin >> N >> M;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> map[i][j];
            }
            
        }

        for (int i = 0; i < M; i++)
        {
            cin >> tun[i].ay >> tun[i].ax >> tun[i].by >> tun[i].bx >> tun[i].c;
        }
        
        
    }
     
}