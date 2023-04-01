#include <bits/stdc++.h>
using namespace std;

int n,in[100010],post[100010];

void amel(int st,int ed,int lf,int rg)
{
    printf("%d ",post[rg]);
    if(st==ed) return;

    int x=st;
    while(in[x]!=post[rg]) x++;

    if(x>st) amel(st,x-1,lf,lf+x-1-st);
    if(x<ed) amel(x+1,ed,lf+x-st,rg-1);
}

int main(){
 //   freopen("input.txt","r",stdin);

    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",in+i);
    for(int i=1;i<=n;i++) scanf("%d",post+i);

    amel(1,n,1,n);

    return 0;
}
