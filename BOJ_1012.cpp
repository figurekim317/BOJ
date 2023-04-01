#include <bits/stdc++.h>
using namespace std;

int n,m,k,a[55][55];

void dfs(int x,int y)
{
    a[x][y]=0;
    if(a[x+1][y]) dfs(x+1,y);
    if(a[x][y+1]) dfs(x,y+1);
    if(x&&a[x-1][y]) dfs(x-1,y);
    if(y&&a[x][y-1]) dfs(x,y-1);
}

int main(){
  //  freopen("input.txt","r",stdin);
    int te;
    scanf("%d",&te);
    for(int ii=0;ii<te;ii++)
    {
        scanf("%d %d %d",&n,&m,&k);
        for(int i=0,s,t;i<k;i++)
            scanf("%d %d",&s,&t),a[s][t]=1;
        int ans=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(a[i][j]) ans++,dfs(i,j);
        printf("%d\n",ans);
    }
    return 0;
}
