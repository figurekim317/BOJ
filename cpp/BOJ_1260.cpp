#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define N 1010
#define MOD 1000000007

int n,m,k,vis[N];
set<int> ed[N];

void dfs(int p)
{
    if(vis[p]) return;
    vis[p]=1; printf("%d ",p);
    for(int i:ed[p]) dfs(i);
}

int main(){
   // freopen("input.txt","r",stdin);
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0,s,t;i<m;i++)
        scanf("%d %d",&s,&t),ed[s].insert(t),ed[t].insert(s);
    dfs(k); puts("");
    memset(vis,0,sizeof(vis));
    queue<int> bfs;
    bfs.push(k); vis[k]=1;
    while(!bfs.empty())
    {
        int p=bfs.front(); bfs.pop(); printf("%d ",p);
        for(int i:ed[p]) if(!vis[i]) vis[i]=1,bfs.push(i);
    }
    return 0;
}
