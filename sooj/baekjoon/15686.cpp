#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;
int N,M;
int town_map[50][50];
map<pair<int,int>,int*> chiken_distances;
map<pair<int,int>,int> chiken_stores;
int chiken_num;
int visited[50][50];
int city_chiken_dist = 10000000;
vector<int> v;

int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};

void cal_city_chiken_dist(){
  int tmp_city_chiken_dist = 0;
  for(pair p: chiken_distances){
    int chiken_dist = 10000000;
    for(int i: v){
      chiken_dist = min(chiken_dist, p.second[i]);
    }
    tmp_city_chiken_dist += chiken_dist;
    if(tmp_city_chiken_dist > city_chiken_dist) return;
  }
  city_chiken_dist = min(tmp_city_chiken_dist,city_chiken_dist);
}

void remove_chiken(int start){
  if(v.size() ==  M){
    cal_city_chiken_dist();
    return;
  }

  for(int i = start; i < chiken_num; i++){
    v.push_back(i);
    remove_chiken(i+1);
    v.pop_back();
  }
  return;
}

void find_chiken_distance(int y, int x){
  queue<pair<int,int>> q;
  q.push({y,x});
  visited[y][x] = 0;

  while(q.size()){
    int qy = q.front().first, qx = q.front().second;
    q.pop();
    for(int i = 0; i < 4; i++){
      int ny = qy + dy[i], nx = qx + dx[i];
      if(ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
      if(visited[ny][nx] != -1) continue;
      visited[ny][nx] = visited[qy][qx] + 1;
      q.push({ny,nx});
      if(town_map[ny][nx] == 2){
        chiken_distances[{y,x}][chiken_stores[{ny,nx}]] = visited[ny][nx];
      }
    }
  }
}


int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> N >> M;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> town_map[i][j];
      if(town_map[i][j] == 1){
        chiken_distances[{i,j}] = NULL;
      }else if(town_map[i][j] == 2){
        chiken_stores[{i,j}] = chiken_num++;
      }
    }
  }

  for(pair p: chiken_distances){
    fill(&visited[0][0], &visited[0][0] + 50 * 50, -1);
    int y = p.first.first, x = p.first.second;
    chiken_distances[p.first]= new int[chiken_num];
    find_chiken_distance(y,x); 
  }

  remove_chiken(0);
  cout << city_chiken_dist;

  for(pair p: chiken_distances){
    delete p.second;
  }
  return 0;

}