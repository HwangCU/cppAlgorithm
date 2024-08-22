#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int N, M;
int map[31][31];
int fuel[31][31];
int dy[] = { -1,1,0,0 }; int dx[] = { 0,0,-1,1 };

struct Tunnel
{
    // 시작점 끝점 코스트
    int ay; int ax; int by; int bx; int c;
};

struct Point
{
    int y; int x; int cost; int visited[31] = { 0 };
};

Tunnel tunnel[31];
struct cmp
{
    bool operator()(Point a, Point b)
    {
        return a.cost > b.cost;
    }
};

void init()
{
    memset(map, 0, sizeof(map));
    memset(tunnel, 0, sizeof(tunnel));
}
// input
void input()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < M; i++)
    {
        int ay, ax, by, bx, c;
        cin >> ay >> ax >> by >> bx >> c;
        tunnel[i] = { ay,ax,by,bx,c };
    }
}

int calcFuel(Point now, Point next)
{
    int nowHeight = map[now.y][now.x];
    int nextHeight = map[next.y][next.x];
    int Height = nextHeight - nowHeight;

    if (Height < 0) return 0;
    else if (Height > 0) return Height * 2;
    else if (Height == 0) return 1;
}

void dijkstra(int sy, int sx)
{
    priority_queue<Point, vector<Point>, cmp> pq;
    pq.push({ sy,sx,0 });
    fuel[sy][sx] = 0;

    while (!pq.empty())
    {
        Point now = pq.top();
        pq.pop();

        //터널 체크
        for (int i = 0; i < M; i++)
        {
            if (now.visited[i]) continue;
            Point next = now;
            if (tunnel[i].ay == now.y && tunnel[i].ax == now.x)
            {
                next.y = tunnel[i].by;
                next.x = tunnel[i].bx;
                next.cost = tunnel[i].c + now.cost;
                next.visited[i] = 1;
                if (fuel[next.y][next.x] < next.cost) continue;
                fuel[next.y][next.x] = next.cost;
                pq.push(next);
            }
            if (tunnel[i].by == now.y && tunnel[i].bx == now.x)
            {
                next.y = tunnel[i].ay;
                next.x = tunnel[i].ax;
                next.cost = tunnel[i].c + now.cost;
                next.visited[i] = 1;
                if (fuel[next.y][next.x] < next.cost) continue;

                fuel[next.y][next.x] = next.cost;
                pq.push(next);
            }
        }
        // 방향 배열로 진행
        for (int i = 0; i < 4; i++)
        {
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];

            if (ny <= 0 || ny > N || nx <= 0 || nx > N) continue;
            if (now.cost > fuel[ny][nx]) continue;

            int add = calcFuel(now, { ny,nx });
            int nextFuel = now.cost + add;

            if (fuel[ny][nx] > nextFuel)
            {
                Point next = now;
                next.y = ny;
                next.x = nx;
                next.cost = nextFuel;
                fuel[ny][nx] = nextFuel;
                pq.push(next);
            }
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        init();
        input();
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                fuel[i][j] = 21e8;
            }
        }
        dijkstra(1, 1);
        cout << '#' << t << ' ' << fuel[N][N] << '\n';
    }
}