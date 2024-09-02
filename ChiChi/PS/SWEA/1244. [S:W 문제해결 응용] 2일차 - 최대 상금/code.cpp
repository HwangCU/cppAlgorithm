#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int ans = 0;
int N;
int visited[6];
string num;
void init()
{
    ans = 0;
    memset(visited,0,sizeof(visited));
}
void dfs(int lev, string num)
{
    if(lev == N)
    {
        int value = stoi(num);
        ans = max(ans,value);
        return;
    }

    char temp;
    for (int i = 0; i < num.size(); i++)
    {
        if(visited[i])continue;
        visited[i] = 1;
        temp = num[i];
        num[i] = num[lev];
        num[lev] = temp;
        dfs(lev+1,num);
        visited[i] = 0;
        num[lev] = num[i];
        num[i] = temp;
    }
}
void solve()
{
    visited[0]=1;
    dfs(0,num);
}
int main()
{
    freopen("input.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    for (int t = 0; t < T; t++)
    {
        init();
        cin>>num;
        cin>>N;
        solve();
        cout<<'#'<<t+1<<' '<<ans<<'\n';
    }
}