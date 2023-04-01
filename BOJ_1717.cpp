#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 1000010
#define MOD 15746

int n,m,k,par[N];

int pfind(int p)
{
    if(par[p]==p) return p;
    return par[p]=pfind(par[p]);
}

void uni(int p,int q)
{
    p=pfind(p); q=pfind(q);
    if(p==q) return;
    par[q]=p;
}

int main(){
   // freopen("input.txt","r",stdin);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) par[i]=i;
    while(~scanf("%d %d %d",&n,&m,&k)) n?(void)printf(pfind(m)==pfind(k)?"YES\n":"NO\n"):uni(m,k);
    return 0;
}
