#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000
#define N 100010
#define M 3010

int n,m,a[55][55],ans,vis[55][55],h=1;
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};

bool chk(int x,int y)
{
    return 0<=x&&x<=n+1&&0<=y&&y<=m+1&&!vis[x][y]&&a[x][y]<h;
}

void dfs(int x,int y)
{
    vis[x][y]=1;
    for(int i=0;i<4;i++)
        if(chk(x+dx[i],y+dy[i])) dfs(x+dx[i],y+dy[i]);
}

int main(){
    freopen("input.txt","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) scanf("%1d",a[i]+j);
    for(;h<10;h++)
    {
        memset(vis,0,sizeof(vis));
        dfs(0,0);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++) ans+=a[i][j]<h&&!vis[i][j];
    }
    cout<<ans;
    return 0;
}