#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define TWO 500000004

int n;
bool vis[100010];
ll me[100010],ans[100010];
list< pair<int,ll> > ed[100010];

bool dfs(int p)
{
    if(vis[p]) return 0;
    vis[p]=1;
    ll sqsum=0;
    for(auto i:ed[p])
        if(dfs(i.first))
        {
            ans[p]+=ans[i.first]; ans[p]%=MOD;
            ll tmp=i.second*(me[i.first]+1)%MOD;
            me[p]+=tmp; me[p]%=MOD;
            sqsum+=tmp*tmp%MOD; sqsum%=MOD;
        }
    ans[p]+=((((me[p]*me[p]%MOD)+MOD)-sqsum)%MOD)*TWO%MOD;
    ans[p]+=me[p]; ans[p]%=MOD;
    return 1;
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int s,t; ll w;
        scanf("%d %d %lld",&s,&t,&w);
        ed[s].push_back({t,w});
        ed[t].push_back({s,w});
    }
    dfs(1);
    printf("%lld",ans[1]);
    return 0;
}
