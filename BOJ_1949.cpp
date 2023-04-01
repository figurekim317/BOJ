#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000

int n,a[1<<14],vis[1<<14],yes[1<<14],no[1<<14];
list<int> edge[1<<14];

bool dfs(int p)
{
    if(vis[p]) return 0;
    vis[p]=1;
    int nosum=0,yessum=0;
    for(int i:edge[p])
        if(dfs(i)) no[p]+=max(no[i],yes[i]),yes[p]+=no[i];
    yes[p]+=a[p];
    return 1;
}

int main(){
   // freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    for(int i=1,s,t;i<n;i++)
        scanf("%d %d",&s,&t),edge[s].push_back(t),edge[t].push_back(s);
    dfs(1);
    printf("%d",max(yes[1],no[1]));
    return 0;
}
