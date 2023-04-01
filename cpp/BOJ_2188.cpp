#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007

int n,m,a[210],b[210],vis[210];
list<int> ed[210];

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
    for(int i=1,s;i<=n;i++)
    {
        scanf("%d",&s);
        for(int j=0,t;j<s;j++) scanf("%d",&t),ed[i].push_back(t);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        memset(vis,0,sizeof(vis));
        ans+=dfs(i);
    }
    printf("%d",ans);
    return 0;
}
