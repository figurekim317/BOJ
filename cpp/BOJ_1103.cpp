#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000009
#define N 100010
#define M 1010

int n,m,a[55][55],vis[55][55],d[55][55];
char c;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};

bool dfs(int p,int q)
{
    d[p][q]=0;
    for(int k=0;k<4;k++)
    {
        int x=p+dx[k]*a[p][q],y=q+dy[k]*a[p][q];
        if(0>x||x>=n||0>y||y>=m||!a[x][y]) continue;
        if(vis[x][y]) return 1;
        if(!~d[x][y])
        {
            vis[x][y]=1;
            if(dfs(x,y)) return 1;
            vis[x][y]=0;
        }
        d[p][q]=max(d[p][q],d[x][y]+1);
    }
    return 0;
}

int main(){
    freopen("input.txt","r",stdin);
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            scanf(" %c",&c);
            if(c!='H') a[i][j]=c-'0';
        }
    vis[0][0]=1; memset(d,-1,sizeof(d));
    if(dfs(0,0)) printf("-1");
    else cout<<d[0][0]+1;
    return 0;
}
