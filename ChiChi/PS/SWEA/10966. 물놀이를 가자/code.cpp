#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, M;
int map[1001][1001];

int dx[] = { 1,0,-1,0 }; //우하좌상
int dy[] = { 0,1,0,-1 };

int main()
{
    ios::sync_with_stdio(false);


    cin.tie(NULL);
    int T;
    cin >> T;
    //cin.tie(0); 17,18번라인은 같다


    for (int t = 0; t < T; ++t)
    {
        int result = 0;
        cin >> N >> M;
        queue<pair<int, int>> q;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                char ch;
                cin >> ch;
                if (ch == 'W') {
                    map[i][j] = 0;
                    q.push({ i,j });
                }
                else
                    map[i][j] = -1;
            }
        }

        while (!q.empty()) {
            int cx = q.front().first;
            int cy = q.front().second;
            q.pop();

            for (int d = 0; d < 4; d++) {
                int nx = cx + dx[d];
                int ny = cy + dy[d];

                if ((nx >= 0 && nx < N) && (ny >= 0 && ny < M)) {
                    if (map[nx][ny] == -1) {
                        map[nx][ny] = map[cx][cy] + 1;
                        result += map[nx][ny];
                        q.push({ nx,ny });
                    }
                }
            }
        }
        cout << "#" << t + 1 << ' ' << result << '\n';

        // '\n' vs endl 입력버퍼, 출력버퍼를 비우냐 마냐

    }

}