#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000007
#define N 310
#define M 100010

int n,m,k;
string t;
char a[N][N];
ll ans[N][N],row[N],col[N],tot;
int ddx[]={-1,-1,-1,0,0,0,1,1,1},ddy[]={-1,0,1,-1,0,1,-1,0,1};
int dx[]={-2,-2,2,2},dy[]={-2,2,-2,2};

int main()
{
 //   freopen("input.txt","r",stdin);
    cin>>n>>m>>k>>t;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) cin>>a[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) if(a[i][j]==t[0]) ans[i][j]=1;
    for(int i=1;i<t.length();i++)
    {
        tot=0;
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        for(int j=1;j<=n;j++)
            for(int k=1;k<=m;k++)
            {
                row[j]+=ans[j][k]; row[j]%=MOD;
                col[k]+=ans[j][k]; col[k]%=MOD;
                tot+=ans[j][k];
            }
        ll b[N][N]={0};
        for(int j=1;j<=n;j++)
            for(int k=1;k<=m;k++)
                if(a[j][k]==t[i])
                {
                    b[j][k]=tot;
                    for(int u=-1;u<=1;u++)
                    {
                        if(j+u>0&&j+u<=n) b[j][k]-=row[j+u];
                        if(k+u>0&&k+u<=m) b[j][k]-=col[k+u];
                    }
                    for(int u=0;u<9;u++)
                        if(j+ddx[u]>0&&j+ddx[u]<=n&&k+ddy[u]>0&&k+ddy[u]<=m)
                            b[j][k]+=ans[j+ddx[u]][k+ddy[u]];
                    for(int u=0;u<4;u++)
                        if(j+dx[u]>0&&j+dx[u]<=n&&k+dy[u]>0&&k+dy[u]<=m)
                            b[j][k]-=ans[j+dx[u]][k+dy[u]];
                    b[j][k]%=MOD;
                }
        memcpy(ans,b,sizeof(ans));
    }
    tot=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) tot+=ans[i][j];
    cout<<tot%MOD;
    return 0;
}
