#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 510
#define MOD 1001
#define SOURCE 0
#define SINK 505

int n,m,vis[N],b[N],ans;
list<int> ed[N];

bool dfs(int p)
{
    if(vis[p]) return 0;
    vis[p]=1;
    for(int i:ed[p])
        if(!b[i]||dfs(b[i]))
        {b[i]=p; return 1;}
    return 0;
}

int main(){
 //   freopen("input.txt","r",stdin);
    scanf("%d %d",&n,&m);
    for(int i=0,s,t;i<m;i++)
        scanf("%d %d",&s,&t),ed[s].push_back(t);
    for(int i=1;i<=n;i++)
    {
        memset(vis,0,sizeof(vis));
        ans+=dfs(i);
    }
    printf("%d",ans);
    return 0;
}
