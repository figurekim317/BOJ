#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
#define N 1010
#define M 0
#define MOD 15746

int n,m,a[N][N],ans[N][N][2],vis[N][N][2];
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};

bool chk(int p,int q,int r)
{
    return 0<p&&p<=n&&0<q&&q<=m&&!vis[p][q][r];
}

int main(){
  //  freopen("input.txt","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) scanf("%1d",a[i]+j);
    memset(ans,1,sizeof(ans));
    queue<piii> bfs;
    bfs.push({{1,1},0}); vis[1][1][0]=1; ans[1][1][0]=ans[1][1][1]=0;
    while(!bfs.empty())
    {
        auto p=bfs.front(); bfs.pop();
        for(int i=0;i<4;i++)
            for(int j=p.second;j<2;j++)
            {
                int x=p.first.first+dx[i],y=p.first.second+dy[i];
                if(chk(x,y,j)&&((!p.second&&a[x][y]==j)||(p.second&&!a[x][y])))
                {
                    vis[x][y][j]=1; bfs.push({{x,y},j});
                    ans[x][y][j]=min(ans[x][y][j],ans[p.first.first][p.first.second][p.second]+1);
                }
            }
    }
    printf("%d",min(ans[n][m][0],ans[n][m][1])&1<<24?-1:min(ans[n][m][0],ans[n][m][1])+1);
    return 0;
}
