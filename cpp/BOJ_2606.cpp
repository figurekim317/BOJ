#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 110
#define MOD 15746

int n,m,par[N],siz[N];

int pfind(int p)
{
    if(par[p]==p) return p;
    return par[p]=pfind(par[p]);
}

void uni(int p,int q)
{
    p=pfind(p),q=pfind(q);
    if(p!=q) par[q]=p,siz[p]+=siz[q];
}

int main(){
   // freopen("input.txt","r",stdin);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) par[i]=i,siz[i]=1;
    while(~scanf("%d %d",&n,&m)) uni(n,m);
    printf("%d",siz[pfind(1)]-1);
    return 0;
}
