



#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 55
#define MOD 1000000007

int n,m,par[N],siz[N],no[N];
list<int> party[N],tr;

int parfind(int p)
{
    if(par[p]==p) return p;
    return par[p]=parfind(par[p]);
}

void uni(int p,int q)
{
    int x=parfind(p),y=parfind(q);
    if(x==y) return;
    siz[x]+=siz[y]; par[y]=x;
}

int main(){
  //  freopen("input.txt","r",stdin);
    scanf("%d %d",&n,&m);
    int r;
    scanf("%d",&r);
    for(int i=0,s;i<r;i++) scanf("%d",&s),tr.push_back(s);
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&r);
        for(int j=0,s;j<r;j++) scanf("%d",&s),party[s].push_back(i);
    }
    for(int i=1;i<=m;i++) par[i]=i,siz[i]=1;
    for(int i=1;i<=n;i++)
    {
        int p=party[i].front();
        for(int j:party[i]) uni(p,j);
    }
    for(int i:tr)
        for(int j:party[i]) no[parfind(j)]=1;
    int ans=0;
    for(int i=1;i<=m;i++) if(par[i]==i&&!no[i]) ans+=siz[i];
    printf("%d",ans);
    return 0;
}
