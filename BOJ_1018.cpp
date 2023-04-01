#include <bits/stdc++.h>
using namespace std;

int n,m,a[60][60],ans=INT_MAX;

int amel(int x,int y,int p)
{
    int ret=0;
    for(int i=x;i<x+8;i++,p=!p)
        for(int j=y;j<y+8;j++,p=!p)
            ret+=a[i][j]!=p;
    return ret;
}

int main(){
   // freopen("input.txt","r",stdin);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            char c;
            scanf(" %c",&c);
            a[i][j]=c=='B';
        }
    for(int i=1;i<=n-7;i++)
        for(int j=1;j<=m-7;j++)
            ans=min(ans,min(amel(i,j,0),amel(i,j,1)));
    printf("%d",ans);
    return 0;
}
