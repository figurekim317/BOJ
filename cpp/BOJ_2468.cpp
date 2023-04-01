#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 110
#define MOD 1000000

int n,m,a[N][N],ans=1,vis[N][N];
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};

bool amel()
{
    bool flag=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) if(a[i][j]) flag=1,a[i][j]--;
    return flag;
}

 void dfs(int x,int y)
 {
    if(vis[x][y]) return;
    vis[x][y]=1;
    for(int i=0;i<4;i++)
        if(a[x+dx[i]][y+dy[i]]) dfs(x+dx[i],y+dy[i]);
 }

int main(){
  //  freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) scanf("%d",a[i]+j);
    for(;amel();)
    {
        memset(vis,0,sizeof(vis));
        int cnt=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++) if(a[i][j]&&!vis[i][j]) cnt++,dfs(i,j);
        ans=max(ans,cnt);
    }
    printf("%d",ans);
    return 0;
}
