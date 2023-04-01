#include <bits/stdc++.h>
using namespace std;
int a[30][30],ans[600],n,m=1;
void danji(int x,int y,int m)
{
    if(a[x][y])
    {
        ans[m]++;
        a[x][y]=0;
        danji(x-1,y,m);
        danji(x+1,y,m);
        danji(x,y-1,m);
        danji(x,y+1,m);
    }
}
int main(){
   //freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) scanf("%1d",&a[i+1][j+1]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(a[i][j])
            {
                danji(i,j,m);
                m++;
            }
    printf("%d\n",m-1);
    sort(ans+1,ans+m);
    for(int i=1;i<m;i++) printf("%d\n",ans[i]);
    return 0;
}