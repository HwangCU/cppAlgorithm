#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N,M;
int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};
int map[101][101];
int visited[101][101];

struct Point 
{
    int y;
    int x;
};
void print(Point p)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout<<visited[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
}
void bfs(Point st)
{
    queue<Point> q;
    q.push(st);
    visited[st.y][st.x] = 1;

    while(!q.empty())
    {
        Point now = q.front();
        q.pop();
        // print(now);
        for (int i = 0; i < 4; i++)
        {
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];

            if(visited[ny][nx]) continue;
            if(ny<0||ny>=N||nx<0||nx>=M) continue;
            if(map[ny][nx] == 0) continue;
            visited[ny][nx] = visited[now.y][now.x] + 1;
            q.push({ny,nx});
        }
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    cin>>N>>M;
    for (int i = 0; i < N; i++)
    {
        string col;
        cin>>col;
        for (int j = 0; j < M; j++)
        {
            map[i][j] = col[j] - '0';
        }
    }
    bfs({0,0});
    cout<<visited[N-1][M-1];
}