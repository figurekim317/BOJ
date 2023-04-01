#include <bits/stdc++.h>
using namespace std;

int n,m;

int amel(int p,int q)
{
    if(q==1) return p%10;
    int ret=amel(p,q/2);
    return q%2?ret*ret*p%10:ret*ret%10;
}

int main(){
   // freopen("input.txt","r",stdin);
    int te;
    scanf("%d",&te);
    for(int ii=0;ii<te;ii++)
    {
        scanf("%d %d",&n,&m);
        printf("%d\n",n%10?amel(n,m):10);
    }
    return 0;
}
