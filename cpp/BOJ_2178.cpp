#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 110

int n,m,a[N][N];
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};

int main(){
  //  freopen("input.txt","r",stdin);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) scanf("%1d",a[i]+j);
    queue<pii> bfs;
    bfs.push({1,1}); a[1][1]=2;
    while(!bfs.empty())
    {
        auto p=bfs.front(); bfs.pop();
        for(int i=0;i<4;i++)
            if(a[p.first+dx[i]][p.second+dy[i]]==1)
                a[p.first+dx[i]][p.second+dy[i]]=a[p.first][p.second]+1,
                bfs.push({p.first+dx[i],p.second+dy[i]});
    }
    printf("%d",a[n][m]-1);
    return 0;
}
