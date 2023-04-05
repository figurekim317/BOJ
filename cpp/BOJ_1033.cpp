#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


#define N 15
#define MOD 1000000007

int n,vis[N],work[N],par[N];
ll a[N][N],m,ans[N];
vector<int> ed[N];

void mul(int p,ll q)
{
    ans[p]*=q;
    for(int i=0;i<work[p];i++)
        if(ed[p][i]!=par[p]&&vis[ed[p][i]]) mul(ed[p][i],q);
}

int dfs(int p)
{
    for(int &ii=work[p];ii<ed[p].size();ii++)
    {
        int i=ed[p][ii];
        if(i==par[p]||vis[i]) continue;
        if(ans[p]%a[p][i]) {mul(p,a[p][i]); return a[p][i];}
        ans[i]=ans[p]/a[p][i]*a[i][p];
        int ret=dfs(i);
        if(ret!=1) mul(p,ret);
        return ret;
    }
    vis[p]=1;
    return 1;
}

void findpar(int p,int up)
{
    if(vis[p]) return;
    vis[p]=1;
    par[p]=up;
    for(int i:ed[p])
        findpar(i,p);
}

bool chk()
{
    for(int i=0;i<n;i++) if(!vis[i]) return 0;
    return 1;
}

void pnt()
{
    for(int i=0;i<n;i++) printf("%lld ",ans[i]);
    puts("");
    for(int i=0;i<n;i++) printf("%d ",vis[i]);
    puts("");
    puts("");
}

int main(){
  //  freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1,s,t;i<n;i++)
    {
        ll p,q;
        scanf("%d %d %lld %lld",&s,&t,&p,&q);
        ed[s].push_back(t); ed[t].push_back(s);
        ll tmp=__gcd(p,q);
        a[s][t]=p/tmp; a[t][s]=q/tmp;
    }
    findpar(0,0);
    ans[0]=1;
    memset(vis,0,sizeof(vis));
    for(int i=0;i!=1||!chk();i=dfs(0)) ;
    m=ans[0];
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            m=__gcd(m,__gcd(ans[i],ans[j]));
    for(int i=0;i<n;i++) printf("%lld ",ans[i]/m);
    return 0;
}
