// BFS 풀이

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> graph(101);
vector<bool> visited(4951, false);


void bfs(int start) { // 1 2
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i = 0; i < graph[now].size(); i++) {
            int next_node = graph[now][i];
            if (!visited[next_node]) {
                q.push(next_node);
                visited[next_node] = true;
            }
        }
    }

}


int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int result = 0;
        int n, m; //사람수, 관계수
        cin >> n >> m;

        //이전 테케 데이터 초기화

        for (int i = 0; i <= n; i++) {
            graph[i].clear();
            visited[i] = false;
        }


        for (int i = 0; i < m; i++) {
            int n1, n2;
            cin >> n1 >> n2;
            graph[n1].push_back(n2);
            graph[n2].push_back(n1);
        }

        //for (int i = 0; i < graph.size(); i++) {
        //    for (int j = 0; j < graph[i].size(); j++) {
        //        cout << graph[i][j] << " ";
        //    }
        //    cout << "\n";
        //}

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                bfs(i);
                result++;
            }
        }



        
        
        cout << "#" << t + 1 << " " << result << '\n';
    }
    return 0;
}

// DFS 풀이
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph(101);
vector<bool> visited(4951, false);

void dfs(int start) {
    visited[start] = true;
    for (int i = 0; i < graph[start].size(); i++) {
        int next = graph[start][i];
        if (!visited[next]) {
            dfs(next);
        }
    }
}


int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int result = 0;
        int n, m; //사람수, 관계수
        cin >> n >> m;

        //이전 테케 데이터 초기화

        for (int i = 0; i <= n; i++) {
            graph[i].clear();
            visited[i] = false;
        }


        for (int i = 0; i < m; i++) {
            int n1, n2;
            cin >> n1 >> n2;
            graph[n1].push_back(n2);
            graph[n2].push_back(n1);
        }

        //for (int i = 0; i < graph.size(); i++) {
        //    for (int j = 0; j < graph[i].size(); j++) {
        //        cout << graph[i][j] << " ";
        //    }
        //    cout << "\n";
        //}

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                dfs(i);
                result++;
            }
        }



        
        
        cout << "#" << t + 1 << " " << result << '\n';
    }
    return 0;
}

// Union-Find 풀이
#include <iostream>
#include <vector>
using namespace std;

vector<int> p(101);

int find_p(int x) {
    if (x == p[x]) {
        return x;
    }
    else {
        return p[x] = find_p(p[x]);
    }
}

int main() {
    int T;
    cin >> T;
    /*
    6 5
    1 2
    2 5
    5 1
    3 4
    4 6
    */
    for (int t = 0; t < T; t++) {
        int result = 0;
        int n, m; //사람수, 관계수
        cin >> n >> m;

        for (int i = 1; i <= n; i++) {
            p[i] = i;
        }

        for (int i = 0; i < m; i++) {
            int n1, n2;
            cin >> n1 >> n2;
            p[find_p(n1)] = find_p(n2);
            //p[1] = 2
            //..
            //[5] = 
        }

        for (int i = 1; i <= n; i++) {
            if (i == find_p(i)) {
                result++;
            }
        }

        cout << "#" << t + 1 << " " << result << '\n';
    }
    return 0;
}