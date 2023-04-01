#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m,ti,d=1;

bool amel(int x,int y)
{
    for(int i=0,p=0,q=0,tmp=d;i<ti;i++,tmp/=n)
    {
        int s=1,t=1;
        while(p+tmp<=x) p+=tmp,s++;
        while(q+tmp<=y) q+=tmp,t++;
        if(n-m>>1<s&&s<=n+m>>1&&n-m>>1<t&&t<=n+m>>1) return 1;
    }
    return 0;
}

int main(){
   // freopen("input.txt","r",stdin);
    scanf("%d %d %d",&ti,&n,&m);
    for(int i=1;i<ti;i++) d*=n;
    int sx,sy,ex,ey;
    scanf("%d %d %d %d",&sx,&ex,&sy,&ey);
    for(int i=sx;i<=ex;i++,puts(""))
        for(int j=sy;j<=ey;j++)
            printf(amel(i,j)?"1":"0");
    return 0;
}
