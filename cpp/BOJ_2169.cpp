#include <bits/stdc++.h>
using namespace std;

int n,m,a[1010][1010],ans[1010][1010],tmp[1010][2];

int main(){
  //  freopen("input.txt","r",stdin);

    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);
    for(int i=2;i<1010;i++)
        for(int j=0;j<1010;j++) ans[i][j]=INT_MIN;
    for(int i=0;i<1010;i++) tmp[i][0]=tmp[i][1]=INT_MIN;
    for(int i=1;i<=m;i++) ans[1][i]=ans[1][i-1]+a[1][i];

    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            tmp[j][0]=max(ans[i-1][j],tmp[j-1][0])+a[i][j];
        for(int j=m;j;j--)
            tmp[j][1]=max(ans[i-1][j],tmp[j+1][1])+a[i][j];
        for(int j=1;j<=m;j++) ans[i][j]=max(tmp[j][0],tmp[j][1]);
    }

    printf("%d",ans[n][m]);

    return 0;
}
