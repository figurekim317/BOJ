#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m,a[755][755],lf[755][755],rg[755][755],ans;

void amel(int x,int y,int dx,int dy,int (*arr)[755])
{
    for(int cnt=0;0<x&&x<=n&&0<y&&y<=m;x+=dx,y+=dy)
        a[x][y]?arr[x][y]=++cnt:cnt=0;
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) scanf("%1d",a[i]+j);
    for(int i=1;i<=n;i++) amel(i,1,-1,1,lf);
    for(int i=2;i<=m;i++) amel(n,i,-1,1,lf);
    for(int i=1;i<=n;i++) amel(i,m,-1,-1,rg);
    for(int i=1;i<m;i++) amel(n,i,-1,-1,rg);

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            for(int k=1;k<=min(lf[i][j],rg[i][j]);k++)
                if(rg[i+k-1][j-k+1]>=k&&lf[i+k-1][j+k-1]>=k) ans=max(ans,k);

    printf("%d",ans);
    return 0;
}
