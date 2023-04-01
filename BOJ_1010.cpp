#include <bits/stdc++.h>
using namespace std;

int n,m,c[40][40]={1};

int main(){
    //freopen("input.txt","r",stdin);

    for(int i=0;i<=30;i++,c[i][0]=1)
        for(int j=1;j<=i;j++)
            c[i][j]=c[i-1][j-1]+c[i-1][j];

    int te;
    scanf("%d",&te);
    for(int ii=0;ii<te;ii++)
    {
        scanf("%d %d",&n,&m);
        printf("%d\n",c[max(n,m)][min(n,m)]);
    }
    return 0;
}
