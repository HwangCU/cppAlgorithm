#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct Node{
  int num;
  int cost;
};

int n, m, p; //학생수, 마을 개수, 도로 개수
vector<Node> connected_to[1000];
int dist[1000]; //final P
int to_p[1000];
int from_p[1000];
int answer = 0;

struct compare{
  bool operator()(Node a, Node b)
  {
    return a.cost > b.cost;
  }
};

void print_dist()
{
  for (int i = 0; i < n; i++)
  {
    cout << dist[i] << ' ';
  }
  cout << "\n\n";
}

void init()
{
  fill(dist, dist + n, 1e9);
}

void find_answer(int start)
{
  priority_queue<Node, vector<Node>, compare> pq;
  pq.push({start,0});
  dist[start] = 0;

  while(pq.size())
  {
    Node now = pq.top(); pq.pop();

    if(dist[now.num] < now.cost) continue;

    for (int i = 0; i < connected_to[now.num].size(); i++)
    {
      int next_idx = connected_to[now.num][i].num;
      int next_cost = now.cost + connected_to[now.num][i].cost;
      if(next_cost > dist[next_idx]) continue;
      dist[next_idx] = next_cost;
      pq.push({next_idx,next_cost});
    }
    
  }
}

int main()
{
  freopen("input.txt","r",stdin);
  cin >> n >> m >> p;
  int start, end, cost;
  for (int i = 0; i < m; i++)
  {
    cin >> start >> end >> cost;
    connected_to[start-1].push_back({end-1,cost});
  }

  for (int i = 0; i < n; i++)
  {
    init();
    find_answer(i);
    if(i == p-1)
    {
      for (int i = 0; i < n; i++)
      {
        to_p[i] += dist[i];
      }
      
    }
    else
    {
      to_p[i] += dist[p-1];
    }
  }
  
  for (int i = 0; i < n; i++)
  {
    answer = max(answer, to_p[i]);
  }
  
  cout << answer << '\n';
}