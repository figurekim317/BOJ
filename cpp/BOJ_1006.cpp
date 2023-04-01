#include <bits/stdc++.h>
using namespace std;

int n,m,a[2][10010],ans[100010][3];

int amel(int p)
{
    if(p&1&&a[0][1]+a[0][n]>m) return INT_MAX;
    if(p&2&&a[1][1]+a[1][n]>m) return INT_MAX;
    ans[1][0]=p&2?123456:1;
    ans[1][1]=p&1?123456:1;
    ans[1][2]=1+(p||a[0][1]+a[1][1]>m);
    ans[0][2]=p?123456:0;
    for(int i=2;i<=n;i++)
    {
        ans[i][0]=ans[i][1]=ans[i-1][2]+1;
        if(a[0][i-1]+a[0][i]<=m) ans[i][0]=min(ans[i][0],ans[i-1][1]+1);
        if(a[1][i-1]+a[1][i]<=m) ans[i][1]=min(ans[i][1],ans[i-1][0]+1);
        ans[i][2]=min(ans[i][0],ans[i][1])+1;
        if(a[0][i]+a[1][i]<=m) ans[i][2]=min(ans[i][2],ans[i-1][2]+1);
        if(a[0][i-1]+a[0][i]<=m&&a[1][i-1]+a[1][i]<=m) ans[i][2]=min(ans[i][2],ans[i-2][2]+2);
    }
    if(!p) return ans[n][2];
    if(p==1) return ans[n][1];
    if(p==2) return ans[n][0];
    return ans[n-1][2];
}

int main(){
    //freopen("input.txt","r",stdin);
    int te;
    scanf("%d",&te);
    for(int ii=0;ii<te;ii++)
    {
        scanf("%d %d",&n,&m);
        for(int i=0;i<2;i++)
            for(int j=1;j<=n;j++) scanf("%d",a[i]+j);
        if(n==1) printf("%d\n",1+(a[0][1]+a[1][1]>m));
        else printf("%d\n",min(min(amel(0),amel(1)),min(amel(2),amel(3))));
    }
    return 0;
}
