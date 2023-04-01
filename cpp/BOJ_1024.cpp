#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m;

void print(int p,int q)
{
    while(q--) printf("%d ",p),p++;
}

void amel()
{
    for(int cnt=m*(m-1)>>1;m<=100;cnt+=m++)
        if(n>=cnt&&(n-cnt)%m==0) return print((n-cnt)/m,m);
    printf("-1");
}

int main(){
   // freopen("input.txt","r",stdin);
    scanf("%d %d",&n,&m);
    amel();
    return 0;
}
