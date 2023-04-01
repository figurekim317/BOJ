#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m,ans[60][10],v;

int amel(int x,int y)
{
    int a=max(abs(x),abs(y));
    a=a*2+1;
    if(x==a>>1) return a*a-a/2+y;
    if(-y==a>>1) return a*a-a+1-a/2+x;
    if(-x==a>>1) return a*a-(a<<1)+2-a/2-y;
    return (a-2)*(a-2)+a/2-x;
}

int main(){
   // freopen("input.txt","r",stdin);
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    for(int i=a;i<=c;i++)
        for(int j=b;j<=d;j++)
            ans[i-a][j-b]=amel(i,j),v=max(v,ans[i-a][j-b]);
    int p=1;
    while(p<=v) p*=10;
    p/=10;
    for(int i=a;i<=c;i++,puts(""))
        for(int j=b;j<=d;j++)
        {
            for(int k=ans[i-a][j-b];k<p;k*=10) printf(" ");
            printf("%d ",ans[i-a][j-b]);
        }
    return 0;
}
